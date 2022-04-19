#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"

void intro(){
    std::cout << "Dawid, 19" << std::endl;
}

int main() {
    intro();
    MinesweeperBoard board(10,10, EASY);
    sf::RenderWindow window(sf::VideoMode(900,500), "Sapper");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);
    MSSFMLView view(board);
    int clickrow, clickcol, coordX, coordY, width, height;
    sf::String textwidth, textheight;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                coordX = event.mouseButton.x;
                coordY = event.mouseButton.y;
                clickrow = coordY / 25;
                clickcol = coordX / 25;
                if (coordY % 25 >= 5 && coordX % 25 >= 5 && coordX <= ((board.getBoardWidth() * 25) + 5)) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                        board.revealField(clickrow, clickcol);

                    if (event.mouseButton.button == sf::Mouse::Right)
                        board.toggleFlag(clickrow, clickcol);
                }

                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (coordX > 780 && coordX < 880 && coordY > 10 && coordY < 30)
                        view.changeSelectedBox(1);

                    if (coordX > 780 && coordX < 880 && coordY > 35 && coordY < 55)
                        view.changeSelectedBox(2);

                    if (coordX > 780 && coordX < 880 && coordY > 105 && coordY < 145) {
                        board.setSize(width, height);
                        view.changeSelectedBox(0);
                    }

                    if (coordX > 780 && coordX < 880 && coordY > 150 && coordY < 190)
                    {
                        textwidth.clear();
                        textheight.clear();
                        width = 0;
                        height = 0;
                        board.setGameMode(EASY);
                        view.changeSelectedBox(0);
                    }

                    if (coordX > 780 && coordX < 813 && coordY > 70 && coordY < 90)
                        view.selectDifficult(EASY);

                    if (coordX > 814 && coordX < 847 && coordY > 70 && coordY < 90)
                        view.selectDifficult(NORMAL);

                    if (coordX > 848 && coordX < 881 && coordY > 70 && coordY < 90)
                        view.selectDifficult(HARD);
                }
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::S)
                    board.setSize(width, height);
                if (event.key.code == sf::Keyboard::D)
                    board.setGameMode(DEBUG);
            }
            if (event.type == sf::Event::TextEntered) {
                if(event.text.unicode >=48 && event.text.unicode <= 57){
                    if (view.getSelectedBox() == 1){
                        textwidth += event.text.unicode;
                        width = width * 10 + static_cast<int>(event.text.unicode) - 48;
                    }
                    if (view.getSelectedBox() == 2){
                        textheight += event.text.unicode;
                        height = height * 10 + static_cast<int>(event.text.unicode) - 48;
                    }
                }
            }
        }
        window.clear();
        view.draw(window);
        view.drawMenu(window, textwidth, textheight);
        window.display();
    }
    return 0;
}