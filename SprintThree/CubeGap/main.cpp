#include <iostream>

using namespace std;

const bool TRANSPARENT = 0;
const bool SOLID = 1;
const int DIMENSIONS = 3;

int main()
{
    bool cube[3][3][3];

    //The 1st Z row is transparent
    //Front side.
    //First row
    cube[0][0][0] = TRANSPARENT;
    cube[0][0][1] = TRANSPARENT;
    cube[0][0][2] = TRANSPARENT;

    //Second row
    cube[0][1][0] = SOLID;
    cube[0][1][1] = SOLID;
    cube[0][1][2] = SOLID;

    //Third row
    cube[0][2][0] = SOLID;
    cube[0][2][1] = SOLID;
    cube[0][2][2] = SOLID;

    //Center side.
    //First row
    cube[1][0][0] = SOLID;
    cube[1][0][1] = SOLID;
    cube[1][0][2] = SOLID;

    //Second row
    cube[1][1][0] = SOLID;
    cube[1][1][1] = SOLID;
    cube[1][1][2] = SOLID;

    //Third row
    cube[1][2][0] = SOLID;
    cube[1][2][1] = SOLID;
    cube[1][2][2] = SOLID;

    //Back side.
    //First row
    cube[2][0][0] = SOLID;
    cube[2][0][1] = SOLID;
    cube[2][0][2] = SOLID;

    //Second row
    cube[2][1][0] = SOLID;
    cube[2][1][1] = SOLID;
    cube[2][1][2] = SOLID;

    //Third row
    cube[2][2][0] = SOLID;
    cube[2][2][1] = SOLID;
    cube[2][2][2] = SOLID;

    //Checking columns (Y rows)
    for(int i = 0; i < DIMENSIONS; i++)
        for(int j = 0; j < DIMENSIONS; j++)
           if(!cube[i][0][j] && !cube[i][1][j] && !cube[i][2][j])
               cout << "Cube has a transparent column" << endl;

    //Checking X rows
    for(int i = 0; i < DIMENSIONS; i++)
        for(int j = 0; j < DIMENSIONS; j++)
            if(!cube[0][i][j] && !cube[1][i][j] && !cube[2][i][j])
                cout << "Cube has a transparent X row" << endl;

    //Checking Z rows
    for(int i = 0; i < DIMENSIONS; i++)
        for(int j = 0; j < DIMENSIONS; j++)
            if(!cube[i][j][0] && !cube[i][j][1] && !cube[i][j][2])
                cout << "Cube has a transparent Z row" << endl;

    return 0;
}