//
// Created by dawid on 24.03.2022.
//

#ifndef SAPPER_MSBOARDTEXTVIEW_H
#define SAPPER_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView {
    MinesweeperBoard &msBoard;
public:
    MSBoardTextView(MinesweeperBoard &board);
    void display() const;

};


#endif //SAPPER_MSBOARDTEXTVIEW_H
