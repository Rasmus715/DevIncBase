#include <iostream>

using namespace std;

int main()
{
    double n1 = 0;
    double n2 = 1;
    double n3 = 0;
    double number = 0;

    cout << "Enter the number of elements: ";
    cin >> number;

    for(int i = 2; i <= number; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }

    cout << n3 << endl;

    return 0;
}
