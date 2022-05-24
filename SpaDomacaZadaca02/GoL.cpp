#include "GoL.h"
#include <ctime>

void GoL::create(RenderWindow *window) { this->window = window; }

bool GoL::generate_alive()
{
    int tmp = rand() % 4;
    return tmp == 0;
}

void GoL::generateGrid()
{
    for (int i = 0; i < nbr_col; i++)
    {
        for (int j = 0; j < nbr_row; j++)
            cells[i][j].create(10 + 20 * i, 10 + 20 * j, 20, 20, generate_alive());
    }
}

bool GoL::rule0(Cell tmp)
{
    if (tmp.isAlive() && tmp.aliveNeighbors < 1 && tmp.aliveNeighbors > 4)
        return true;
    return false;
}

bool GoL::rule1(Cell tmp)
{
    if (!tmp.isAlive() && tmp.aliveNeighbors == 3)
        return true;
    return false;
}

void GoL::test_for_generation(int col, int row)
{
    Cell tmp = cells[col][row];
    if (rule0(tmp) || rule1(tmp))
        tmp.setAlive(true);
    else
        tmp.setAlive(false);
}

void GoL::updateGeneration()
{
    for (int i = 0; i < nbr_col; i++)
    {
        for (int j = 0; j < nbr_row; j++)
        {
            cells[i][j].aliveNeighbors = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (i + x >= 0 && i + x < nbr_col && j + y >= 0 && j + y < nbr_row && !(x == 0 && y == 0) && cells[i + x][j + y].isAlive())
                        cells[i][j].aliveNeighbors++;
                }
            }
        }
    }

    for (int i = 0; i < nbr_col; i++)
    {
        for (int j = 0; j < nbr_row; j++)
            test_for_generation(i, j);
    }
}

void GoL::drawCells()
{
    for (int i = 0; i < nbr_col; i++)
    {
        for (int j = 0; j < nbr_row; j++)
            window->draw(cells[i][j].cellShape());
    }
}