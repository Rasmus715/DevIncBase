#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void PrintCoffeeBoxLogo();
void mainMenu();
void mainMenuOutOfRangeException();
void cookCoffee(tuple<double,string> coffee);
void cookCoffeeOutOfRangeException();
void cookCoffeeSugarMenu();
void Sleep(int milliseconds);
void cookCoffeeProgressBar();
void cookCoffeeCurrencyMenu(tuple<double,string> coffee);

const string CURRENCY = "BYN";
const tuple<double,string> ESPRESSO = make_tuple(3, "Espresso");
const tuple<double,string> CAPPUCCINO = make_tuple(2.5, "Cappuccino");
const tuple<double,string> LATTE = make_tuple(2, "Latte");
const int MAX_CUPS = 700;
const int INITIAL_CUPS = 7;
const int MAX_SUGAR_PER_CUP = 2;
double currentlyDeposited = 0.0;
int currentSugarAmount = 0;
int cups = INITIAL_CUPS;

int main()
{
    PrintCoffeeBoxLogo();
    mainMenu();
    return  0;
}

void PrintCoffeeBoxLogo()
{
    cout << "COFFEEBOX" << endl;
}

void mainMenu() {
    int option = 0;


    cout << "Please, choose an option:" << endl;
    cout << "1. " << get<1>(ESPRESSO) << ": " << get<0>(ESPRESSO) << " " << CURRENCY << endl;
    cout << "2. " << get<1>(CAPPUCCINO) << ": " << get<0>(CAPPUCCINO) << " " << CURRENCY << endl;
    cout << "3. " << get<1>(LATTE) << ": " << get<0>(LATTE) << " " << CURRENCY << endl;
    cout << "4. Service menu" << endl;
    cout << "5. Exit" << endl;

    cin >> option;

    switch (option) {
        case 1:
            system("clear");
            PrintCoffeeBoxLogo();
            cookCoffee(ESPRESSO);
            break;
        case 2:
            system("clear");
            PrintCoffeeBoxLogo();
            cookCoffee(CAPPUCCINO);
            break;
        case 3:
            system("clear");
            PrintCoffeeBoxLogo();
            cookCoffee(LATTE);
            break;
        case 5:
            return;
        default:
            system("clear");
            PrintCoffeeBoxLogo();
            mainMenuOutOfRangeException();
            return mainMenu();
    }
}

void mainMenuOutOfRangeException()
{
    cout << "Incorrect input. Please, enter one of the options listed below." << endl;
}

void outOfCupsException()
{
    cout << "Apparently, we are out of cups." << endl << flush << "Please call customer service" << endl;
}


void cookCoffee(tuple<double,string> coffee)
{

    if(cups == 0)
    {
        system("clear");
        PrintCoffeeBoxLogo();
        outOfCupsException();
        cout << "cups: " << cups;
        Sleep(10000);
        system("clear");
        return mainMenu();
    }


    cookCoffeeCurrencyMenu(coffee);
    int option = 0;
    cin >> option;
    switch(option)
    {
        case 1:
            currentlyDeposited += 5;
            break;
        case 2:
            currentlyDeposited += 2;
            break;
        case 3:
            currentlyDeposited += 1;
            break;
        case 4:
            currentlyDeposited += 0.5;
            break;
        case 5:
            currentlyDeposited += 0.2;
            break;
        case 6:
            currentlyDeposited += 0.1;
            break;
        case 7:
            system("clear");
            PrintCoffeeBoxLogo();
            return mainMenu();
        default:
            system("clear");
            PrintCoffeeBoxLogo();
            cookCoffeeOutOfRangeException();
            return cookCoffee(coffee);
    }

    system("clear");

    while(currentlyDeposited < get<0>(coffee))
        cookCoffee(coffee);

    cookCoffeeSugarMenu();
    system("clear");
    PrintCoffeeBoxLogo();
    cout << "Your coffee is being prepared, please wait a bit..." << endl;
    cookCoffeeProgressBar();
    cout << endl;
    cout << "Now, take your " << get<1>(coffee) << "." << endl;
    cout << "Have a nice day!" << endl;
    Sleep(5000);
    system("Clear");
    currentlyDeposited = 0.0;
    currentSugarAmount = 0.0;
    cups--;
    return mainMenu();
}

void cookCoffeeCurrencyMenu(tuple<double,string> coffee)
{
    cout << "Please, deposit " << get<0>(coffee) << " " << CURRENCY << endl;
    cout << "Currently deposited: " <<  currentlyDeposited << " " << CURRENCY << endl;
    cout << "1. 5 " <<  CURRENCY << endl;
    cout << "2. 2 " <<  CURRENCY << endl;
    cout << "3. 1 " <<  CURRENCY << endl;
    cout << "4. 0.5 " <<  CURRENCY << endl;
    cout << "5. 0.2 " <<  CURRENCY << endl;
    cout << "6. 0.1 " <<  CURRENCY << endl;
    cout << "7. Exit to Main Menu" << endl;
}

void cookCoffeeOutOfRangeException()
{
    cout << "There is no such option. Please, enter valid option" << endl;
}

void cookCoffeeSugarMenu()
{
    cout << "Enter, how many sugar do you want? (Max. " << MAX_SUGAR_PER_CUP <<"): ";
    cin >> currentSugarAmount;

    if(currentSugarAmount > MAX_SUGAR_PER_CUP)
    {
        system("clear");
        cout << "Incorrect amount of sugar." << endl;
        cookCoffeeSugarMenu();
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

void Sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


