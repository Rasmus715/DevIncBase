#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
bool rotateLine();
void printLine();
void sleep(int milliseconds);

const int SIZE = 10;
const int SECOND = 1000;
char line[SIZE] = {'<', '<', '>','<', '<', '<', '>','<', '<', '>'};

int main()
{
    cout << "TURN LEFT!" << endl;

    printLine();

    while(rotateLine());

    cout << "STOP!";
    return  0;
}

bool rotateLine()
{
    int rotations = 0;

    for(int i = 0; i < SIZE - 1; i++)
    {
        if(line[i] == '>' && line[i + 1] == '<')
        {
            line[i] = '<';
            line[i + 1] = '>';
            rotations++;
            i += 2;
        }
    }

    if(rotations == 0)
        return false;
    else
    {
        sleep(SECOND);
        printLine();
        return true;
    }
}

void printLine()
{
    for(int i = 0; i < 10; i++)
    {
        cout << line[i] << " ";
    }
    cout << endl;
}

void sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}