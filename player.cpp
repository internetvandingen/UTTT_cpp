#include "player.h"


std::tuple<int, int> Player::decide_move(Matrix<int>board, Matrix<int>legal) {
    // algorithm implementation of deciding a move, use random legal move for now
    return(this->random_legal_move(board, legal));
}

std::tuple<int, int> Player::random_legal_move(Matrix<int> const board, Matrix<int> const legal) {
    // keep trying random moves until a legal one is found
    int counter = 0;
    int row = Rand::rint(9);
    int col = Rand::rint(9);
    while(legal(row, col) == 0 && counter<1000){
        row = Rand::rint(9);
        col = Rand::rint(9);
        counter++;
    }
    if (legal(row, col) == 0)
    {
        throw(std::runtime_error("No legal moves found in 1000 tries!"));
    }
    //std::cout << "number of tries: " << counter << std::endl;
    std::tuple<int, int> result = std::make_tuple(row, col);
    return(result);
}
