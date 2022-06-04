#include "GoL.h"
#include <ctime>
#include <iostream>

using namespace std;

GoL::GoL()
{
    nbr_row = 40;
    nbr_col = 20;
    wave = 0;
}

bool GoL::generate_alive()
{
    int tmp = rand() % 4;
    return tmp == 0;
}

void GoL::generateGrid()
{
    for (int i = 0; i < nbr_row; i++)
    {
        for (int j = 0; j < nbr_col; j++)
            cells[i][j].create(i, j, generate_alive());
    }
}

bool GoL::test_aliveNeighbor(int i, int j, int x, int y)
{
    if (i + x >= 0 && i + x < nbr_row)
    {
        if (j + y >= 0 && j + y < nbr_col)
        {
            if (!(x == 0 && y == 0) && cells[i + x][j + y].isAlive())
                return true;
        }
    }
    return false;
}

bool GoL::rule0(Cell tmp)
{
    if (tmp.isAlive() && (tmp.aliveNeighbors == 2 || tmp.aliveNeighbors == 3))
        return true;
    return false;
}

bool GoL::rule1(Cell tmp)
{
    if (!tmp.isAlive() && tmp.aliveNeighbors == 3)
        return true;
    return false;
}

void GoL::test_for_generation(int row, int col)
{
    Cell tmp = cells[row][col];
    if (rule0(tmp) || rule1(tmp))
        tmp.setAlive(true);
    else
        tmp.setAlive(false);
}

void GoL::updateGeneration()
{
    for (int i = 0; i < nbr_row; i++)
    {
        for (int j = 0; j < nbr_col; j++)
        {
            cells[i][j].aliveNeighbors = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (test_aliveNeighbor(i, j, x, y))
                        cells[i][j].aliveNeighbors++;
                }
            }
        }
    }

    for (int i = 0; i < nbr_row; i++)
    {
        for (int j = 0; j < nbr_col; j++)
            test_for_generation(i, j);
    }
}

void GoL::drawCells()
{
    for (int i = 0; i < nbr_row; i++)
    {
        for (int j = 0; j < nbr_col; j++)
        {
            if (cells[i][j].isAlive())
                cout << "0";
            if (cells[i][j].isAlive())
                cout << "_";
            if (j + 1 == nbr_col)
                cout << "\n";
        }
    }

    wave++;
    cout << "This is wave " << wave << endl;
}