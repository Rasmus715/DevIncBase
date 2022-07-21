#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

//Ivan methods
void PrintCoffeeBoxLogo();
void mainMenu();
void printMainMenu();
void printCurrencyMenu();
void mainMenuOutOfRangeException();
void cookCoffee(string coffee, double price);
void cookCoffeeOutOfRangeException();
void Sleep(int milliseconds);
void cookCoffeeProgressBar();
void currencyMenu();
void notEnoughMoneyException();
void printBalance();
void outOfCupsException();
void execute();
void clearScreen();

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
const int PIN = 1234;
double currentlyDeposited = 0.0;
int cups = INITIAL_CUPS;
double accumulatedCash = 0.0;


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
            printBalance();
            cookCoffee(ESPRESSO, ESPRESSO_PRICE);
            break;
        case 2:
            clearScreen();
            printBalance();
            cookCoffee(CAPPUCCINO, CAPPUCCINO_PRICE);
            break;
        case 3:
            clearScreen();
            printBalance();
            cookCoffee(LATTE, LATTE_PRICE);
            break;
        case 4:
            clearScreen();
            printCurrencyMenu();
            currencyMenu();
        case 5:
            clearScreen();
            serviceMenu();
        case 6:
            return;
        default:
            clearScreen();
            printBalance();
            printMainMenu();
            mainMenuOutOfRangeException();
            return mainMenu();
    }
}

void cookCoffee(string coffee, double price)
{
    if(cups == 0)
    {
        clearScreen();
        PrintCoffeeBoxLogo();
        outOfCupsException();
        cout << "cups: " << cups;
        Sleep(10000);
        clearScreen();
        printMainMenu();
        return mainMenu();
    }

    if(currentlyDeposited < price)
        return notEnoughMoneyException();

    clearScreen();

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
            cookCoffeeOutOfRangeException();
            return currencyMenu();
    }
}

void cookCoffeeProgressBar()
{
    double progress = 0.0;
    int isDone = false;
    while (progress <= 1.0)
    {
        int barWidth = 60;

        cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i)
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

        if(isDone)
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
            clearScreen();
            startServiceMenu();
            break;
        } else if (pinEntered == escapeSymbol) {
            clearScreen();
            printMainMenu();
            return mainMenu();
        } else {
            cout << "\n";
            clearScreen();
            serviceMenuLoginError();
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
//Print functions section
 void PrintCoffeeBoxLogo()
 {
     cout << "COFFEEBOX" << endl;
     cout << "------------------" << endl;
 }

 void printBalance()
 {
     cout << "Balance: " << currentlyDeposited << endl;
     cout << "------------------" << endl;
 }

 void printMainMenu()
 {
     cout << "Please, choose an option:" << endl;
     cout << "1. " << ESPRESSO << ": " << ESPRESSO_PRICE << " " << CURRENCY << endl;
     cout << "2. " << CAPPUCCINO << ": " << CAPPUCCINO_PRICE << " " << CURRENCY << endl;
     cout << "3. " << LATTE << ": " << LATTE_PRICE << " " << CURRENCY << endl;
     cout << "4. Insert coins" << endl;
     cout << "5. Service menu" << endl;
     cout << "6. Exit" << endl;
     cout << "------------------" << endl;
 }

void printServiceMenuLoginPage()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
    cout << "Please, enter PIN and press \"Enter\":" << endl;
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
    for(int i = 0; i < 40; i++)
    {
        cout << endl;
    }
}

//Errors and Exceptions section
 void cookCoffeeOutOfRangeException()
 {
     cout << "There is no such option. Please, enter valid option" << endl;
 }

 void notEnoughMoneyException()
 {
     printMainMenu();
     cout << "Not enough money. Please, deposit more money, if you will to buy this coffee." << endl;
     return mainMenu();
 }

 void mainMenuOutOfRangeException()
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
 }

