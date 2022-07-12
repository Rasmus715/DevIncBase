#include <iostream>

using namespace std;

int getSumOfDigits(int number);

int main()
{
    int day = 0;
    int month = 0;
    int year = 0;

    cout << "Please enter the day of your birthday: ";
    cin >> day;
    cout << "Please enter the month number of your birthday: ";
    cin >> month;
    cout << "Please enter the year of your birthday: ";
    cin >> year;


    cout << "Your number of fate is: " << getSumOfDigits(getSumOfDigits(day) + getSumOfDigits(month) + getSumOfDigits(year)) << endl;

    return  0;
}

int getSumOfDigits(int number)
{
    int result = 0;

    while (number > 0)
    {
        result += number % 10;
        number /= 10;
    }

    return result;
}