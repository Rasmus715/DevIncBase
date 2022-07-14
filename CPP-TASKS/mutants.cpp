#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double mutantsCounter = 0.0;
    double reproductionInPercent = 0.0;
    double reproductionCoefficient = 0.0;
    double reproduction = 0;
    int clearance = 0;
    int daysToVictory = 0;

    cout << "Enter the number of mutants:" << endl;
    cin >> mutantsCounter;
    cout << "Enter the reproduction percentage:" << endl;
    cin >> reproductionInPercent;
    cout << "Enter the amount of mutants removed each day:" << endl;
    cin >> clearance;
    
    if (mutantsCounter <= 0) {
    	cout << "Error: wrong amount of mutants:" << mutantsCounter;
    	return 1;
    }

    reproductionCoefficient = reproductionInPercent / 100;

    while (mutantsCounter > 0)
    {
        reproduction = floor(mutantsCounter * reproductionCoefficient);

        if (reproduction >= clearance)
        {
            cout << "Minsk won't be cleared of mutants";
            return 0;
        }
        mutantsCounter += reproduction - clearance;
        daysToVictory++;
    }
    cout << "Minsk will be cleared of mutants in " << daysToVictory << " days.";

        return  0;
}

