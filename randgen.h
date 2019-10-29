#ifndef __RANDGEN_H_INCLUDED__
#define __RANDGEN_H_INCLUDED__

#include <iostream>
#include <random>

namespace Rand{
    extern std::default_random_engine gen;
    extern std::uniform_int_distribution<int> dist3;
    extern void seed(int seed);
    extern int r3();
    extern int rint(int range);
}



#endif
