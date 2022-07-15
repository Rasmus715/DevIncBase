#include <iostream>

using namespace std;

void putSpaces(int number)
{
    while (number > 0)
    {
        cout << " ";
        number /= 10;
    }
}

int main()
{
    const int multiplier = 10;
    for (int i  = 1; i <= multiplier; i++)
    {
        for (int j = 1; j <= multiplier; j++) {
            putSpaces(j*multiplier);
            cout << i * j;
        }
        cout << endl;
    }
}

