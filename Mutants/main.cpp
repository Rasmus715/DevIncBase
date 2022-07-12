#include <iostream>
#include "iomanip"

using namespace std;

int main()
{
    int mutants = 0;
    double breedPercentage = 0.0;
    double breedInMutants = 0.0;
    int destructionOfMutantsByDay = 0;
    int daysToVanishMutants = 0;

    cout << "Minsk is under siege by mutants!!!" << endl << "Please, enter the amount of mutants, currently attacking the city: ";
    cin >> mutants;
    cout << "Please, enter the speed of mutants breeding per day in percentage: ";
    cin >> breedPercentage;
    cout << "Please, enter the amount of mutants, vanished by housing maintenance team: ";
    cin >> destructionOfMutantsByDay;

    while (mutants > 0)
    {
        breedInMutants = mutants * (breedPercentage / 100);

        if (breedInMutants >= destructionOfMutantsByDay)
        {
            cout << "There is no escape now.";
            return 0;
        }

        mutants += breedInMutants - destructionOfMutantsByDay;
        daysToVanishMutants++;
    }

    cout << "The city will be cleared of mutants in " << daysToVanishMutants << " days.";
    return  0;
}