#pragma once

class Cell
{
private:
    int x, y;
    bool alive;

public:
    int aliveNeighbors;

    void create(int posX, int posY, bool alive = false);
    void setAlive(bool aliveValue);
    bool isAlive() { return alive; }
};