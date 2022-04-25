//
// Created by dawid on 21.04.22.
//

#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(sf::RenderWindow &window, MinesweeperBoard &board, MSSFMLView &view)
: mswindow(window), msboard(board),  msview(view) {
    fieldSize = msview.getFieldSize();
    fieldBorder = msview.getSpaceBetween();
}

void MSSFMLController::EventLoop(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        coordX = event.mouseButton.x;
        coordY = event.mouseButton.y;
        clickrow = coordY / fieldSize;
        clickcol = coordX / fieldSize;
        if (coordY % fieldSize >= fieldBorder && coordX % fieldSize >= fieldBorder &&
            coordX <= ((msboard.getBoardWidth() * fieldSize) + fieldBorder)) {
            if (event.mouseButton.button == sf::Mouse::Left)
                msboard.revealField(clickrow, clickcol);

            if (event.mouseButton.button == sf::Mouse::Right)
                msboard.toggleFlag(clickrow, clickcol);
        }

        if (event.mouseButton.button == sf::Mouse::Left) {
            if (coordX > 780 && coordX < 880 && coordY > 10 && coordY < 30)
                msview.changeSelectedBox(1);

            if (coordX > 780 && coordX < 880 && coordY > 35 && coordY < 55)
                msview.changeSelectedBox(2);

            if (coordX > 780 && coordX < 880 && coordY > 105 && coordY < 145) {
                if (width * fieldSize > 500)
                    width = 500 / fieldSize;
                if (height * fieldSize > 500)
                    height = 500 / fieldSize;
                msboard.setSize(width, height);
                msview.changeSelectedBox(0);
            }

            if (coordX > 780 && coordX < 880 && coordY > 150 && coordY < 190) {
                inputSizeWidth.clear();
                inputSizeHeight.clear();
                width = 0;
                height = 0;
                msboard.setGameMode(EASY);
                msview.changeSelectedBox(0);
            }

            if (coordX > 780 && coordX < 813 && coordY > 70 && coordY < 90)
                msview.selectDifficult(EASY);

            if (coordX > 814 && coordX < 847 && coordY > 70 && coordY < 90)
                msview.selectDifficult(NORMAL);

            if (coordX > 848 && coordX < 881 && coordY > 70 && coordY < 90)
                msview.selectDifficult(HARD);
        }
    }
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::S)
            msboard.setSize(width, height);
        if (event.key.code == sf::Keyboard::D)
            msboard.setGameMode(DEBUG);
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode >= 48 && event.text.unicode <= 57) {
            if (msview.getSelectedBox() == 1) {
                inputSizeWidth += event.text.unicode;
                width = width * 10 + static_cast<int>(event.text.unicode) - 48;
            }
            if (msview.getSelectedBox() == 2) {
                inputSizeHeight += event.text.unicode;
                height = height * 10 + static_cast<int>(event.text.unicode) - 48;
            }
        }
    }
}

sf::String MSSFMLController::getInputSizeWidth() {
    return inputSizeWidth;
}

sf::String MSSFMLController::getInputSizeHeight() {
    return inputSizeHeight;
}