#include <iostream>
#include "iomanip"

using namespace std;

int main()
{
    for (int multiplier = 1; multiplier <= 10; multiplier++)
    {
        for (int i = 1; i <= 10; i++)
            cout << setw(4) << multiplier * i;
        cout << endl;
    }
}