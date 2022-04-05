//
// Created by dawid on 31.03.2022.
//
#include <iostream>
#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : msBoard(board) {}

void MSSFMLView::draw(sf::RenderWindow &win) {
    sf::Font font;
    if(!font.loadFromFile("GothicA1-Black.ttf")) { std::cout << "Blad"; }
    sf::Text numberOfMines(" ", font, 18);
    sf::RectangleShape field, border;
    sf::CircleShape mine(10);
    sf::RectangleShape flag1({20,12});
    sf::RectangleShape flag2({5,20});

    flag1.setFillColor(sf::Color::Blue);
    flag2.setFillColor(sf::Color::Blue);
    mine.setFillColor(sf::Color::Red);
    field.setSize(sf::Vector2f(20, 20));
    field.setFillColor(sf::Color::White);
    field.setOutlineColor(sf::Color{150,150,150});
    field.setOutlineThickness(1);
    border.setSize({20,20});
    border.setFillColor(sf::Color::Black);
    border.setOutlineColor(sf::Color{255,212,139});
    border.setOutlineThickness(1);

    for(int row=0; row<msBoard.getBoardHeight(); row++){
        for(int col=0; col<msBoard.getBoardWidth(); col++){
            if(msBoard.getFieldInfo(row,col) == 'x') {
                mine.setPosition(4 + col * 25, 4 + row * 25);
                win.draw(mine);
            }

            if(msBoard.getFieldInfo(row,col) == '_') {
                field.setPosition(4 + col * 25, 4 + row * 25);
                win.draw(field);
            }

            if(msBoard.getFieldInfo(row,col) == 'F'){
                flag1.setPosition(4 + col * 25, 4 + row * 25);
                flag2.setPosition(4 + col * 25, 4 + row * 25);
                field.setPosition(4 + col * 25, 4 + row * 25);
                win.draw(field);
                win.draw(flag1);
                win.draw(flag2);
            }

            if(msBoard.getFieldInfo(row,col) > '0' && msBoard.getFieldInfo(row,col) < '9'){
                numberOfMines.setString(msBoard.getFieldInfo(row,col));
                numberOfMines.setPosition(9 + col * 25, 4 + row * 25);
                border.setPosition(4 + col * 25, 4 + row * 25);
                win.draw(border);
                win.draw(numberOfMines);
            }

            if(msBoard.getFieldInfo(row,col) == ' '){
                border.setPosition(4 + col * 25, 4 + row * 25);
                win.draw(border);
            }
        }
    }
}