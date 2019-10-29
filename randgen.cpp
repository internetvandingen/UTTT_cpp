#include "randgen.h"

namespace Rand{
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist3(0,2);

    void seed(int seed){
        if (seed<100000){
            throw std::invalid_argument( "seed must be >100000 (1e5)" );
        }
        gen.seed(seed);
    }

    int r3(){return dist3(gen);}

    int rint(int range){
        std::uniform_int_distribution<int> dist(0,range-1);
        return(dist(gen));
    }
}
