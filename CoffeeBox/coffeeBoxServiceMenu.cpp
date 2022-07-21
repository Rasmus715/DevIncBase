#include <iostream>

using namespace std;

void serviceMenu();
void printServiceMenuLoginPage();
void printServiceMenuLoginError();
void printServiceMenu();
void printWithdrawMenu();
void startServiceMenu();
void withdraw();
void setAccumulatedCash(double);
void setCupsAmount(int);
void addCups();
void printServiceMenuError();
void pressAnyNumber();
double getAccumulatedCash();
int getCupsAmount();



double accumulatedCash = 0.0;
double currentCups = 0.0;
int const PIN = 1234;
int const MAX_CUPS = 700;

int main()
{
    serviceMenu();
}

void serviceMenu()
{
    int pinEntered = 0;
    int escapeSymbol = 1;

    printServiceMenuLoginPage();

    while (true)
    {
        cin >> pinEntered;

        if (pinEntered == PIN) {
        	cout << "\n";
            startServiceMenu();
            break;
        } else if (pinEntered == escapeSymbol) {
            //BACK TO MAIN MENU
            break;
        } else {
        	cout << "\n";
            printServiceMenuLoginError();
        }
    }
}

void startServiceMenu()
{
    int choice = 0;
    int const withdrawButton = 1;
    int const addCupsButton = 2;
    int const mainMenuButton = 3;

    while (true)
    {	
		cout << "\n";
        printServiceMenu();
        cin >> choice;

        if (choice == withdrawButton) {
            cout << "\n";
			withdraw();            
        } else if (choice == addCupsButton) {
        	cout << "\n";
            addCups();
        } else if (choice == mainMenuButton) {
            //main menu entry
            break;
        } else {
        	cout << "\n";
            printServiceMenuError();
        }
    }
}

void addCups()
{
    int cupsAdded = 0;
    int buffer = 0;

    while (true)
    {
        buffer = getCupsAmount();
        cout << "Enter amount of cups you want to put into coffee machine:";
        cin >> cupsAdded;
        buffer += cupsAdded;

        if (cupsAdded <= 0) {
        	cout << "\n";
            cout << "ERROR! Incorrect input: " << cupsAdded << "." << endl;
            cout << "Input couldn't be less or equal zero." << endl;
            cout << "Please, enter the valid amount of cups." << endl;
        } else if (buffer > MAX_CUPS) {
        	cout << "\n";
            cout << "Error! There too many cups: " << buffer << ". Max value of cups is " << MAX_CUPS <<"." << endl;
            cout << "Please, enter the valid amount of cups." << endl;
        } else {
        	cout << "\n";
            setCupsAmount(buffer);
            cout << "Cups successfully added." << endl;
            cout << "Returning into service menu..." << endl;
            pressAnyNumber();
            break;
        }
    }
}

void withdraw()
{
	setAccumulatedCash(0.0);
    printWithdrawMenu();
    pressAnyNumber();
}

void setCupsAmount(int value)
{
    currentCups = value;
}

void printServiceMenuLoginPage()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
    cout << "Please, enter PIN and press \"Enter\":" << endl;
    cout << "Enter 1 to return to customer menu" << endl;
}

void printServiceMenuLoginError()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
    cout << "Error! Incorrect PIN." << endl;
    cout << "Please, enter PIN and press \"Enter\":" << endl;
    cout << "Enter 1 to return to customer menu" << endl;
    cout << "------------------" << endl;
}

void printServiceMenu()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
    cout << "Current amount of cups: " << getCupsAmount() << endl;
    cout << "Accumulated cash: " << getAccumulatedCash() << " BYN." << endl;
    cout << "Please, choose an option:" << endl;
    cout << "------------------" << endl;
    cout << "1. Withdraw cash" << endl;
    cout << "2. Add cups" << endl;
    cout << "3. Return to Main Menu" << endl;
    cout << "------------------" << endl;
}

void printWithdrawMenu()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
    cout << "Withdrawing cash..." << endl;
    cout << "Cash withdrawn." << endl;
    cout << "Returning to Service Menu..." << endl;
}

void printServiceMenuError()
{
    cout << "Error! Use numbers from range 1 - 3" << endl;
}

void pressAnyNumber() 
{
    char timeHolder = '/0';
    cout << "Enter any number to continue..." << endl;
    cout << "-------------------" << endl;
    cin >> timeHolder;
}

double getAccumulatedCash()
{
    return accumulatedCash;
}

void setAccumulatedCash(double number)
{
    accumulatedCash = number;
}

int getCupsAmount()
{
    return currentCups;
}
