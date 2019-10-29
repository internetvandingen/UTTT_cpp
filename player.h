#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include <iostream>
#include <tuple>

#include "matrix.hpp"
#include "randgen.h"

class Player{
public:
    std::tuple<int, int> decide_move(Matrix<int> const board, Matrix<int> const legal);
    std::tuple<int, int> random_legal_move(Matrix<int> const board, Matrix<int> const legal);
};


#endif
