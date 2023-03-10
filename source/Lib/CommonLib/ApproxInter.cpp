#include "ApproxInter.h"

double ApproxInter::MEReadBER;
double ApproxInter::MEWriteBER;

unsigned ApproxInter::frameOrigBufferWidth, ApproxInter::frameOrigBufferHeight;
//unsigned ApproxInter::xMargin, ApproxInter::yMargin;

bool ApproxInter::collectBufferSize, ApproxInter::tmpBool;


int ApproxInter::debugEnable;

std::fstream ApproxInter::fp;

void ApproxInter::init() {
    collectBufferSize = true;
    tmpBool = false;
}

void ApproxInter::initDebug() {
    if(debugEnable) {
        fp.open("debug.txt", std::fstream::out);
    }
}