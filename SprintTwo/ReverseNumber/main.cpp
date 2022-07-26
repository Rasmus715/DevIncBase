#include <iostream>

using namespace std;

int enterAndValidateNumber();
int reverseNumber(int);

int main()
{
    int number = 0;

    number = enterAndValidateNumber();

    cout << "Reversed Number: " << reverseNumber(number) << endl;
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
            cout << "Enter the number of sequence: ";
        }
    }
    while (result < 0);
    return result;
}

int reverseNumber(int number)
{
    int reversedNumber = 0;
    int lastDigit = 0;

    while (number != 0)
    {
        lastDigit = number % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        number /= 10;
    }
    return reversedNumber;
}