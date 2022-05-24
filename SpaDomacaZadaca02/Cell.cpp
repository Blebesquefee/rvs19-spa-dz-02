#include "Cell.h"

void Cell::create(float posX, float posY, float sizeX, float sizeY, bool alive)
{
    x = posX;
    y = posY;
    height = sizeY;
    width = sizeX;

    rectangleShape = RectangleShape(Vector2f(width, height));
    rectangleShape.setPosition(x, y);
    rectangleShape.setFillColor(alive ? aliveColor : deadColor);
    rectangleShape.setOutlineThickness(2);
    rectangleShape.setOutlineColor(Color(0, 0, 0));
}

void Cell::setAlive(bool aliveValue)
{
    alive = aliveValue;
    rectangleShape.setFillColor(alive ? aliveColor : deadColor);
}