#include <iostream>

using namespace std;

int main()
{
    int yAxis1 = 0;
    int xAxis1 = 0;
    int yAxis2 = 0;
    int xAxis2 = 0;
    bool answer = false;

    cout << "Enter coordinates X for the first horse: ";
    cin >> xAxis1;

    cout << "Enter coordinates Y for the first horse: ";
    cin >> yAxis1;

    cout << "Enter coordinates X for the second horse: ";
    cin >> xAxis2;

    cout << "Enter coordinates Y for the second horse: ";
    cin >> yAxis2;
    
    if ((xAxis1 > 8 or xAxis1 < 1) or (yAxis1 > 8 or yAxis2 < 1) or (xAxis2 > 8 or xAxis1 < 1) or (yAxis1 > 8 or yAxis2 < 1)) {
		cout << "Error: Wrong coordinates. Use numbers < 9 and > 0" << endl;
		return 1;
    }
	
    if (xAxis1 - 2 == xAxis2 and yAxis1 + 1 == yAxis2) {
        answer = true;
    }
    if (xAxis1  + 2 == xAxis2 and yAxis1 - 1 == yAxis2) {
        answer = true;
    }   
    if (xAxis1 + 1 == xAxis2 and yAxis1 - 2 == yAxis2) {
        answer = true;
    }
    if (xAxis1 - 1 == xAxis2 and yAxis1 - 2 == yAxis2) {
        answer = true;
    }
    if (xAxis1 -2 == xAxis2 and yAxis1 - 1 == yAxis2) {
        answer = true;
    }
    if (xAxis1 + 1 == xAxis2 and yAxis1 + 2 == yAxis2) {
        answer = true;
    }
    if (xAxis1 + 2 == xAxis2 and yAxis1 - 1 == yAxis2) {
        answer = true;
    }
    if (xAxis1 - 1 == xAxis2 and yAxis1 + 2 == yAxis2) {
        answer = true;
    }
            
    if (answer) {
        cout << "Horses can beat one another!";
    } else {
        cout << "Horses can't beat one another!";
    }

    return 0;
}
