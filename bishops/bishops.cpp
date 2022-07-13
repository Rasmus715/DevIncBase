#include <iostream>

using namespace std;

int main()
{
    int yAxis1 = 0;
    int xAxis1 = 0;
    int yAxis2 = 0;
    int xAxis2 = 0;
    bool answer = false;

    cout << "Enter coordinates X for the first bishop: ";
    cin >> xAxis1;

    cout << "Enter coordinates Y for the first bishop: ";
    cin >> yAxis1;

    cout << "Enter coordinates X for the second bishop: ";
    cin >> xAxis2;

    cout << "Enter coordinates Y for the second bishop: ";
    cin >> yAxis2;

    for (int i = 0; i < 8; i++) {
        
        if (xAxis1 + i == xAxis2 and yAxis1 + i == yAxis2) {
            answer = true;
        }
        if (xAxis1 == xAxis2 - i and yAxis1 == yAxis2 - i) {
        	answer = true;
        }
        if (xAxis1 - i == xAxis2 and yAxis1 + i == yAxis2) {
        	answer = true;
        }
        if (xAxis1 + i == xAxis2 and yAxis1 - i == yAxis2) {
        	answer = true;
        } 
    }

    if (answer) {
        cout << "Bishops can beat one another!";
    } else {
        cout << "Bishops can't beat one another!";
    }

    return 0;
}
