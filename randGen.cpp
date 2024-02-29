#include "randGen.h"

int randGen(int sRange, int eRange){
    int r = rand() % eRange + sRange;

    return r;
}