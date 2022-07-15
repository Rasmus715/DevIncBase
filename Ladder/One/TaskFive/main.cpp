#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    int biggestDigit = 0;
    int smallestDigit = 0;
    int averageSum = 0;
    int numberOfDigits = 0;
    int average = 0;

    cout << "Please, enter the number: ";
    cin >> number;

    biggestDigit = number % 10;
    smallestDigit = number % 10;

    while (number > 0)
    {
        if (biggestDigit < number % 10)
            biggestDigit = number % 10;

        if (smallestDigit > number % 10)
            smallestDigit = number % 10;

        averageSum += number % 10;
        numberOfDigits++;
        number /= 10;
    }

    average = averageSum / numberOfDigits;
    
    cout << "Biggest digit in number: " << biggestDigit << endl;
    cout << "Smallest digit in number: " << smallestDigit << endl;
    cout << "Average digit in number: " << average << endl;

    return 0;
}
