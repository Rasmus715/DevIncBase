#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

//Ivan methods
void PrintCoffeeBoxLogo();
void mainMenu();
void printMainMenu();
void printCurrencyMenu();
void cookCoffee(string coffee, double price);
void optionOutOfRangeException();
void Sleep(int milliseconds);
void cookCoffeeProgressBar();
void currencyMenu();
void notEnoughMoneyException();
void printBalance();
void outOfCupsException();
void execute();
void clearScreen();
void softlockCoffeebox();

//Max methods
void serviceMenu();
void printServiceMenuLoginPage();
void serviceMenuLoginError();
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

const string CURRENCY = "BYN";
const string LATTE = "Latte";
const string CAPPUCCINO = "Cappuccino";
const string ESPRESSO = "Espresso";
const double LATTE_PRICE = 2.0;
const double ESPRESSO_PRICE = 3.0;
const double CAPPUCCINO_PRICE = 2.5;
const int MAX_CUPS = 700;
const int INITIAL_CUPS = 7;
const int PIN = 7818;
double currentlyDeposited = 0.0;
int cups = INITIAL_CUPS;
double accumulatedCash = 0.0;
int wrongPinEntries = 0;
int progressBarWidth = 60;
const int wrongPinEntriesToSoftlock = 3;


int main()
{
    execute();
    return  0;
}

void execute() {
    printBalance();
    printMainMenu();
    mainMenu();
}

void mainMenu()
{
    int option = 0;

    cin >> option;

    switch (option)
    {
        case 1:
            clearScreen();
            printCurrencyMenu();
            return currencyMenu();
        case 2:
            clearScreen();
            printBalance();
            return cookCoffee(ESPRESSO, ESPRESSO_PRICE);
        case 3:
            clearScreen();
            printBalance();
            return cookCoffee(CAPPUCCINO, CAPPUCCINO_PRICE);
        case 4:
            clearScreen();
            printBalance();
            return cookCoffee(LATTE, LATTE_PRICE);
        case 5:
            clearScreen();
            return serviceMenu();
        default:
            clearScreen();
            printBalance();
            printMainMenu();
            optionOutOfRangeException();
            return mainMenu();
    }
}

void cookCoffee(string coffee, double price)
{
    if (currentlyDeposited < price)
        return notEnoughMoneyException();

    clearScreen();
    PrintCoffeeBoxLogo();
    cout << "Your coffee is being prepared, please wait a bit..." << endl;
    cookCoffeeProgressBar();
    cout << endl;
    cout << "Now, take your " << coffee << "." << endl;
    cout << "Have a nice day!" << endl;
    Sleep(5000);
    clearScreen();
    cups--;
    currentlyDeposited -= price;
    clearScreen();
    printBalance();
    printMainMenu();
    return mainMenu();
}

void currencyMenu()
{
    if (cups == 0)
    {
        clearScreen();
        printBalance();
        printMainMenu();
        outOfCupsException();
        mainMenu();
    }

    int option = 0;
    cin >> option;

    switch (option)
    {
        case 1:
            currentlyDeposited += 2;
            accumulatedCash += 2;
            clearScreen();
            printCurrencyMenu();
            return currencyMenu();
        case 2:
            currentlyDeposited += 1;
            accumulatedCash += 1;
            clearScreen();
            printCurrencyMenu();
            return currencyMenu();
        case 3:
            currentlyDeposited += 0.5;
            accumulatedCash += 0.5;
            clearScreen();
            printCurrencyMenu();
            return currencyMenu();
        case 4:
            currentlyDeposited += 0.2;
            accumulatedCash += 0.2;
            clearScreen();
            printCurrencyMenu();
            return currencyMenu();
        case 5:
            currentlyDeposited += 0.1;
            accumulatedCash += 0.1;
            clearScreen();
            printCurrencyMenu();
            return currencyMenu();
        case 6:
            clearScreen();
            printBalance();
            printMainMenu();
            return mainMenu();
        default:
            clearScreen();
            printCurrencyMenu();
            optionOutOfRangeException();
            return currencyMenu();
    }
}

void cookCoffeeProgressBar()
{
    double progress = 0.0;
    int isDone = false;
    while (progress <= 1.0)
    {
        cout << "[";
        int pos = progressBarWidth * progress;
        for (int i = 0; i < progressBarWidth; ++i)
        {
            if (i < pos)
                cout << "=";
            else
                if (i == pos) cout << ">";
                else cout << " ";
        }
        cout << "] " << int(progress * 100.0) << " %\r";
        Sleep(500);
        cout << flush;
        progress += 0.15;

        if (isDone)
            return;

        if (progress > 1.0)
        {
            progress = 1.0;
            isDone = true;
        }

    }
    cout << endl;
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
            wrongPinEntries = 0;
            clearScreen();
            startServiceMenu();
            break;
        } else if (pinEntered == escapeSymbol) {
            clearScreen();
            printBalance();
            printMainMenu();
            return mainMenu();
        } else {
            cout << "\n";
            clearScreen();
            wrongPinEntries++;
            serviceMenuLoginError();
            if(wrongPinEntries == wrongPinEntriesToSoftlock)
            {
                softlockCoffeebox();
            }

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
        printServiceMenu();
        cout << "\n";
        cin >> choice;

        if (choice == withdrawButton) {
            clearScreen();
            withdraw();
        } else if (choice == addCupsButton) {
            clearScreen();
            addCups();
        } else if (choice == mainMenuButton) {
            clearScreen();
            printBalance();
            printMainMenu();
            return mainMenu();
        } else {
            cout << "\n";
            clearScreen();
            printServiceMenu();
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
        cout << "Enter amount of cups you want to put into coffee machine: ";
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
            clearScreen();
            break;
        }
    }
}

