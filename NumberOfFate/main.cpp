#include <iostream>

using namespace std;

int getSumOfDigits(int number);

int main()
{
    const int MAX_MONTH = 12;
    const int MAX_DAY = 31;
    const int MIN_MONTH = 1;
    const int MIN_DAY = 1;
    const int MAX_YEAR = 2022;

    int day = 0;
    int month = 0;
    int year = 0;
    int birthdayDigitsSum;

    do
    {
        cout << "Please enter the day of your birthday: ";
        cin >> day;

        if (day < MIN_DAY or day > MAX_DAY)
            cout << "Day number cannot be less than 1 or more than 31." << endl;
    }
    while (day < MIN_DAY or day > MAX_DAY);

    do
    {
        cout << "Please enter the month of your birthday: ";
        cin >> month;

        if (month < MIN_MONTH or month > MAX_MONTH)
            cout << "Month number cannot be less than 1 or more than 12." << endl;
    }
    while (month < MIN_MONTH or month > MAX_MONTH);

    do
    {
        cout << "Please enter the year of your birthday: ";
        cin >> year;

        if (year > MAX_YEAR)
            cout << "Year number cannot be more than 2022." << endl;
    }
    while (year > MAX_YEAR);

    birthdayDigitsSum = getSumOfDigits(day) + getSumOfDigits(month) + getSumOfDigits(year);
    cout << "Your number of fate is: " << getSumOfDigits(birthdayDigitsSum) << endl;

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