//
// Created by dawid on 31.03.2022.
//
#include <iostream>
#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : msBoard(board) {
    selectedBox = 0;
}

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
                mine.setPosition(5 + col * 25, 5 + row * 25);
                win.draw(mine);
            }

            if(msBoard.getFieldInfo(row,col) == '_') {
                field.setPosition(5 + col * 25, 5 + row * 25);
                win.draw(field);
            }

            if(msBoard.getFieldInfo(row,col) == 'F'){
                flag1.setPosition(5 + col * 25, 5 + row * 25);
                flag2.setPosition(5 + col * 25, 5 + row * 25);
                field.setPosition(5 + col * 25, 5 + row * 25);
                win.draw(field);
                win.draw(flag1);
                win.draw(flag2);
            }

            if(msBoard.getFieldInfo(row,col) > '0' && msBoard.getFieldInfo(row,col) < '9'){
                numberOfMines.setString(msBoard.getFieldInfo(row,col));
                numberOfMines.setPosition(10 + col * 25, 5 + row * 25);
                border.setPosition(5 + col * 25, 5 + row * 25);
                win.draw(border);
                win.draw(numberOfMines);
            }

            if(msBoard.getFieldInfo(row,col) == ' '){
                border.setPosition(5 + col * 25, 5 + row * 25);
                win.draw(border);
            }
        }
    }
}

void MSSFMLView::drawMenu(sf::RenderWindow &win, sf::String width, sf::String height) {
    sf::Font font;
    if(!font.loadFromFile("GothicA1-Black.ttf")) { std::cout << "Blad"; }
    sf::RectangleShape button ({100,40});
    sf::Text buttonText("", font, 14);
    sf::RectangleShape boxwidth ({100,20});
    sf::RectangleShape boxheight ({100,20});
    sf::RectangleShape difficulty ({33, 20});
    sf::Text textBox("", font, 15);
    textBox.setFillColor(sf::Color::Black);
    if(selectedBox == 0){
        boxwidth.setFillColor(sf::Color::White);
        boxheight.setFillColor(sf::Color::White);
    }
    if(selectedBox == 1){
        boxwidth.setFillColor(sf::Color{70,70,70});
        boxheight.setFillColor(sf::Color::White);
    }

    if(selectedBox == 2){
        boxwidth.setFillColor(sf::Color::White);
        boxheight.setFillColor(sf::Color{70,70,70});
    }
    //difficulty buttons
    difficulty.setPosition(780, 70);
    win.draw(difficulty);
    difficulty.setPosition(814, 70);
    win.draw(difficulty);
    difficulty.setPosition(848, 70);
    win.draw(difficulty);
    difficulty.setFillColor(sf::Color {70, 70, 70});
    if(msBoard.getGameMode() == EASY){
        difficulty.setPosition(780, 70);
        win.draw(difficulty);
    }
    if(msBoard.getGameMode() == NORMAL){
        difficulty.setPosition(814, 70);
        win.draw(difficulty);
    }
    if(msBoard.getGameMode() == HARD){
        difficulty.setPosition(848, 70);
        win.draw(difficulty);
    }
    difficulty.setFillColor(sf::Color::White);
    buttonText.setPosition(786, 75);
    buttonText.setString("EASY");
    buttonText.setCharacterSize(7);
    buttonText.setFillColor(sf::Color::Black);
    win.draw(buttonText);
    buttonText.setPosition(814, 75);
    buttonText.setString("NORMAL");
    win.draw(buttonText);
    buttonText.setPosition(854, 75);
    buttonText.setString("HARD");
    win.draw(buttonText);

    //input texBox
    boxwidth.setPosition(780, 10);
    win.draw(boxwidth);
    boxheight.setPosition(780, 35);
    win.draw(boxheight);

    textBox.setPosition( 785, 10);
    textBox.setString(width);
    win.draw(textBox);
    textBox.setPosition( 785, 35);
    textBox.setString(height);
    win.draw(textBox);

    //buttons
    button.setPosition(780,105);
    win.draw(button);
    buttonText.setString("START");
    buttonText.setCharacterSize(15);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(805,115);
    win.draw(buttonText);

    button.setPosition(780,150);
    win.draw(button);
    buttonText.setString("RESET");
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(805,160);
    win.draw(buttonText);

    //labels
    buttonText.setString("WIDTH");
    buttonText.setCharacterSize(9);
    buttonText.setPosition(720, 15);
    buttonText.setFillColor(sf::Color::White);
    win.draw(buttonText);

    buttonText.setString("HEIGHT");
    buttonText.setPosition(720, 39);
    win.draw(buttonText);

    buttonText.setString("DIFFICULTY");
    buttonText.setPosition(720, 75);
    win.draw(buttonText);

    if (msBoard.getGameState() == FINISHED_WIN)
    {
        buttonText.setString("EASY WIN!");
        buttonText.setOutlineThickness(4);
        buttonText.setOutlineColor(sf::Color {148,26,14});
        buttonText.setFillColor(sf::Color{254,154,26});
        buttonText.setCharacterSize(30);
        buttonText.setPosition(300, 230);
        buttonText.rotate(15);
        win.draw(buttonText);
    }
    if (msBoard.getGameState() == FINISHED_LOSS)
    {
        buttonText.setString("YOU LOST, TRY AGAIN!");
        buttonText.setOutlineThickness(4);
        buttonText.setOutlineColor(sf::Color {148,26,14});
        buttonText.setFillColor(sf::Color{254,154,26});
        buttonText.setCharacterSize(30);
        buttonText.setPosition(200, 230);
        win.draw(buttonText);
    }
}

void MSSFMLView::changeSelectedBox(int select) {
    selectedBox = select;
}

int MSSFMLView::getSelectedBox() const {
    return selectedBox;
}

void MSSFMLView::selectDifficult(GameMode mode) {
    msBoard.setGameMode(mode);
}