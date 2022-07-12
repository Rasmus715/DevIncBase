#include <iostream>
#include "iomanip"

using namespace std;

int main()
{
    for (int multiplier = 1; multiplier <= 9; multiplier++)
    {
        for (int i = 1; i <= 9; i++)
            if(i == 1)
                cout << multiplier * i;
            else
                cout << setw(3) << multiplier * i;
        cout << endl;
    }
}