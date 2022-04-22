#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"
#include "MSSFMLController.h"

void intro(){
    std::cout << "Dawid, 19" << std::endl;
}

int main() {
    intro();
    MinesweeperBoard board(10,10, EASY);
    sf::RenderWindow window(sf::VideoMode(900,500), "Sapper");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);
    MSSFMLView view(board, 30, 5);
    MSSFMLController ctrl(window, board, view);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            ctrl.EventLoop(event);
        }
        window.clear();
        view.draw(window);
        view.drawMenu(window, ctrl.getInputSizeWidth(), ctrl.getInputSizeHeight());
        window.display();
    }
    return 0;
}