#include <iostream>
#include "MinesweeperBoard.h"

void intro(){
    std::cout << "Dawid, 19" << std::endl;
}

int main() {
    intro();

    MinesweeperBoard gameBoard(5,7,DEBUG);
    gameBoard.debug_display();

    return 0;
}
