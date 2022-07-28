#include <iostream>

using namespace std;

void printTree(int x);

int main()
{
    printTree(6);
    return 0;
}

void printTree(int x)
{
    int numberOfStars = 1;
    for(; numberOfStars < x; numberOfStars++)
    {
        for (int i = 0; i < numberOfStars; i++)
            cout << "*";
        cout << endl;
    }

    for(; numberOfStars > 0; numberOfStars--)
    {
        for (int i = 0; i < numberOfStars; i++)
            cout << "*";
        cout << endl;
    }
}