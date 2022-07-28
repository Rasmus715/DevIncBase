#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    int heights[SIZE] = {2,4,3,6,8,10,9,12,14,10};
    int maxHeight = heights[0];

    cout << "Heights: ";
    for(int i = 1; i < 10; i++)
    {
        cout << heights[i] << " ";
    }
    cout << endl;

    cout << "User don't see heights with indexes: " << endl;
    for(int i = 1; i < 10; i++)
    {
        if(heights[i] > maxHeight)
            maxHeight = heights[i];
        if(heights[i] < maxHeight)
            cout << i << " ";
    }

    return  0;
}
