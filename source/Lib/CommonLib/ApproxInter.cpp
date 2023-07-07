#include "ApproxInter.h"

double ApproxInter::MEReadBER;
double ApproxInter::MEWriteBER;

unsigned ApproxInter::frameOrigBufferWidth, ApproxInter::frameOrigBufferHeight;
unsigned ApproxInter::frameRecoBufferWidth, ApproxInter::frameRecoBufferHeight;
unsigned ApproxInter::xMargin, ApproxInter::yMargin;

bool ApproxInter::collectOrigBufferSize, ApproxInter::tmpOrigBool;
bool ApproxInter::collectRecoBufferSize, ApproxInter::tmpRecoBool;


int ApproxInter::debugEnable;

std::fstream ApproxInter::fp;

void ApproxInter::init() {
    collectOrigBufferSize = true;
    collectRecoBufferSize = true;
    tmpOrigBool = false;
    tmpRecoBool = false;
}

void ApproxInter::initDebug() {
    if(debugEnable) {
        fp.open("debug.txt", std::fstream::out);
    }
}