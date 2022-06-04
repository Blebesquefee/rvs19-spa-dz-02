#include "GoL.h"
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    srand(time(0));

    GoL game;
    string tmp;

    game.generateGrid();

    while (true)
    {
        game.drawCells();

        cout << "Press (0) to continue, (1) to quit :";
        cin >> tmp;
        cout << "\n";

        if (tmp == "1")
            break;

        game.updateGeneration();
    }

    return 0;
}