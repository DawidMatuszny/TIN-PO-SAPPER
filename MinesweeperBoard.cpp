//
// Created by c on 17.03.2022.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int boardWidth, int boardHeight, GameMode mode){
    width = boardWidth;
    height = boardHeight;
    mineCount = (width*height)*(mode/10.0);
    state = RUNNING;
    first_action = false;
    gmode = mode;
    clear_board();
    srand(time(NULL));
    if (mode){
        for(int mines=0; mines<mineCount; mines++){
            create_mine();
        }
    }
    else {
        for (int diagonal=0; diagonal<height && diagonal<width; diagonal++){
            board[diagonal][diagonal].hasMine = true;
        }
        for (int col2=0; col2<width; col2++){
            board[0][col2].hasMine = true;
        }
        for (int row2=0; row2<height; row2++){
            if (row2 % 2 == 0) { board[row2][0].hasMine = true; }
        }
    }
}

void MinesweeperBoard::clear_board(){
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            board[row][col] = {false, false, false};
        }
    }
}

void MinesweeperBoard::debug_display() const {
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            std::cout << "[";
            if(board[row][col].hasMine) {std::cout << "M";}
            else {std::cout << ".";}
            if(board[row][col].isRevealed) {std::cout << "o";}
            else {std::cout << ".";}
            if(board[row][col].hasFlag) {std::cout << "f";}
            else {std::cout << ".";}
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}

int MinesweeperBoard::getBoardWidth() const{
    return width;
}

int MinesweeperBoard::getBoardHeight() const{
    return height;
}

int MinesweeperBoard::getMineCount() const{
    return mineCount;
}

bool MinesweeperBoard::inBoard(int row, int col) const {
    if ((row >= 0 && row < height) && (col >= 0 && col < width)) { return true; }
    else { return false; }
}

int MinesweeperBoard::countMines(int row, int col) const {
    if (!board[row][col].isRevealed) { return -1; }
    if (!inBoard(row, col)) { return -1; }
    int count=0;
    for(int row2=row-1; row2<=row+1; row2++)
    {
        for(int col2=col-1; col2<=col+1; col2++)
        {
            if (inBoard(row2,col2))
            {
                if (board[row2][col2].hasMine) { count++; }
            }
        }
    }
    return count;
}

bool MinesweeperBoard::hasFlag(int row, int col) const {
    if ((!inBoard(row,col)) || (board[row][col].isRevealed) || (!board[row][col].hasFlag)) { return false; }
    else { return true; }
}

void MinesweeperBoard::toggleFlag(int row, int col) {
    if ((!inBoard(row,col)) || (board[row][col].isRevealed) || state) {}
    else {
        if (board[row][col].hasFlag) { board[row][col].hasFlag = false; }
        else { board[row][col].hasFlag = true; }
    }
}

void MinesweeperBoard::revealField(int row, int col) {
    if ((!inBoard(row,col)) || (board[row][col].isRevealed) || (board[row][col].hasFlag) || state) {}
    else{
        if (!board[row][col].hasMine) { board[row][col].isRevealed = true; }
        else{
            if (!first_action && gmode) {
                first_action = true;
                board[row][col].hasMine = false;
                create_mine();
                board[row][col].isRevealed = true;
            }
            else {
                board[row][col].isRevealed = true;
                state = FINISHED_LOSS;
            }
        }
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const {
    if (!inBoard(row, col)) { return false; }
    if (board[row][col].isRevealed) { return true; }
    else { return false; }
}

GameState MinesweeperBoard::getGameState() const{
    return state;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const {
    if (!inBoard(row, col)) { return '#'; }
    if (!board[row][col].isRevealed){
        if (board[row][col].hasFlag) { return 'F'; }
        else { return '_'; }
    }
    else {
        if (board[row][col].hasMine) { return 'x'; }
        int mines = countMines(row,col);
        if (mines) { return char(mines+48); }
        else { return ' '; }
    }
}

void MinesweeperBoard::create_mine() {
    int row_number,col_number;
    do {
        row_number = rand() % height;
        col_number = rand() % width;
    }while(board[row_number][col_number].hasMine);
    board[row_number][col_number].hasMine = true;
}