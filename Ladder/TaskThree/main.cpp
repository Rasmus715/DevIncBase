#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    int sum = 1;

    cout << "Please, enter the number (min. 10): ";
    cin >> number;

    while (number > 0)
    {
        sum *= number % 10;
        number /= 10;
    }

    cout << "Multiplication of its digits: " << sum << endl;

    return 0;
}