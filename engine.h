#include "board.h"
#include "player.h"

class Engine{
public:
    Engine(Player pone, Player ptwo);
    int game(bool verbose=false);
    int get_result();
private:
    Player pone, ptwo;
    int status;
    Board board;
};
