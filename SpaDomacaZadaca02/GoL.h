#include "Cell.h"

class GoL
{
private:
    RenderWindow *window;

    Cell cells[40][40];

    int nbr_col = 40;
    int nbr_row = 40;

    bool generate_alive();
    bool rule0(Cell tmp);
    bool rule1(Cell tmp);
    void test_for_generation(int col, int row);

public:
    int generationUpdateInterval = 2;
    void create(RenderWindow *window);
    void generateGrid();
    void updateGeneration();
    void drawCells();
};