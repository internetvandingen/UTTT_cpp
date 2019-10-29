#include "board.h"

// define static variable
void some_function(int ind_coords[9][9][2]){
    // generate indices ind_coords[9][9][2]: [field][square][row, col]
    for (int field=0;field<9;field++){ // loop over fields
        for (int square=0;square<9;square++){ // loop over squares in field
            ind_coords[field][square][0] = field/3*3 + square/3; // row
            ind_coords[field][square][1] = field%3*3 + square%3; // col
        }
    }
}
int Board::ind_coords[9][9][2];
static int dummy = (some_function(Board::ind_coords), 0);


Board::Board(void) : board(9,9), legal(9,9) {
    this->whos_turn = 1;

    // construct board and legal
    for (int row=0;row<9;row++){
        for (int col=0;col<9;col++){
            this->board(row, col) = 0; //Rand::r3()-1; // every square is empty,
            this->legal(row, col) = 1; // every action is legal
        }
    }
};

void Board::print_board(){
    //                      -1    0    1    2
    char board_symbols[] = {'o', ' ', 'x', 'd'};
    std::stringstream ss;
    // print using stringstream
    ss << "    0  1  2   3  4  5   6  7  8";
    for (int row=0;row<9;row++){ // rows
        if (row%3==0)
            ss << std::endl << "  " << std::string(31, '-');
        ss << std::endl << std::to_string(row) << " |";
        for (int col=0;col<9;col++){ // columns
            ss << ' ' << board_symbols[this->board(row,col)+1] << ' ';
            if (col%3==2)
                ss << '|';
        }
    }
    std::cout << ss.str() << std::endl << "  " << std::string(31, '-') << std::endl;
};

Matrix<int> Board::get_board(){
    return(this->board);
}

Matrix<int> Board::get_legal(){
    return(this->legal);
}

int Board::get_turn(){
    return(this->whos_turn);
}

int Board::get_winner(){
    int macroboard[9];
    for (int i=0; i<9; i++){
        macroboard[i] = this->get_winner_field(i);
    }
    return(this->get_winner_arr(macroboard));
}

int Board::get_winner_field(int fieldnr){
    // get numbers from board and store in field (int 9)
    int field[9];
    for (int i=0; i<9; i++){
        field[i] = this->board(this->ind_coords[fieldnr][i][0], this->ind_coords[fieldnr][i][1]);
    }
    return(this->get_winner_arr(field));
}

int Board::get_winner_arr(int arr[9]){
    // returns winner of arr (int 9)
    for (int i=0; i<8; i++){ // loop through all 8 possible lines in a 3x3
        if (arr[this->ind_field[i][0]] != 0 && // must not be empty
            arr[this->ind_field[i][0]] == arr[this->ind_field[i][1]] && // compare first element in row to second
            arr[this->ind_field[i][1]] == arr[this->ind_field[i][2]]){  // compare second element in row to third
            return arr[this->ind_field[i][0]];
        }
    }
    return 0;
}

int Board::is_field_full(int fieldnr){
    int sum = 0;
    for (int i=0; i<9; i++){
        sum += (this->board(this->ind_coords[fieldnr][i][0], this->ind_coords[fieldnr][i][1]) != 0);
    }
    return (sum==9) ? 1 : 0;
}


int Board::parse_move(int row, int col){
    /*
    parses move in the game, returns status
    1:  X win
    0:  draw
    -1: O win
    9:  unfinished
    */

    // check move
    if (this->legal(row,col) == 0){
        throw std::invalid_argument("Illegal move!");
    }

    // place mark on board
    this->board(row,col) = this->whos_turn;

    // field that move is in needs to be updated
    int move_field_nr = (row/3)*3+col/3;
    int temp_winner = this->get_winner_field(move_field_nr);
    // if the field has a winner,
    if (temp_winner != 0){
        // all squares in the field are replaced with the winners mark
        for (int r=0;r<3;r++){
            for (int c=0; c<3;c++){
                this->board(row/3*3+r, col/3*3+c) = temp_winner;
            }
        }
        // check if the game is over
        int winner = this->get_winner();
        if (winner){
            return winner;
        }
    }

    // update legal moves
    int fieldnr = row%3*3+col%3;
    int total_available_moves = 0;
    // check if target field for next move is completed (X or O win, or draw)
    int replacement = (this->is_field_full(fieldnr)) ? 0 : 1;
    for (int r=0;r<9;r++){
        for (int c=0;c<9;c++){
            // check if spot is free
            if (this->board(r,c) == 0){
                if (r/3 == fieldnr/3 && c/3 == fieldnr%3){
                    this->legal(r, c) = replacement;
                    total_available_moves += replacement;
                }else{
                    this->legal(r, c) = 1-replacement;
                    total_available_moves += 1-replacement;
                }
            } else {
                this->legal(r,c) = 0;
            }
        }
    }
    // check if there is any available move, return draw if not
    if (total_available_moves==0){
        return 0;
    }

    // switch turn
    this->whos_turn *= -1;

    return 9;
}
