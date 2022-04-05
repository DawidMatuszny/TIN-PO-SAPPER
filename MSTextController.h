//
// Created by dawid on 30.03.2022.
//

#ifndef SAPPER_MSTEXTCONTROLLER_H
#define SAPPER_MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController {
    MinesweeperBoard &msBoard;
    MSBoardTextView &msView;
public:
    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
    void play();
};


#endif //SAPPER_MSTEXTCONTROLLER_H
