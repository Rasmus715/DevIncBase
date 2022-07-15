#include <iostream>

using namespace std;

int main()
{
    int initialNumber = 0;
    int nextDigit = 0;
    int numberInCycle = 0;

    cout << "Please, enter the number: ";
    cin >> initialNumber;

    while (initialNumber > 0)
    {
        nextDigit = initialNumber % 10;
        initialNumber /= 10;
        numberInCycle = initialNumber;
        while (numberInCycle > 0)
        {
            if (numberInCycle % 10 == nextDigit)
            {
                cout << "Number does contain two equal digits";
                return 0;
            }
            numberInCycle /= 10;
        }
    }
    cout << "Number does not contain two equal digits";

    return 0;
}