# library
set( LIB_NAME vvenc )

# create upper case name
string( TOUPPER ${LIB_NAME} LIB_NAME_UC )

# create file version.h
if(PROJECT_VERSION_RC)
  configure_file( version-rc.h.in "${CMAKE_BINARY_DIR}/${LIB_NAME}/version.h" )
else()
  configure_file( version.h.in "${CMAKE_BINARY_DIR}/${LIB_NAME}/version.h" )
endif()

# get source files
file( GLOB BASE_SRC_FILES "*.cpp"  "../CommonLib/*.cpp"  "../Utilities/*.cpp" "../DecoderLib/*.cpp" "../EncoderLib/*.cpp" )

# get include files
file( GLOB BASE_INC_FILES "*.h" "../CommonLib/*.h"  "../Utilities/*.h" "../DecoderLib/*.h" "../EncoderLib/*.h" )

if( VVENC_ENABLE_X86_SIMD )
  # get x86 source files
  file( GLOB X86_SRC_FILES "../CommonLib/x86/*.cpp" )

  # get x86 include files
  file( GLOB X86_INC_FILES "../CommonLib/x86/*.h" )

  # get avx source files
  file( GLOB AVX_SRC_FILES "../CommonLib/x86/avx/*.cpp" )

  # get avx2 source files
  file( GLOB AVX2_SRC_FILES "../CommonLib/x86/avx2/*.cpp" )

  # get sse4.1 source files
  file( GLOB SSE41_SRC_FILES "../CommonLib/x86/sse41/*.cpp" )

  # get sse4.2 source files
  file( GLOB SSE42_SRC_FILES "../CommonLib/x86/sse42/*.cpp" )

  # get all source files
  set( SRC_FILES ${BASE_SRC_FILES} ${X86_SRC_FILES} ${SSE41_SRC_FILES} ${SSE42_SRC_FILES} ${AVX_SRC_FILES} ${AVX2_SRC_FILES} )
else()
  set( SRC_FILES ${BASE_SRC_FILES} )
endif()

# get public/extern include files
file( GLOB PUBLIC_INC_FILES  "../../../include/${LIB_NAME}/*.h" )

# get all include files
file( GLOB PRIVATE_INC_FILES ${BASE_INC_FILES} ${X86_INC_FILES}  )

set( INC_FILES ${PRIVATE_INC_FILES} ${PUBLIC_INC_FILES}  )

# NATVIS files for Visual Studio
if( MSVC )
  file( GLOB NATVIS_FILES "../../VisualStudio/*.natvis" )

  # example: place header files in different folders
  source_group( "Natvis Files" FILES ${NATVIS_FILES} )
endif()

source_group( "Header Files"          FILES ${PUBLIC_INC_FILES} )
source_group( "Header Files\\private" FILES ${PRIVATE_INC_FILES} )

if( VVENC_ENABLE_X86_SIMD )
  # set needed compile definitions
  set_property( SOURCE ${SSE41_SRC_FILES} APPEND PROPERTY COMPILE_DEFINITIONS USE_SSE41 )
  set_property( SOURCE ${SSE42_SRC_FILES} APPEND PROPERTY COMPILE_DEFINITIONS USE_SSE42 )
  set_property( SOURCE ${AVX_SRC_FILES}   APPEND PROPERTY COMPILE_DEFINITIONS USE_AVX )
  set_property( SOURCE ${AVX2_SRC_FILES}  APPEND PROPERTY COMPILE_DEFINITIONS USE_AVX2 )
  # set needed compile flags
  if( MSVC )
    set_property( SOURCE ${AVX_SRC_FILES}   APPEND PROPERTY COMPILE_FLAGS "/arch:AVX" )
    set_property( SOURCE ${AVX2_SRC_FILES}  APPEND PROPERTY COMPILE_FLAGS "/arch:AVX2" )
  elseif( UNIX OR MINGW )
    set_property( SOURCE ${SSE41_SRC_FILES} APPEND PROPERTY COMPILE_FLAGS "-msse4.1" )
    set_property( SOURCE ${SSE42_SRC_FILES} APPEND PROPERTY COMPILE_FLAGS "-msse4.2" )
    set_property( SOURCE ${AVX_SRC_FILES}   APPEND PROPERTY COMPILE_FLAGS "-mavx" )
    set_property( SOURCE ${AVX2_SRC_FILES}  APPEND PROPERTY COMPILE_FLAGS "-mavx2" )
  endif()
endif()

# set resource file for MSVC compilers
if( MSVC )
  set( RESOURCE_FILE ${LIB_NAME}.rc )
endif()

add_library( ${LIB_NAME} ${SRC_FILES} ${INC_FILES} ${NATVIS_FILES} ${RESOURCE_FILE} )

target_compile_definitions( ${LIB_NAME} PRIVATE ${LIB_NAME_UC}_SOURCE )
target_compile_definitions( ${LIB_NAME} PUBLIC $<$<AND:$<PLATFORM_ID:Windows>,$<STREQUAL:$<TARGET_PROPERTY:${LIB_NAME},TYPE>,SHARED_LIBRARY>>:${LIB_NAME_UC}_DYN_LINK> )

target_compile_options( ${LIB_NAME} PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Wall -Werror -Wno-deprecated-register -Wno-unused-const-variable -Wno-unknown-attributes>
                                            $<$<CXX_COMPILER_ID:GNU>:-Wall -Werror -Wno-unused-function  -Wno-unused-variable  -Wno-sign-compare  -fdiagnostics-show-option -Wno-ignored-attributes>
                                            $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /wd4100 /wd4127 /wd4244 /wd4245 /wd4251 /wd4310 /wd4389 /wd4456 /wd4457 /wd4458 /wd4459 /wd4505 /wd4701 /wd4702 /wd4703 /wd4996 >)

if( CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7.0 )
  target_compile_options( ${LIB_NAME} PRIVATE $<$<CXX_COMPILER_ID:GNU>: -Wno-array-bounds> )
endif()

target_include_directories( ${LIB_NAME} PRIVATE           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include> $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
                                        SYSTEM INTERFACE  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include> $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}> )
target_include_directories( ${LIB_NAME} PRIVATE . .. ../DecoderLib ../EncoderLib ../CommonLib ../CommonLib/x86 )

if( VVENC_ENABLE_THIRDPARTY_JSON )
  set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVVENC_ENABLE_THIRDPARTY_JSON" )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVVENC_ENABLE_THIRDPARTY_JSON" )
  target_include_directories( ${LIB_NAME} PRIVATE ../../../thirdparty/nlohmann_json/single_include )
endif()

if( TARGET INTEL_ITT)
  target_link_libraries( ${LIB_NAME} PRIVATE INTEL_ITT Threads::Threads apputils )
else()
  target_link_libraries( ${LIB_NAME} PRIVATE Threads::Threads apputils )
endif()

# set the folder where to place the projects
set_target_properties( ${LIB_NAME} PROPERTIES FOLDER lib )
