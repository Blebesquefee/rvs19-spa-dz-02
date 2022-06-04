#pragma once

class GoL
{
private:
    static const int nbr_row = 20;
    static const int nbr_col = 40;
    int wave = 0;
    bool cells[nbr_row][nbr_col];

    bool generate_alive();
    bool test_aliveNeighbor(int i, int j, int x, int y);
    int test_for_generation(int row, int col);

public:
    void generateGrid();
    void updateGeneration();
    void drawCells();
};