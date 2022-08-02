#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

bool randomBool(int min, int max);
int countNeighbours(int x, int y);
void sleep(int milliseconds);
void nextGeneration();
void clearScreen();
void renderField();

int const FIELD_SIZE = 100;
int const DENSITY = 8;
int const TIMEOUT = 150;
bool field[FIELD_SIZE][FIELD_SIZE];

int main()
{
    srand(time(nullptr));
    int generation = 1;

    for (int i = 0; i < FIELD_SIZE; i++)
        for (int j = 0; j < FIELD_SIZE; j++)
            field[i][j] = randomBool(0,DENSITY);

    while(true)
    {
        cout << "Generation №." << generation << endl << endl;
        renderField();
        nextGeneration();
        generation++;
        sleep(TIMEOUT);
        clearScreen();
    }
}

bool randomBool(int min, int max)
{
    return  min + rand() % (( max + 1 ) - min) == 0;
}

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void renderField()
{
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (int j = 0; j < FIELD_SIZE; j++)
            if (field[i][j])
                cout << "X" << " ";
            else
                cout << "_" << " ";
        cout << endl;
    }
}

int countNeighbours(int x, int y)
{
    int count = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            //Preventing out of bounds exception and looking by other side of array, if we got to the edge of it.
            int col = (x + i + FIELD_SIZE) % FIELD_SIZE;
            int row = (y + j + FIELD_SIZE) % FIELD_SIZE;

            bool isSelfChecking = col == x && row == y;
            int hasLife = field[col][row];

            if(hasLife && !isSelfChecking)
                count++;
        }
    }

    return count;
}

void nextGeneration()
{
    for (int i = 0; i < FIELD_SIZE; i++)
        for (int j = 0; j < FIELD_SIZE; j++)
        {
            int neighbours = countNeighbours(i,j);
            bool hasLife = field[i][j];
            if (!hasLife && neighbours == 3)
                field[i][j] = true;
            else if (hasLife && (neighbours < 2 || neighbours > 3))
            {
                field[i][j] = false;
            }
        }

}

void sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}