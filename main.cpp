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
    sf::RenderWindow window(sf::VideoMode(800,600), "Sapper");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(12, 15, DEBUG);
    MSSFMLView view(board);
    board.toggleFlag(2,2);
    board.toggleFlag(3,4);
    board.toggleFlag(5,7);
    board.revealField(8,1);
    board.revealField(1,11);
    board.revealField(3,10);
    board.revealField(4,10);
    board.revealField(5,3);
    board.revealField(1,2);
    board.revealField(1,1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        view.draw(window);
        window.display();
    }
    return 0;
}
