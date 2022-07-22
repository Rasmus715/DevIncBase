#include <iostream>

using namespace std;

int enterAndValidateNumber();
double getFibonacciNumber(int);


int main()
{
    int number = 0.0;

    number = enterAndValidateNumber();

    cout << "The " << number << " number of Fibonacci sequence is: " << getFibonacciNumber(number);

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

double getFibonacciNumber(int number)
{
    double n1 = 0;
    double n2 = 1;
    double n3 = 0;

    for(int i = 2; i <= number; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }

    return n3;
}
