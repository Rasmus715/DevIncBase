#include <iostream>

using namespace std;

void outOfRangeCoordinateError()
{
    cout << "WARNING: Coordinate of bishop cannot be less than 1 or more than 8." << endl;
}

void collisionCoordinateError(int bishopOneX, int bishopOneY)
{
    cout << "WARNING: Coordinate of bishops cannot be the same. Please, enter valid coordinates of the second bishop." << endl;
    cout << "Currently the coordinates of the fist bishop are: " << endl;
    cout << "X: " << bishopOneX << endl;
    cout << "Y: " << bishopOneY << endl;
}

int getCoordinates(string bishopNumber, string axis)
{
    int bishopCoordinate = 0;
    do
    {
        cout << "Please, enter the " << axis << " coordinates for the " << bishopNumber << " bishop: ";
        cin >> bishopCoordinate;
        if(bishopCoordinate > 8 or bishopCoordinate < 1)
            outOfRangeCoordinateError();
    }
    while (bishopCoordinate > 8 or bishopCoordinate < 1);

    return bishopCoordinate;
}

int main()
{
    int bishopOneX = 0;
    int bishopOneY = 0;
    int bishopTwoX = 0;
    int bishopTwoY = 0;
    bool answer = false;

    bishopOneX = getCoordinates("first", "X");
    bishopOneY = getCoordinates("first", "Y");

    do
    {
       bishopTwoX = getCoordinates("second", "X");
       bishopTwoY = getCoordinates("second", "Y");
       if (bishopOneX == bishopTwoX and bishopOneY == bishopTwoY)
           collisionCoordinateError(bishopOneX, bishopOneY);
    }
    while (bishopOneX == bishopTwoX and bishopOneY == bishopTwoY);

    for (int i = 0; i < 8; i++)
    {
        if (bishopOneX + i == bishopTwoY and bishopOneY + i == bishopTwoX)
        {
            answer = true;
        }

        if (bishopOneX == bishopTwoY - i and bishopOneY == bishopTwoX - i)
        {
            answer = true;
        }

        if (bishopOneX - i == bishopTwoY and bishopOneY + i == bishopTwoX)
        {
            answer = true;
        }

        if (bishopOneX + i == bishopTwoY and bishopOneY - i == bishopTwoX)
        {
            answer = true;
        }
    }

    if (answer)
        cout << "Bishops can beat one another!";
    else
        cout << "Bishops can't beat one another!";

    return  0;
}