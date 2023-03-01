#ifndef APPROXME_H
#define	APRROXME_H

#include <fstream>

class ApproxInter {

    public:
        static std::fstream fp;
        static int debugEnable;

        static double MEReadBER, MEWriteBER;
        static unsigned frameBufferWidth, frameBufferHeight;
        static unsigned xMargin, yMargin;
        static bool collectBufferSize, tmpBool;

        static void init();
        static void initDebug();
};

#endif