void withdraw()
{
    setAccumulatedCash(0.0);
    printWithdrawMenu();
    pressAnyNumber();
    clearScreen();
}
//Print functions section
 void PrintCoffeeBoxLogo()
 {
     cout << "COFFEEBOX" << endl;
     cout << "------------------" << endl;
 }

 void printBalance()
 {
     cout << "Balance: " << currentlyDeposited << " " << CURRENCY << endl;
     cout << "------------------" << endl;
 }

 void printMainMenu()
 {
     cout << "Please, choose an option:" << endl;
     cout << "1. Insert coins" << endl;
     cout << "2. " << ESPRESSO << ": " << setw(5) << ESPRESSO_PRICE << " " << CURRENCY << endl;
     cout << "3. " << CAPPUCCINO << ": " << setw(5) << CAPPUCCINO_PRICE << " " << CURRENCY << endl;
     cout << "4. " << LATTE << ": " << setw(8) << LATTE_PRICE << " " << CURRENCY << endl;
     cout << "5. Service menu" << endl;
     cout << "------------------" << endl;
 }

void printServiceMenuLoginPage()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
    cout << "Please, enter PIN and press \"Enter\":" << endl;

    if(wrongPinEntries > 0)
    {
        cout << "WARNING! You entered wrong pin " << wrongPinEntries << " times. " << endl;
        cout << "If you enter it wrong " << wrongPinEntriesToSoftlock - wrongPinEntries << " more times, the Coffeebox will be locked." << endl;
    }

    cout << "Enter \"1\" to return to customer menu" << endl;
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

 void printCurrencyMenu()
 {
     printBalance();
     cout << "1. 2 " << CURRENCY << endl;
     cout << "2. 1 " << CURRENCY << endl;
     cout << "3. 0.5 " << CURRENCY << endl;
     cout << "4. 0.2 " << CURRENCY << endl;
     cout << "5. 0.1 " << CURRENCY << endl;
     cout << "6. Exit to Main Menu" << endl;
     cout << "------------------" << endl;
 }

 void printServiceMenuError()
 {
     cout << "Error! Use numbers from range 1 - 3" << endl;
 }


void printWithdrawMenu()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
    cout << "Withdrawing cash..." << endl;
    cout << "Cash withdrawn." << endl;
    cout << "Returning to Service Menu..." << endl;
}

//Minor service functions section
void pressAnyNumber()
{
    char holder = '\0';
    cout << "Enter any number to continue..." << endl;
    cout << "-------------------" << endl;
    cin >> holder;
}

double getAccumulatedCash()
{
    return accumulatedCash;
}

int getCupsAmount()
{
    return cups;
}

 void setAccumulatedCash(double number)
{
    accumulatedCash = number;
}

void setCupsAmount(int value)
{
     cups = value;
}

 void Sleep(int milliseconds)
 {
     std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
 }

 void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

//Errors and Exceptions section

 void notEnoughMoneyException()
 {
     printMainMenu();
     cout << "Not enough money. Please, deposit more money, if you will to buy this coffee." << endl;
     return mainMenu();
 }

 void optionOutOfRangeException()
 {
     cout << "Incorrect input. Please, enter one of the options listed below." << endl;
 }

 void outOfCupsException()
 {
     cout << "Apparently, we are out of cups." << endl << flush << "Please call customer service" << endl;
 }

 void serviceMenuLoginError()
 {
     cout << "Service Menu" << endl;
     cout << "------------------" << endl;
     cout << "Please, enter PIN and press \"Enter\":" << endl;
     cout << "Enter 1 to return to customer menu" << endl;
     cout << "------------------" << endl;
     cout << "Error! Incorrect PIN." << endl;

     if (wrongPinEntries > 0)
     {
         cout << "WARNING! You entered wrong pin " << wrongPinEntries << " times. " << endl;
         cout << "If you enter it wrong " << wrongPinEntriesToSoftlock - wrongPinEntries << " more times, the Coffeebox will be locked." << endl;
     }
 }

 void softlockCoffeebox()
 {
    while(true)
    {
        clearScreen();
        cout << "Sorry, you entered wrong PIN " << wrongPinEntriesToSoftlock << " times." << endl;
        cout << "Please call customer service, to continue using Coffeebox." << endl;
        cin.ignore();
    }
 }
