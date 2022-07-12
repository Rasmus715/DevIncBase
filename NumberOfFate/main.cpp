#include <iostream>

using namespace std;

int main()
{
    int day = 0;
    int month = 0;
    int year = 0;
    int numberOfFateSum = 0;
    int numberOfFate = 0;

    cout << "Please enter the day of your birthday: ";
    cin >> day;
    cout << "Please enter the number of month of your birthday: ";
    cin >> month;
    cout << "Please enter the year of your birthday: ";
    cin >> year;

    while (day > 0)
    {
        numberOfFateSum += day % 10;
        day /= 10;
    }

    while (month > 0)
    {
        numberOfFateSum += month % 10;
        month /= 10;
    }

    while (year > 0)
    {
        numberOfFateSum += year % 10;
        year /= 10;
    }

    while (numberOfFateSum > 0)
    {
        numberOfFate += numberOfFateSum % 10;
        numberOfFateSum /= 10;
    }

    cout << "Your number of fate is: " << numberOfFate << endl;

    return  0;
}