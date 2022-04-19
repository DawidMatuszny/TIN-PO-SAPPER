//
// Created by dawid on 31.03.2022.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"

class MSSFMLView {
MinesweeperBoard &msBoard;
int selectedBox;
sf::RectangleShape field, border, flag1, flag2, button, boxwidth, boxheight, difficulty;
sf::CircleShape mine;
sf::Font font;
sf::Text numberOfMines, textBox, buttonText;
public:
    explicit MSSFMLView(MinesweeperBoard &board);
    void draw(sf::RenderWindow &win);
    void drawMenu(sf::RenderWindow &win, sf::String width, sf::String height);
    void changeSelectedBox(int select);
    int getSelectedBox() const;
    void selectDifficult(GameMode mode);
};


#endif //SAPER_MSSFMLVIEW_H
