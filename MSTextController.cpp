//
// Created by dawid on 30.03.2022.
//

#include "iostream"
#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : msBoard(board), msView(view) {
    
}

void MSTextController::play() {
    int row,col;
    char action;
    std::cout << "Skladnia: (akcja) (wiersz) (kolumna)\nAkcje: \nm - odslon pole\nf - postaw/usun flage" << std::endl;
    while(!msBoard.getGameState()){
        msView.display();
        std::cin >> action >> row >> col;
        if(action == 'm') { msBoard.revealField(row-1,col-1); }
        if(action == 'f') { msBoard.toggleFlag(row-1,col-1); }
    }
    msView.display();
}