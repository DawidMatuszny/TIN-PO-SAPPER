#include <iostream>
#include "MinesweeperBoard.h"

void intro(){
    std::cout << "Dawid, 19" << std::endl;
}

int main() {
    intro();

    MinesweeperBoard gameBoard(12,7,DEBUG);
    gameBoard.debug_display();
    std::cout<<gameBoard.getFieldInfo(1,1);

    return 0;
}
