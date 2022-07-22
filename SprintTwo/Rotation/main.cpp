#include <iostream>

using namespace std;

const int ZERO = 0;
const int ONE = 1;

int enterAndValidateNumber();
bool isNumberRotating(long number);

int main()
{
    long number = 0;

    number = enterAndValidateNumber();
    if(isNumberRotating(number))
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
        cout << "Enter the number of sequence: ";
        cin >> result;
        if(result < 0)
        {
            cout << "Incorrect input. The number of sequence cannot be less than zero" << endl;
            cout << "Enter the number of sequence: ";
        }
    }
    while(result < 0);
    return result;
}

bool isNumberRotating(long number)
{
    long lastDigit = 0;

    while(number > 9)
    {
        lastDigit = number % 10;

        if(lastDigit != ONE && lastDigit != ZERO)
        {
            return false;
        }

        if(lastDigit == ZERO && number / 10 % 10 != ONE)
        {
            return false;
        }

        if(lastDigit == ONE && number / 10 % 10 != ZERO)
        {
            return false;
        }

        number /= 10;
    }

    return true;
}