#include <iostream>

using namespace std;

const int SIZE = 10;
double heights[SIZE] = {0, 3, 10, 15, 20, 30, 9.23, 12.45, 14.67, 10.89};

void printSightlessHeights();
void printHeights();

int main()
{

    printHeights();
    printSightlessHeights();

    return  0;
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
    double heightVisibilityRate = 0.0;
    heightVisibilityRate = heights[1] - heights[0];
    double heightWithRate = 0.0;
    double maxHeight = heights[1];
    bool hasSightlessHeights = false;

    for (int i = 2; i < SIZE; i++)
    {
        heightWithRate = i * heightVisibilityRate + heights[0];
        if (heights[i] <= heightWithRate || heights[i] < maxHeight)
        {
            if (heights[i] > maxHeight)
                maxHeight = heights[i];
            hasSightlessHeights = true;
            break;
        }
    }

    maxHeight = heights[1];

    if(hasSightlessHeights)
    {
        cout << "User don't see heights: " << endl;
        for (int i = 2; i < SIZE; i++)
        {

            heightWithRate = i * heightVisibilityRate + heights[0];
            if (heights[i] <= heightWithRate || heights[i] < maxHeight)
            {
                cout << heights[i] << "(" << i << ") ";
            }

            if(heights[i] > maxHeight)
                maxHeight = heights[i];
        }
    }
    else
        cout << "User sees everything";
}
