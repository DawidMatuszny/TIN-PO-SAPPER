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
    while(!msBoard.getGameState()){
        msView.display();
        std::cin >> action >> row >> col;
        if(action == 'm') { msBoard.revealField(row,col); }
        if(action == 'f') { msBoard.toggleFlag(row,col); }
    }
    msView.display();
}