#include <iostream>
#include <tuple>

#include "player.h"
#include "engine.h"

int main(){
    Rand::seed(100000);
    Player pone, ptwo;

//    std::cout << "Result: ";
    for (int i=0;i<10000;i++){
        Engine engine(pone, ptwo);
        engine.game();
//        std::cout << engine.get_result();
    }
//    std::cout << std::endl;
    return 0;
}
