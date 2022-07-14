#include <iostream>

using namespace std;

int summDigits(int number);

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
    
    if (day > 31 or day < 1) 
	{
		cout << "Incorrect input: day is: " << day;
    }
    
    if (month > 12 or month < 1) 
	{
		cout << "Incorrect input: month is: " << month;
    }
    
    if (year > 2022  or year < 1900) 
	{
		cout << "Incorrect input: year is: " << year;
    }

    cout << "Your number of fate is: " << getSumOfDigits(getSumOfDigits(day) + getSumOfDigits(month) + getSumOfDigits(year)) << endl;

    return  0;

int summDigits(int number)
{
    int result = 0;

    while (number > 0)
    {
        result += number % 10;
        number /= 10;
    }

    return result;
}
