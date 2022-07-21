#include <iostream>

using namespace std;

int main()
{
    long number = 0;
    int lastDigit = 0;
    const int ZERO = 0;
    const int ONE = 1;

    cout << "Please, enter a number: ";
    cin >> number;

    while(number > 9)
    {
        lastDigit = number % 10;

        if(lastDigit != ONE && lastDigit != ZERO)
        {
            cout << "Number is not rotating.";
            return 0;
        }

        if(lastDigit == ZERO && number / 10 % 10 != ONE)
        {
            cout << "Number is not rotating.";
            return 0;
        }

        if(lastDigit == ONE && number / 10 % 10 != ZERO)
        {
         cout << "Number is not rotating.";
         return 0;
        }

        number /= 10;
    }

    cout << "Number is rotating" << endl;
    return 0;
}