#include <iostream>

using namespace std;

void putSpaces(int i, int j, int multiplier)
{
    int maxNumber = multiplier * i;
    int amountOfDigitsInMaxNumber = 0;
    int amountOfDigitsInNumber = 0;
    int number = j * i;

    while (maxNumber > 0)
    {
        maxNumber /= 10;
        amountOfDigitsInMaxNumber++;
    }

    while (number > 0)
    {
        number /= 10;
        amountOfDigitsInNumber++;
    }

    while (amountOfDigitsInNumber < amountOfDigitsInMaxNumber)
    {
        cout << " ";
        amountOfDigitsInNumber++;
    }
}

int main()
{
    const int multiplier = 10;
    for (int j  = 1; j <= multiplier; j++)
    {
        for (int i = 1; i <= multiplier; i++)
        {
            if (i != 1)
                cout << " ";

            putSpaces(i, j, multiplier);
            cout << i * j;
        }
        cout << endl;
    }
}

