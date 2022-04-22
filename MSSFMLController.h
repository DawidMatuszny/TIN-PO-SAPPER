//
// Created by dawid on 21.04.22.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H

#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

class MSSFMLController {
sf::RenderWindow &mswindow;
MinesweeperBoard &msboard;
MSSFMLView &msview;
sf::String inputSizeWidth, inputSizeHeight;
int clickrow, clickcol, coordX, coordY, width, height, fieldSize, fieldBorder;
public:
    MSSFMLController(sf::RenderWindow &window, MinesweeperBoard &board, MSSFMLView &view);
    void EventLoop();
    sf::String getInputSizeWidth();
    sf::String getInputSizeHeight();
};


#endif //SAPER_MSSFMLCONTROLLER_H
