#include "GoL.h"
#include <ctime>
#include <iostream>

using namespace std;

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
            cells[i][j] = generate_alive();
    }
}

bool GoL::test_aliveNeighbor(int i, int j, int x, int y)
{
    if (i + x >= 0 && i + x < nbr_row)
    {
        if (j + y >= 0 && j + y < nbr_col)
        {
            if (!(x == 0 && y == 0) && cells[i + x][j + y])
                return true;
        }
    }
    return false;
}

int GoL::test_for_generation(int row, int col)
{
    int tmp = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (test_aliveNeighbor(row, col, x, y))
                tmp++;
        }
    }
    return tmp;
}

void GoL::updateGeneration()
{
    for (int i = 0; i < nbr_row; i++)
    {
        for (int j = 0; j < nbr_col; j++)
        {
            int tmp = test_for_generation(i, j);
            if (!cells[i][j] && tmp == 3)
                cells[i][j] = true;
            else if (cells[i][j] && (tmp == 2 || tmp == 3))
                cells[i][j] = true;
            else
                cells[i][j] = false;
        }
    }
}

void GoL::drawCells()
{
    for (int i = 0; i < nbr_row; i++)
    {
        for (int j = 0; j < nbr_col; j++)
        {
            if (cells[i][j])
                cout << "0";
            if (!cells[i][j])
                cout << "_";
        }
        cout << endl;
    }

    wave++;
    cout << "This is wave " << wave << endl;
}