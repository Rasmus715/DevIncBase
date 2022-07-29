#include <iostream>

using namespace std;

const bool TRANSPARENT = false;
const int SIDE_SIZE = 3;

bool checkForGaps(bool cube[SIDE_SIZE][SIDE_SIZE][SIDE_SIZE]);

int main()
{
    bool cube[SIDE_SIZE][SIDE_SIZE][SIDE_SIZE];
    srand(time(nullptr));

    for (int z = 0; z < SIDE_SIZE; z ++)
        for (int y = 0; y < SIDE_SIZE; y++)
            for (int x = 0; x < SIDE_SIZE; x++)
                cube[y][z][x] = rand() % 2 == TRANSPARENT;

    if(checkForGaps(cube))
        cout << "Cube has a gap";
    else
        cout << "Cube does not has a gap";
    return 0;
}

bool checkForGaps(bool cube[SIDE_SIZE][SIDE_SIZE][SIDE_SIZE])
{
    //Checking columns (Y rows)
    for(int i = 0; i < SIDE_SIZE; i++)
        for(int j = 0; j < SIDE_SIZE; j++)
            if(!cube[i][0][j] && !cube[i][1][j] && !cube[i][2][j])
                return true;
                //cout << "Cube has a transparent column" << endl;

    //Checking X rows
    for(int i = 0; i < SIDE_SIZE; i++)
        for(int j = 0; j < SIDE_SIZE; j++)
            if(!cube[0][i][j] && !cube[1][i][j] && !cube[2][i][j])
                return true;
                //cout << "Cube has a transparent X row" << endl;

    //Checking Z rows
    for(int i = 0; i < SIDE_SIZE; i++)
        for(int j = 0; j < SIDE_SIZE; j++)
            if(!cube[i][j][0] && !cube[i][j][1] && !cube[i][j][2])
                return true;
                //cout << "Cube has a transparent Z row" << endl;
                return false;
}