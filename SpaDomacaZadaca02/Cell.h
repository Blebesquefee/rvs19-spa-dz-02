#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Cell
{
private:
    RectangleShape rectangleShape;
    Color aliveColor = Color(0, 0, 0);
    Color deadColor = Color(255, 255, 255);

    float x, y;
    float width, height;
    bool alive;

public:
    RectangleShape cellShape() { return rectangleShape; }

    void create(float posX, float posY, float sizeX, float sizeY, bool alive = false);
    void setAlive(bool aliveValue);
    bool isAlive() { return alive; }

    int aliveNeighbors = 0;
};