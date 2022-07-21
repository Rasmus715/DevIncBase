#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    int reversedNumber = 0;
    int lastDigit = 0;

    cout << "Please, enter a number: ";
    cin >> number;

    while(number < 0)
    {
        cout << "The number cannot be less than zero." << endl;
        cout << "Please, enter valid number: ";
        cin >> number;
    }

    while(number != 0)
    {
        lastDigit = number % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        number /= 10;
    }

    cout << "Reversed Number: " << reversedNumber << endl;
    return 0;
}