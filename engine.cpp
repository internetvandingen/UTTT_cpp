#include "engine.h"
Engine::Engine(Player pone, Player ptwo){
    this->pone = pone;
    this->ptwo = ptwo;
}

int Engine::game(bool verbose){
    std::tuple<int, int> zet;
    for (int i=0;i<81;i++){

        zet = pone.decide_move(this->board.get_board(), this->board.get_legal());
        this->status = this->board.parse_move(std::get<0>(zet), std::get<1>(zet));

        if (verbose){
            this->board.print_board();
        }

        if (this->status != 9){
            if (verbose){
                std::cout << "Game status code: " << this->status << std::endl;
            }
            break;
        }
    }
    return(this->status);
}

int Engine::get_result(){
    return(this->status);
}
