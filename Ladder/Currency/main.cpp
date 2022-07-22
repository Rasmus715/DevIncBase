#include <iostream>

using namespace std;

void printMenu();
double getMoney(double);
double convertBYNtoUSD(double);
double convertBYNtoCNY(double);

const double bynToUsd = 2.68;
const double bynToCny = 0.37;

int main ()
{

    int choice = 0;
    double byn = 0.0;

    while(true)
    {
        printMenu();
        cout << "Your choice? ";
        cin >> choice;
        if (choice == 1)
        {
            byn = getMoney(byn);

        }
        else
            if (choice == 2)
                byn = convertBYNtoUSD(byn);
            else
                if (choice == 3)
                    byn = convertBYNtoCNY(byn);
        else
            if (choice == 0)
                break;
        else
            cout << "Select [1..5], please" << endl;
    }
    return 0;
}

void printMenu()
{
    cout << endl << "Currency Exchange Point" << endl;
    cout << "1) Deposit BYN" << endl;
    cout << "2) Convert to USD" << endl;
    cout << "3) Convert to CNY" << endl;
    cout << "0) Exit" << endl;
}

double getMoney(double byn)
{
    double depositAmount = 0.0;
    do
    {
        cout << "Please, specify how much you want to deposit: ";
        cin >> depositAmount;
        if (depositAmount < 0)
            cout << "The deposit amount cannot be less than zero. Please, specify the correct amount." << endl;
    }
    while(depositAmount < 0);
    depositAmount = (int)(depositAmount * 100) / 100.;
    byn += depositAmount;
    cout << "Ok, " << depositAmount << " BYN deposited." << endl;
    cout << "Now you have " << byn << " BYN in your wallet" << endl;
    return byn;
}

double convertBYNtoUSD(double byn)
{
    cout << "Take your " <<  (int)(byn / bynToUsd * 100) / 100.  << " USD" << endl;
    byn = 0;
    return byn;
}

double convertBYNtoCNY(double byn )
{
    cout << "Take your " <<  (int)(byn / bynToCny * 100) / 100.  << " CNY" << endl;
    byn = 0;
    return byn;
}