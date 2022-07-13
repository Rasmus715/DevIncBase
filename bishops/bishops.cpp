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
    
    if ((xAxis1 > 8 or xAxis1 < 1) or (yAxis1 > 8 or yAxis2 < 1) or (xAxis2 > 8 or xAxis1 < 1) or (yAxis1 > 8 or yAxis2 < 1)) {
		cout << "Error: Wrong coordinates. Use numbers < 9 and > 0" << endl;
		return 1;
    }
	
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
