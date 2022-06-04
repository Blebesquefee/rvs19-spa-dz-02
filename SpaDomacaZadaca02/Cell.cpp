#include "Cell.h"

void Cell::create(int posX, int posY, bool alive)
{
    x = posX;
    y = posY;
    aliveNeighbors = 0;
    setAlive(alive);
}

void Cell::setAlive(bool aliveValue) { alive = aliveValue; }