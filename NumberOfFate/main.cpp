#include <iostream>

using namespace std;

int getSumOfDigits(int number);

int main()
{
    while(true) {
        int xCoordinateInt = rand() * 1.0 / RAND_MAX * (9 + 1);
        cout << "randValue: " << xCoordinateInt;
    }
}

int getSumOfDigits(int number)
{
    int result = 0;

    while (number > 0)
    {
        result += number % 10;
        number /= 10;
    }

    return result;
}