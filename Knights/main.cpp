#include <iostream>

using namespace std;

void outOfRangeCoordinateError()
{
    cout << "WARNING: Coordinate of knight cannot be less than 1 or more than 8." << endl;
}

void collisionCoordinateError(int knightOneX, int knightOneY)
{
    cout << "WARNING: Coordinate of knights cannot be the same. Please, enter valid coordinates of the second knight." << endl;
    cout << "Currently the coordinates of the fist knight are: " << endl;
    cout << "X: " << knightOneX << endl;
    cout << "Y: " << knightOneY << endl;
}

int getCoordinates(string knightNumber, string axis)
{
    int knightCoordinate = 0;
    do
    {
        cout << "Please, enter the " << axis << " coordinates for the " << knightNumber << " knight: ";
        cin >> knightCoordinate;
        if (knightCoordinate > 8 or knightCoordinate < 1)
            outOfRangeCoordinateError();
    }
    while (knightCoordinate > 8 or knightCoordinate < 1);

    return knightCoordinate;
}

int main()
{
    int knightOneX = 0;
    int knightOneY = 0;
    int knightTwoX = 0;
    int knightTwoY = 0;
    bool answer = false;

    knightOneX = getCoordinates("first", "X");
    knightOneY = getCoordinates("first", "Y");

    do
    {
       knightTwoX = getCoordinates("second", "X");
       knightTwoY = getCoordinates("second", "Y");
       if (knightOneX == knightTwoX and knightOneY == knightTwoY)
           collisionCoordinateError(knightOneX, knightOneY);
    }
    while (knightOneX == knightTwoX and knightOneY == knightTwoY);

    if (knightOneX - 2 == knightTwoX and knightOneY + 1 == knightTwoY)
    {
        answer = true;
    }

    if (knightOneX  + 2 == knightTwoX and knightOneY - 1 == knightTwoY)
    {
        answer = true;
    }

    if (knightOneX + 1 == knightTwoX and knightOneY - 2 == knightTwoY)
    {
        answer = true;
    }

    if (knightOneX - 1 == knightTwoX and knightOneY - 2 == knightTwoY)
    {
        answer = true;
    }

    if (knightOneX -2 == knightTwoX and knightOneY - 1 == knightTwoY)
    {
        answer = true;
    }

    if (knightOneX + 1 == knightTwoX and knightOneY + 2 == knightTwoY)
    {
        answer = true;
    }

    if (knightOneX + 2 == knightTwoX and knightOneY - 1 == knightTwoY)
    {
        answer = true;
    }

    if (knightOneX - 1 == knightTwoX and knightOneY + 2 == knightTwoY)
    {
        answer = true;
    }

    if (answer)
        cout << "Knights can beat one another!";
    else
        cout << "Knights can not beat one another!";

    return  0;
}