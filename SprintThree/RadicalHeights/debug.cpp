#include <iostream>

using namespace std;

const int SIZE = 10;
double heights[SIZE] = {2.5, 4, 10, 15, 20, 30, 9.23, 12.45, 14.67, 10.89};
int const STEP = 1;

void printSightlessHeights();
void printHeights();
bool arrayHasSightlessHeights();

int main()
{
    printHeights();
    printSightlessHeights();
    return 0;
}

void printHeights()
{
    cout << "Heights: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << heights[i] << " ";
    }
    cout << endl;
}

void printSightlessHeights()
{
    double heightVisibilityRate = heights[1] - heights[0];
    double heightWithRate = 0.0;
    int currentStep = STEP * 2;


    if (arrayHasSightlessHeights())
    {
        cout << "User don't see heights: " << endl;
        for (int i = 2; i < SIZE; i++)
        {
            heightWithRate = currentStep * heightVisibilityRate + heights[0];
            if (heights[i] <= heightWithRate)
            {

                cout << heights[i] << "(" << i << ") ";
            }

            if (heights[i] > heightVisibilityRate)
                heightVisibilityRate = heights[i] - heights[0];

            currentStep += STEP;
        }
    }
    else
        cout << "User sees everything";
}

bool arrayHasSightlessHeights()
{
    double heightVisibilityRate = 0.0;
    heightVisibilityRate = heights[1] - heights[0];
    double heightWithRate = 0.0;
    int currentStep = STEP * 2;

    for (int i = 2; i < SIZE; i++)
    {
        heightWithRate =  currentStep * heightVisibilityRate + heights[0];

        if (heights[i] <= heightWithRate)
        {
            if(heights[i] > heightVisibilityRate)
                heightVisibilityRate = heights[i] - heights[0];
            return true;
        }
        currentStep += STEP;
    }
    return false;
}