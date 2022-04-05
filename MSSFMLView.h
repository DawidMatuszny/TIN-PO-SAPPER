//
// Created by dawid on 31.03.2022.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"

class MSSFMLView {
MinesweeperBoard &msBoard;
public:
    explicit MSSFMLView(MinesweeperBoard &board);
    void draw(sf::RenderWindow &win);
};


#endif //SAPER_MSSFMLVIEW_H
