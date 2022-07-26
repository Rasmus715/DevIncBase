#include <iostream>

using namespace std;

const int ZERO = 0;
const int ONE = 1;

int binaryNumber[32];
int binaryNumberSize = 0;

int enterAndValidateNumber();
bool isNumberRotating();
void printBinaryNumber(int binaryNumber[], int number);
void convertToBinary(int number);

int main()
{
    int number = 0;

    number = enterAndValidateNumber();
    convertToBinary(number);
    printBinaryNumber(binaryNumber, number);

    if (isNumberRotating())
        cout << "The number " << number << " is rotating";
    else
        cout << "The number " << number << " is not rotating";

    return 0;
}

int enterAndValidateNumber()
{
    int result = -1;

    do
    {
        cout << "Enter the number: ";
        cin >> result;
        if (result < 0)
        {
            cout << "Incorrect input. The number cannot be less than zero" << endl;
        }
    }
    while (result < 0);
    return result;
}

bool isNumberRotating()
{
    for (int j = binaryNumberSize - 1; j >= 1; j--)
    {
        if (binaryNumber[j] == ZERO && binaryNumber[j-1] != ONE)
        {
            return false;
        }

        if (binaryNumber[j] == ONE && binaryNumber[j-1] != ZERO)
        {
            return false;
        }
    }
    return true;
}

void printBinaryNumber(int binaryNumber[], int number)
{
    cout <<"The number " << number << " in binary is: ";
    for (int j = binaryNumberSize - 1; j >= 0; j--)
        cout << binaryNumber[j];
    cout << endl;
}

void convertToBinary(int number)
{
    while (number > 0)
    {
        binaryNumber[binaryNumberSize] = number % 2;
        number = number / 2;
        binaryNumberSize++;
    }
}

