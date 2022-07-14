#include <iostream>

using namespace std;

void outputDigitsInColumn();
void outputDigitsSum();
void outputDigitsProduct();
void validateSequence();
void findExtremaAndAverageDigits();
void validateEqualNumbersInRow();
void validateEqualNumbers();


int main() 
{
    //outputDigitsInColumn();
    //outputDigitsSum();
    //outputDigitsProduct();
    //validateSequence();
    //findExtremaAndAverageDigits();
    //validateEqualNumbersInRow();
    //validateEqualNumbers();
    return 0;
}

void outputDigitsInColumn()
{
    int number = 0;
    int remainder = 0;

    cout << "Enter a positive number: " << endl;
    cin >> number;

    remainder = number;

    if (number == 0)
    {
        cout << number;
        return;
    }

    while (number != 0)
    {
        remainder = number % 10;
        number /= 10;

        cout << remainder << endl;
    }
}

void outputDigitsSum()
{
    int number = 0;
    int sum = 0;

    cout << "Enter a positive number: " << endl;
    cin >> number;

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    cout << "The sum of number digits is: " << sum;
}

void outputDigitsProduct()
{
    int number = 0;
    int product = 1;

    cout << "Enter a positive number: " << endl;
    cin >> number;

    while (number > 0)
    {
        product *= number % 10;
        number /= 10;
    }

    cout << "The product of number digits is: " << product;
}

void validateSequence()
{
    int number = 0;
    int digit = 0;
    int nextDigit = 0;
    bool isAscending = false;
    bool isDescending = false;

    cout << "Enter a positive number: " << endl;
    cin >> number;

    if (number <= 0) {
        cout << "Incorrect input: " << number;
        return;
    }

    while (number > 9)
    {
        digit = number % 10;
        nextDigit = (number / 10) % 10;

        if (digit > nextDigit) {
            isAscending = true;
        } else if (digit < nextDigit) {
            isDescending = true;
        }
        number /= 10;
    }

    if ((isDescending) and isAscending or (!isDescending and !isAscending)) {
        cout << "The number sequence is not defined";
    } else if (isAscending) {
        cout << "The number is ascending sequence";
    } else {
        cout << "The number is descending sequence";
    }
}

void findExtremaAndAverageDigits()
{
    int number = 0;
    int maxDigit = 0;
    int minDigit = 0;
    int nextDigit = 0;
    int averageDigit = 0;
    int sum = 0;
    int numberOfDigits = 0;

    cout << "Enter a number > 0: " << endl;
    cin >> number;

    if (number <= 0) {
        cout << "Incorrect input: " << 0;
    }

    maxDigit = number % 10;
    minDigit = number % 10;

    while (number > 0)
    {
        nextDigit = number % 10;
        if (maxDigit < nextDigit) {
            maxDigit = nextDigit;
        } else if (minDigit > nextDigit) {
            minDigit = nextDigit;
        }
        sum += number % 10;
        number /= 10;
        numberOfDigits++;
    }

    averageDigit = sum / numberOfDigits;

    cout << "Max digit in number: " << maxDigit << endl;
    cout << "Min digit in number: " << minDigit << endl;
    cout << "Average digit in number: " << averageDigit << endl;
}

void validateEqualNumbersInRow()
{
    long long number = 0;
    long long digit = 0;
    long long nextDigit = 0;

    cout << "Enter a number: " << endl;
    cin >> number;

    while (number > 9 or number < -9)
    {
        digit = number % 10;
        nextDigit = (number / 10) % 10;

        if (digit == nextDigit)
        {
            cout << "Number does contain two identical digits in a row";
            return;
        }
        number /= 10;
    }
    cout << "Number does not contain two identical digits in a row";
}

void validateEqualNumbers()
{
    long long number = 0;
    long long innerNumber = 0;
    long long digit = 0;
    long long innerDigit = 0;

    cout << "Enter a number: " << endl;
    cin >> number;

    while (number > 0 or number < 0)
    {
        digit = number % 10;
        innerNumber = number / 10;

        while (innerNumber > 0 or innerNumber < 0)
        {
            innerDigit = innerNumber % 10;

            if (digit == innerDigit)
            {
                cout << "Number does contain two identical digits";
                return;
            }
            innerNumber /= 10;
        }
        number /= 10;
    }
    cout << "Number doesn't contain two equal digits";
}
