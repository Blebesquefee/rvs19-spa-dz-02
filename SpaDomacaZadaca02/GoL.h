#include "Cell.h"

class GoL
{
private:
    Cell cells[40][20];

    int nbr_row;
    int nbr_col;
    int wave;

    bool generate_alive();
    bool test_aliveNeighbor(int i, int j, int x, int y);
    bool rule0(Cell tmp);
    bool rule1(Cell tmp);
    void test_for_generation(int row, int col);

public:
    GoL();
    void generateGrid();
    void updateGeneration();
    void drawCells();
};