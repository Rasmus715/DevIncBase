#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    int digit = 0;
    bool ascending = false;
    bool descending = false;

    cout << "Please, enter the number: ";
    cin >> number;

    while (number > 9)
    {
        digit = number % 10;
        if (number / 10 % 10 < digit)
            ascending = true;
        if(number / 10 % 10 > digit)
            descending = true;
        number /= 10;
    }

    if ((descending and ascending) or (!descending and !ascending))
        cout << "Digits in number are neither descending nor ascending";
    else
    if (descending)
        cout << "Digits in number are descending";
    else
        cout << "Digits in number are ascending";

    return 0;
}
