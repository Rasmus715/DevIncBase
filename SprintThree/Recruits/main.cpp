#include <iostream>

using namespace std;
bool rotateLine();

const int SIZE = 10;
char line[SIZE] = {'<', '<', '>','<', '<', '<', '>','<', '<', '>'};

int main()
{
    cout << "TURN LEFT!" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << line[i] << " ";
    }
    cout << endl;

    while(rotateLine());

    cout << "STOP!";

    return  0;
}

bool rotateLine()
{
    int rotations = 0;

    for(int i = 0; i < 9; i++)
    {
        if(line[i] == '>' && line[i + 1] == '<')
        {
            line[i] = '<';
            line[i + 1] = '>';
            rotations++;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        cout << line[i] << " ";
    }
    cout << endl;

    if(rotations == 0)
        return false;
    else
        return true;
}