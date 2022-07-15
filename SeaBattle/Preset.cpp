//
// Created by Ivan Zaitsev on 7/14/22.
//

#include "Preset.h"
#include "random"

using std::default_random_engine;


Cell **Preset::GenerateField(int number, bool exclude) {
    int presetNumber = number;
    if(exclude)
    {
        while(presetNumber == number)
            presetNumber = rand() * 1.0 / RAND_MAX * (3 + 1);
    }
    else
    {
        presetNumber = number;
    }

    Cell** result = nullptr;
    result = new Cell*[10];
    for(int i = 0; i < 10; i++)
    {
        result[i] = new Cell[10];
    }

    switch(presetNumber) {
        case 0:
            //A row
            result[0][0] = Cell(true, true, true);
            result[0][1] = Cell();
            result[0][2] = Cell(true, true, true);
            result[0][3] = Cell();
            result[0][4] = Cell();
            result[0][5] = Cell();
            result[0][6] = Cell();
            result[0][7] = Cell();
            result[0][8] = Cell();
            result[0][9] = Cell();

            //B row
            result[1][0] = Cell();
            result[1][1] = Cell();
            result[1][2] = Cell(true, true, true);
            result[1][3] = Cell();
            result[1][4] = Cell();
            result[1][5] = Cell();
            result[1][6] = Cell();
            result[1][7] = Cell();
            result[1][8] = Cell();
            result[1][9] = Cell();

            //C row
            result[2][0] = Cell();
            result[2][1] = Cell();
            result[2][2] = Cell(true, true, true);
            result[2][3] = Cell();
            result[2][4] = Cell();
            result[2][5] = Cell();
            result[2][6] = Cell();
            result[2][7] = Cell(true, true, true);
            result[2][8] = Cell();
            result[2][9] = Cell();

            //D row
            result[3][0] = Cell();
            result[3][1] = Cell();
            result[3][2] = Cell();
            result[3][3] = Cell();
            result[3][4] = Cell();
            result[3][5] = Cell(true, true, true);
            result[3][6] = Cell();
            result[3][7] = Cell(true, true, true);
            result[3][8] = Cell();
            result[3][9] = Cell(true, true, true);

            //E row
            result[4][0] = Cell();
            result[4][1] = Cell(true, true, true);
            result[4][2] = Cell();
            result[4][3] = Cell();
            result[4][4] = Cell();
            result[4][5] = Cell(true, true, true);
            result[4][6] = Cell();
            result[4][7] = Cell();
            result[4][8] = Cell();
            result[4][9] = Cell();

            //F row
            result[5][0] = Cell();
            result[5][1] = Cell(true, true, true);
            result[5][2] = Cell();
            result[5][3] = Cell();
            result[5][4] = Cell();
            result[5][5] = Cell(true, true, true);
            result[5][6] = Cell();
            result[5][7] = Cell();
            result[5][8] = Cell();
            result[5][9] = Cell();

            //G row
            result[6][0] = Cell();
            result[6][1] = Cell(true, true, true);
            result[6][2] = Cell();
            result[6][3] = Cell();
            result[6][4] = Cell();
            result[6][5] = Cell();
            result[6][6] = Cell();
            result[6][7] = Cell();
            result[6][8] = Cell(true, true, true);
            result[6][9] = Cell();

            //H row
            result[7][0] = Cell();
            result[7][1] = Cell(true, true, true);
            result[7][2] = Cell();
            result[7][3] = Cell();
            result[7][4] = Cell();
            result[7][5] = Cell();
            result[7][6] = Cell();
            result[7][7] = Cell();
            result[7][8] = Cell(true, true, true);
            result[7][9] = Cell();

            //I row
            result[8][0] = Cell();
            result[8][1] = Cell();
            result[8][2] = Cell();
            result[8][3] = Cell();
            result[8][4] = Cell();
            result[8][5] = Cell();
            result[8][6] = Cell();
            result[8][7] = Cell();
            result[8][8] = Cell(true, true, true);
            result[8][9] = Cell();

            //J row
            result[9][0] = Cell();
            result[9][1] = Cell();
            result[9][2] = Cell();
            result[9][3] = Cell();
            result[9][4] = Cell(true, true, true);
            result[9][5] = Cell(true, true, true);
            result[9][6] = Cell(true, true, true);
            result[9][7] = Cell();
            result[9][8] = Cell();
            result[9][9] = Cell();
            break;
        case 1:

            //A row
            result[0][0] = Cell();
            result[0][1] = Cell();
            result[0][2] = Cell();
            result[0][3] = Cell();
            result[0][4] = Cell();
            result[0][5] = Cell();
            result[0][6] = Cell();
            result[0][7] = Cell();
            result[0][8] = Cell();
            result[0][9] = Cell();

            //B row
            result[1][0] = Cell();
            result[1][1] = Cell();
            result[1][2] = Cell();
            result[1][3] = Cell();
            result[1][4] = Cell();
            result[1][5] = Cell(true,true,true);
            result[1][6] = Cell();
            result[1][7] = Cell();
            result[1][8] = Cell();
            result[1][9] = Cell();

            //C row
            result[2][0] = Cell();
            result[2][1] = Cell();
            result[2][2] = Cell();
            result[2][3] = Cell();
            result[2][4] = Cell();
            result[2][5] = Cell(true, true, true);
            result[2][6] = Cell();
            result[2][7] = Cell(true, true, true);
            result[2][8] = Cell();
            result[2][9] = Cell();

            //D row
            result[3][0] = Cell(true, true, true);
            result[3][1] = Cell(true, true, true);
            result[3][2] = Cell(true, true, true);
            result[3][3] = Cell();
            result[3][4] = Cell();
            result[3][5] = Cell(true, true, true);
            result[3][6] = Cell();
            result[3][7] = Cell();
            result[3][8] = Cell();
            result[3][9] = Cell(true, true, true);

            //E row
            result[4][0] = Cell();
            result[4][1] = Cell();
            result[4][2] = Cell();
            result[4][3] = Cell();
            result[4][4] = Cell();
            result[4][5] = Cell();
            result[4][6] = Cell();
            result[4][7] = Cell();
            result[4][8] = Cell();
            result[4][9] = Cell();

            //F row
            result[5][0] = Cell();
            result[5][1] = Cell(true, true, true);
            result[5][2] = Cell();
            result[5][3] = Cell();
            result[5][4] = Cell();
            result[5][5] = Cell();
            result[5][6] = Cell(true, true, true);
            result[5][7] = Cell();
            result[5][8] = Cell(true, true, true);
            result[5][9] = Cell();

            //G row
            result[6][0] = Cell();
            result[6][1] = Cell(true, true, true);
            result[6][2] = Cell();
            result[6][3] = Cell();
            result[6][4] = Cell();
            result[6][5] = Cell();
            result[6][6] = Cell(true, true, true);
            result[6][7] = Cell();
            result[6][8] = Cell(true, true, true);
            result[6][9] = Cell();

            //H row
            result[7][0] = Cell();
            result[7][1] = Cell();
            result[7][2] = Cell();
            result[7][3] = Cell(true, true, true);
            result[7][4] = Cell(true, true, true);
            result[7][5] = Cell();
            result[7][6] = Cell();
            result[7][7] = Cell();
            result[7][8] = Cell(true, true, true);
            result[7][9] = Cell();

            //I row
            result[8][0] = Cell();
            result[8][1] = Cell();
            result[8][2] = Cell();
            result[8][3] = Cell();
            result[8][4] = Cell();
            result[8][5] = Cell();
            result[8][6] = Cell();
            result[8][7] = Cell();
            result[8][8] = Cell(true, true, true);
            result[8][9] = Cell();

            //J row
            result[9][0] = Cell();
            result[9][1] = Cell();
            result[9][2] = Cell();
            result[9][3] = Cell(true, true, true);
            result[9][4] = Cell();
            result[9][5] = Cell();
            result[9][6] = Cell(true, true, true);
            result[9][7] = Cell();
            result[9][8] = Cell();
            result[9][9] = Cell();
            break;

        case 2:

            //A row
            result[0][0] = Cell();
            result[0][1] = Cell();
            result[0][2] = Cell();
            result[0][3] = Cell();
            result[0][4] = Cell();
            result[0][5] = Cell();
            result[0][6] = Cell();
            result[0][7] = Cell();
            result[0][8] = Cell();
            result[0][9] = Cell();

            //B row
            result[1][0] = Cell();
            result[1][1] = Cell();
            result[1][2] = Cell();
            result[1][3] = Cell();
            result[1][4] = Cell();
            result[1][5] = Cell();
            result[1][6] = Cell();
            result[1][7] = Cell();
            result[1][8] = Cell();
            result[1][9] = Cell();

            //C row
            result[2][0] = Cell(true, true, true);
            result[2][1] = Cell();
            result[2][2] = Cell();
            result[2][3] = Cell();
            result[2][4] = Cell(true, true, true);
            result[2][5] = Cell(true, true, true);
            result[2][6] = Cell();
            result[2][7] = Cell(true, true, true);
            result[2][8] = Cell();
            result[2][9] = Cell();

            //D row
            result[3][0] = Cell();
            result[3][1] = Cell();
            result[3][2] = Cell();
            result[3][3] = Cell();
            result[3][4] = Cell();
            result[3][5] = Cell();
            result[3][6] = Cell();
            result[3][7] = Cell(true, true, true);
            result[3][8] = Cell();
            result[3][9] = Cell();

            //E row
            result[4][0] = Cell();
            result[4][1] = Cell();
            result[4][2] = Cell();
            result[4][3] = Cell();
            result[4][4] = Cell();
            result[4][5] = Cell();
            result[4][6] = Cell();
            result[4][7] = Cell(true, true, true);
            result[4][8] = Cell();
            result[4][9] = Cell(true, true, true);

            //F row
            result[5][0] = Cell(true, true, true);
            result[5][1] = Cell();
            result[5][2] = Cell();
            result[5][3] = Cell();
            result[5][4] = Cell();
            result[5][5] = Cell();
            result[5][6] = Cell();
            result[5][7] = Cell();
            result[5][8] = Cell();
            result[5][9] = Cell();

            //G row
            result[6][0] = Cell();
            result[6][1] = Cell();
            result[6][2] = Cell();
            result[6][3] = Cell();
            result[6][4] = Cell(true, true, true);
            result[6][5] = Cell();
            result[6][6] = Cell();
            result[6][7] = Cell();
            result[6][8] = Cell();
            result[6][9] = Cell(true, true, true);

            //H row
            result[7][0] = Cell(true, true, true);
            result[7][1] = Cell(true, true, true);
            result[7][2] = Cell();
            result[7][3] = Cell();
            result[7][4] = Cell();
            result[7][5] = Cell();
            result[7][6] = Cell(true, true, true);
            result[7][7] = Cell();
            result[7][8] = Cell();
            result[7][9] = Cell(true, true, true);

            //I row
            result[8][0] = Cell();
            result[8][1] = Cell();
            result[8][2] = Cell();
            result[8][3] = Cell();
            result[8][4] = Cell();
            result[8][5] = Cell();
            result[8][6] = Cell(true, true, true);
            result[8][7] = Cell();
            result[8][8] = Cell();
            result[8][9] = Cell(true, true, true);

            //J row
            result[9][0] = Cell();
            result[9][1] = Cell();
            result[9][2] = Cell(true, true, true);
            result[9][3] = Cell(true, true, true);
            result[9][4] = Cell();
            result[9][5] = Cell();
            result[9][6] = Cell(true, true, true);
            result[9][7] = Cell();
            result[9][8] = Cell();
            result[9][9] = Cell(true, true, true);
            break;

        case 3:
            //A row
            result[0][0] = Cell();
            result[0][1] = Cell();
            result[0][2] = Cell(true, true, true);
            result[0][3] = Cell(true, true, true);
            result[0][4] = Cell();
            result[0][5] = Cell();
            result[0][6] = Cell();
            result[0][7] = Cell();
            result[0][8] = Cell(true, true, true);
            result[0][9] = Cell(true, true, true);

            //B row
            result[1][0] = Cell();
            result[1][1] = Cell();
            result[1][2] = Cell();
            result[1][3] = Cell();
            result[1][4] = Cell();
            result[1][5] = Cell(true, true, true);
            result[1][6] = Cell();
            result[1][7] = Cell();
            result[1][8] = Cell();
            result[1][9] = Cell();

            //C row
            result[2][0] = Cell();
            result[2][1] = Cell();
            result[2][2] = Cell();
            result[2][3] = Cell();
            result[2][4] = Cell();
            result[2][5] = Cell();
            result[2][6] = Cell();
            result[2][7] = Cell(true, true, true);
            result[2][8] = Cell();
            result[2][9] = Cell();

            //D row
            result[3][0] = Cell(true, true, true);
            result[3][1] = Cell();
            result[3][2] = Cell(true, true, true);
            result[3][3] = Cell();
            result[3][4] = Cell();
            result[3][5] = Cell();
            result[3][6] = Cell();
            result[3][7] = Cell();
            result[3][8] = Cell();
            result[3][9] = Cell();

            //E row
            result[4][0] = Cell(true, true, true);
            result[4][1] = Cell();
            result[4][2] = Cell();
            result[4][3] = Cell();
            result[4][4] = Cell();
            result[4][5] = Cell();
            result[4][6] = Cell();
            result[4][7] = Cell();
            result[4][8] = Cell();
            result[4][9] = Cell();

            //F row
            result[5][0] = Cell(true, true, true);
            result[5][1] = Cell();
            result[5][2] = Cell();
            result[5][3] = Cell();
            result[5][4] = Cell(true, true, true);
            result[5][5] = Cell(true, true, true);
            result[5][6] = Cell(true, true, true);
            result[5][7] = Cell(true, true, true);
            result[5][8] = Cell();
            result[5][9] = Cell();

            //G row
            result[6][0] = Cell();
            result[6][1] = Cell();
            result[6][2] = Cell();
            result[6][3] = Cell();
            result[6][4] = Cell();
            result[6][5] = Cell();
            result[6][6] = Cell();
            result[6][7] = Cell();
            result[6][8] = Cell();
            result[6][9] = Cell();

            //H row
            result[7][0] = Cell();
            result[7][1] = Cell();
            result[7][2] = Cell();
            result[7][3] = Cell();
            result[7][4] = Cell();
            result[7][5] = Cell();
            result[7][6] = Cell();
            result[7][7] = Cell();
            result[7][8] = Cell();
            result[7][9] = Cell();

            //I row
            result[8][0] = Cell(true, true, true);
            result[8][1] = Cell(true, true, true);
            result[8][2] = Cell(true, true, true);
            result[8][3] = Cell();
            result[8][4] = Cell();
            result[8][5] = Cell(true, true, true);
            result[8][6] = Cell();
            result[8][7] = Cell();
            result[8][8] = Cell();
            result[8][9] = Cell();

            //J row
            result[9][0] = Cell();
            result[9][1] = Cell();
            result[9][2] = Cell();
            result[9][3] = Cell();
            result[9][4] = Cell();
            result[9][5] = Cell(true, true, true);
            result[9][6] = Cell();
            result[9][7] = Cell();
            result[9][8] = Cell();
            result[9][9] = Cell(true, true, true);
            break;
    }

    return result;
}

void Preset::DestroyField(Cell **field) {
    for (int h = 0; h < 10; h++)
    {
        delete [] field[h];
    }
    delete [] field;
    field = 0;
}
