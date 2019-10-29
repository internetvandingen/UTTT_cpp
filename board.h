#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include <iostream>
#include <string>
#include <sstream>

#include "matrix.hpp"


class Board {
public:
    void print_board();
    Matrix<int> get_board();
    Matrix<int> get_legal();
    static int ind_coords[9][9][2];

    Board();
    int get_turn();
    int parse_move(int row, int col);
private:
    // indices of three-in-a-rows in the field:
    // 0 1 2
    // 3 4 5
    // 6 7 8
    int const ind_field[8][3] = {{ 0,1,2}, // horizontals
                                {3,4,5},
                                {6,7,8},
                                {0,3,6}, // verticals
                                {1,4,7},
                                {2,5,8},
                                {0,4,8}, // diagonals
                                {2,4,6}};
    int whos_turn;
    Matrix<int> board;
    Matrix<int> legal;

    int get_winner();
    int get_winner_field(int fieldnr);
    int get_winner_arr(int arr[9]);
    int is_field_full(int fieldnr);
};

#endif
