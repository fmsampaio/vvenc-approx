#ifndef APPROXME_H
#define	APRROXME_H

#include <fstream>

class ApproxInter {

    public:
        static std::fstream fp;
        static int debugEnable;

        static double MEReadBER, MEWriteBER;
        static unsigned frameOrigBufferWidth, frameOrigBufferHeight;
        static unsigned frameRecoBufferWidth, frameRecoBufferHeight;
        static unsigned xMargin, yMargin;
        static bool collectOrigBufferSize, collectRecoBufferSize, tmpOrigBool, tmpRecoBool;

        static void init();
        static void initDebug();
};

#endif