#include "GoL.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(0));

    RenderWindow window(sf::VideoMode(720, 720), "Conway's Game of Life", sf::Style::Titlebar | sf::Style::Close);
    GoL game;

    const int delay = 1000000 * game.generationUpdateInterval;

    game.create(&window);
    game.generateGrid();
    game.drawCells();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        usleep(delay);
        window.clear();
        game.updateGeneration();
        game.drawCells();
        window.display();
    }

    return 0;
}