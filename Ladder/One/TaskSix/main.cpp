#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    int nextDigit = 0;

    cout << "Please, enter the number: ";
    cin >> number;

    while (number > 9)
    {
        nextDigit = number % 10;
        if (nextDigit == number / 10 % 10)
        {
            cout << "Number contains two equal digits, that are staying in a row.";
            return 0;
        }
        number /= 10;
    }
    cout << "Number does not contain two equal digits, that are staying in a row";

    return 0;
}