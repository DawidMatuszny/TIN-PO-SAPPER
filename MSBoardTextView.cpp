//
// Created by dawid on 24.03.2022.
//
#include "iostream"
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) : msBoard(board){

}

void MSBoardTextView::display() const {
    for(int row=0; row<msBoard.getBoardHeight(); row++ ){
        for(int col=0; col<msBoard.getBoardWidth(); col++){
            std::cout << "[" << msBoard.getFieldInfo(row,col) << "]";
        }
        std::cout << std::endl;
    }
}