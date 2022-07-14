#include <iostream>

using namespace std;

const int N = 15;

int main()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << i * j << " ";

            if (i * j < N)
			{
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

