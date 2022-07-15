//
// Created by Ivan Zaitsev on 7/12/22.
//

#include "SeaBattleGame.h"
#include "Cell.h"
#include "iomanip"
#include <chrono>
#include <thread>
#include <random>
#include <ctime>
#include "Preset.h"

using std::cout;
using std::endl;
using std::cin  ;
using std::setw;
using std::this_thread::sleep_for;
using std::string;
using std::default_random_engine;


void SeaBattleGame::PrintSplashScreen()
{
    PrintLogo();
    cout << "                  Press \"Enter\" key                    " << endl;
    cin.ignore();
    system("clear");
}

void SeaBattleGame::MainMenu()
{

    int option;

    PrintLogo();
    cout << "              +----------------------+                      " << endl;
    cout << "              |       Main Menu      |                      " << endl;
    cout << "              +----------------------+                      " << endl;
    cout << "              | 1. Play Singleplayer |                      " << endl;
    cout << "              +----------------------+                     " << endl;
    cout << "              | 2. Play Hot-Seat     |                     " << endl;
    cout << "              +----------------------+                     " << endl;
    cout << "              | 3.    Tutorial       |                     " << endl;
    cout << "              +----------------------+                     " << endl;
    cout << "              | 4.      Quit         |                     " << endl;
    cout << "              +----------------------+                     " << endl;

    cin >> option;

    switch(option)
    {
        case 1:
            system("clear");
            Singleplayer();
            break;
        case 2:
            system("clear");
            NotImplemented();
            //Hotseat();
            break;
        case 3:
            system("clear");
            NotImplemented();
            break;
        case 4:
            return;
        case 451:
            system("clear");
            Singleplayer(true);
            break;
        default:
            system("clear");
            NotImplemented();
            break;
    }
}

void SeaBattleGame::NotImplemented()
{
    PrintLogo();
    cout << " Sorry, this function is not implemented yet. Try again later." << endl;
    cout << endl;
    cout << "            Press \"Enter\" key to return to Main Menu      " << endl;
    cin.ignore();
    cin.ignore();
    system("clear");
    MainMenu();
}


void SeaBattleGame::PrintLogo()
{
    cout << "   _____                  ____        _   _   _          " << endl;
    cout << R"(  / ____|                |  _ \      | | | | | |        )" << endl;
    cout << " | (___   ___  __ _      | |_) | __ _| |_| |_| | ___     " << endl;
    cout << R"(  \___ \ / _ \/ _` |     |  _ < / _` | __| __| |/ _ \   )" << endl;
    cout << "  ____) |  __/ (_| |     | |_) | (_| | |_| |_| |  __/   " << endl;
    cout << R"( |_____/ \___|\__,_|     |____/ \__,_|\__|\__|_|\___|   )" << endl;
    cout << endl;
}


void SeaBattleGame::Singleplayer(bool debug)
{
    srand ( time(nullptr) );
    string firstPlayer = "You";
    string secondPlayer = "PC";
    PrintLogo();

    //Crutch to prevent generating "0" all the time
    int playerPreset = rand() * 1.0 / RAND_MAX * (3 + 1) + rand() * 1.0 / RAND_MAX * (3 + 1);
    if(playerPreset > 3)
        playerPreset = 0;

    Cell** playerCells = Preset::GenerateField(playerPreset, false);
    Cell** enemyCells = Preset::GenerateField(playerPreset, true);
    int playerAliveShipCells = CalculateAliveShipCells(playerCells);
    int enemyAliveShipCells = CalculateAliveShipCells(enemyCells);
    //cout << "playerAliveShipCells:" << playerAliveShipCells << endl;

    RenderGrid("Your", secondPlayer, playerCells, enemyCells, debug);


    bool playerGoesFirst = FlipTheCoin(firstPlayer, secondPlayer);

    system("clear");


    //Good idea to move these things to another function.
    //... Maybe another time)
    while (enemyAliveShipCells > 0 && playerAliveShipCells > 0)
    {
        cout << endl;
        //cout << "In cycle" << endl;
        //bool state = playerAliveShipCells > 0;
        //cout << "state: " << state << endl;
        bool result;

        if (playerGoesFirst)
        {
            result = ShootActionStatic("You", enemyCells, playerCells,  debug, false);
            if(result)
                enemyAliveShipCells--;
            //cout << "enemyAliveShipCells: " << enemyAliveShipCells << endl;
            cout << "Press \"Enter\" to continue" << endl;
            cin.ignore();
            cin.ignore();
            system("clear");
            while (result)
            {
                result = ShootActionStatic("You", enemyCells, playerCells , debug, false);
                if (!result)
                    break;
                enemyAliveShipCells--;
                if(enemyAliveShipCells == 0)
                    break;
                //cout << "enemyAliveShipCells: " << enemyAliveShipCells << endl;
                cout << "Press \"Enter\" to continue" << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
            }
            playerGoesFirst = false;
        }
        else
        {
            //PC's move
            //cout << "calling PC's ShootActionStatic" << endl;
            result = ShootActionStatic("Your", enemyCells, playerCells, debug, true);
            if(result)
                playerAliveShipCells--;
            //cout << "playerAliveShipCells: " << enemyAliveShipCells << endl;
            cout << "Press \"Enter\" key to continue" << endl;
            cin.ignore();
            system("clear");

            while(result)
            {
                result = ShootActionStatic("Your", enemyCells, playerCells, debug, true);
                //cout << "playerAliveShipCells: " << playerAliveShipCells << endl;
                cout << "Press \"Enter\" to continue" << endl;
                cin.ignore();
                system("clear");
                if(!result)
                    break;
                enemyAliveShipCells--;
            }


            //Player's move
            result = ShootActionStatic("You", enemyCells,playerCells,  debug, false);
            if(result)
                enemyAliveShipCells--;
            //cout << "enemyAliveShipCells: " << enemyAliveShipCells << endl;
            cout << "Press \"Enter\" to continue" << endl;
            cin.ignore();
            cin.ignore();
            system("clear");

            while (result)
            {
                result = ShootActionStatic("You", enemyCells, playerCells,  debug, false);
                cout << "Press \"Enter\" to continue" << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                if(!result)
                    break;
                enemyAliveShipCells--;
                //cout << "enemyAliveShipCells: " << enemyAliveShipCells << endl;
                cout << "Press \"Enter\" to continue" << endl;
                if(enemyAliveShipCells == 0)
                    break;
            }
        }
    }

    Preset::DestroyField(playerCells);
    Preset::DestroyField(enemyCells);
    PrintLogo();
    cout << "Game Over!" << endl;
    if(enemyAliveShipCells == 0)
        cout << firstPlayer << " won!" << endl;
    else
        cout << secondPlayer << " won!" << endl;

        //ShootAction(enemyCells,)
    cout << "Press \"Enter\" key to return to Main Menu" << endl;
    cin.ignore();

    MainMenu();
}

void SeaBattleGame::Hotseat(bool debug)
{
    string firstPlayer;
    string secondPlayer;
    PrintLogo();

    cout << "Please, enter the first player's name: ";
    cin >> firstPlayer;
    cout << "Roger, " << firstPlayer <<"!" << endl;
    cout << "Now, enter the second player's name: ";
    cin >> secondPlayer;
    cout << "Awesome, " << secondPlayer << endl;

    Cell** playerCells = Preset::GenerateField(1,false);
    Cell** enemyCells = Preset::GenerateField(1,true);


    RenderGrid(firstPlayer + "'s", secondPlayer + "'s", playerCells, enemyCells, debug, true);

    if(FlipTheCoin(firstPlayer, secondPlayer))
        cin.ignore();
    cin.ignore();

}

void SeaBattleGame::RenderGrid(string firstPlayer, string secondPlayer, Cell **playerCells, Cell **enemyCells, bool debug, bool hotseat)
{
    cout << "        " << firstPlayer << " grid                      " << secondPlayer << " grid" << "     " << endl;
    cout << "    ";
    for (int column = 1; column <= 10; column++)
        cout << column << " ";
    cout << "        ";
    for (int column = 1; column <= 10; column++)
        cout << column << " ";
    cout << endl;

    cout << "    ___________________          ___________________" << endl;

    int rowNumber = 65;
    for (int column = 0; column < 10; column++)
    {
        cout << setw(2) << char(rowNumber) << " |";
        if(!hotseat)
        {
            for (int row = 0; row < 10; row++)
            {
                if(playerCells[column][row].ship)
                {
                    if (playerCells[column][row].cellState)
                        cout << "O|";
                    if (!playerCells[column][row].cellState)
                        cout << "X|";
                }
                else
                {
                    if (playerCells[column][row].cellState)
                        cout << "_|";
                    if (!playerCells[column][row].cellState)
                        cout << "M|";
                }
            }
        }
        else
        {
            for (int row = 0; row < 10; row++)
                if (!enemyCells[column][row].cellState)
                    cout << "X|";
                else
                    cout << "_|";
        }
        cout << "     " ;
        cout << setw(2) << char(rowNumber) << " |";
        if(debug)
        {
            for (int row = 0; row < 10; row++) {
                if (enemyCells[column][row].ship)
                {
                    if (enemyCells[column][row].cellState)
                        cout << "O|";
                    if (!enemyCells[column][row].cellState)
                        cout << "X|";
                }
                else
                {
                    if (enemyCells[column][row].cellState)
                        cout << "_|";
                    if (!enemyCells[column][row].cellState)
                        cout << "M|";
                }
            }
        }
        else
        {
            for (int row = 0; row < 10; row++)
                    if (!enemyCells[column][row].fogOfWar)
                    {
                        if (enemyCells[column][row].ship)
                        {
                            if (!enemyCells[column][row].cellState)
                                cout << "X|";
                        }
                        else
                            if (!enemyCells[column][row].cellState)
                                cout << "M|";
                    }
                    else
                        cout << "_|";
        }

        cout << endl;
        rowNumber++;
        }
    cout << endl;
}

bool SeaBattleGame::ShootActionStatic(string firstPlayer, Cell **enemyCells, Cell **playerCells, bool debug, bool isPC)
{
    int yCoordinate = 0;

    if(isPC)
    {
        bool isCellAlive = true;
        while(isCellAlive)
        {
            yCoordinate = rand() * 1.0 / RAND_MAX * (9+1);
            int xCoordinateInt = rand() * 1.0 / RAND_MAX * (9+1);
            //cout << "PC's xCoordinateInt:" << xCoordinateInt << endl;
            //cout << "PC's yCoordinate:" << yCoordinate << endl;
            if (!playerCells[xCoordinateInt][yCoordinate].cellState)
            {
                //cout << "PC shot " << char(xCoordinateInt + 65) << " " << yCoordinate << endl;
                //cout << "and hit cell with already false cellState" << endl;
                isCellAlive = true;
            }
            else
            {
                playerCells[xCoordinateInt][yCoordinate].fogOfWar = false;
                playerCells[xCoordinateInt][yCoordinate].cellState = false;
                PrintLogo();
                RenderGrid("Your", "PC", playerCells, enemyCells, debug);
                cout << "PC hit " << char(xCoordinateInt + 65) << " " << yCoordinate + 1;
                if(playerCells[xCoordinateInt][yCoordinate].ship)
                {
                    cout << " and damaged your ship." << endl;
                    return true;
                }
                else
                {
                    cout << " and missed." << endl;
                    return false;
                }
            }
        }
    }
    else
    {
        char xCoordinateChar = 'A';
        int x = int(xCoordinateChar - 65);

        PrintLogo();
        RenderGrid("Your", "PC", playerCells, enemyCells, debug);

        yCoordinate = 0;

        //Too bad I can't use recursive call here whatsoever
        cout << R"(Please, enter the X and Y coordinate, according to the format ("E 4", "A 2"))" << endl;
        scanf("%s %d", &xCoordinateChar, &yCoordinate);
        //cout << "xCoordinateChar: " << xCoordinateChar << endl;
        //cout << "xCoordinateChar after conversion: " << int(xCoordinateChar - 65) << endl;
        //cout << "yCoordinate: " << yCoordinate << endl;
        x = int(xCoordinateChar - 65);

        while (x > 9 or x < 0 or yCoordinate > 10 or yCoordinate < 1)
        {
            system("clear");
            cout << "Please, enter the valid coordinates" << endl;
            PrintLogo();
            RenderGrid("Your", "PC", playerCells, enemyCells, debug);
            cout << R"(Please, enter the X and Y coordinate, according to the format ("E 4", "A 2"))" << endl;
            scanf("%s %d", &xCoordinateChar, &yCoordinate);
            //cout << "xCoordinateChar: " << xCoordinateChar << endl;
            //cout << "xCoordinateChar after conversion: " << int(xCoordinateChar - 65) << endl;
            //cout << "yCoordinate: " << yCoordinate << endl;
            x = int(xCoordinateChar - 65);
        }


        yCoordinate--;
        if(!enemyCells[x][yCoordinate].cellState)
        {
            system("clear");
            cout << "This cell is already damaged. Please, enter the coordinates of another cell" << endl;
            ShootActionStatic("You", enemyCells, playerCells, debug, false);
        }

        enemyCells[x][yCoordinate].cellState = false;
        enemyCells[x][yCoordinate].fogOfWar = false;
        if(enemyCells[x][yCoordinate].ship)
        {
            PrintLogo();
            RenderGrid("Your", "PC", playerCells, enemyCells, debug);
            cout << "You hit the ship!" << endl;
            return true;
        }
        else
        {
            PrintLogo();
            RenderGrid("Your", "PC", playerCells, enemyCells, debug);
            cout << "You missed :(" << endl;
            return false;
        }
    }

    //Returning false just to shut up warning on cmake build
    return false;
}


bool SeaBattleGame::FlipTheCoin(string firstPlayer, string secondPlayer)
{
    cout << endl << "Flipping the coin..." << endl;
    Sleep(1000);
    bool result = rand() <= (RAND_MAX / 2);
    if (result)
        cout << firstPlayer <<  " go first." << endl;
    else
        cout << secondPlayer << " goes first." << endl;
    cout << "Press \"Enter\" to continue";
    cin.ignore();
    cin.ignore();
    return result;
}



void SeaBattleGame::Sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int SeaBattleGame::CalculateAliveShipCells(Cell **cells)
{
    int result = 0;
    for (int column = 0; column < 10; column++)
        for (int row = 0; row < 10; row++)
            if (cells[column][row].ship and cells[column][row].cellState)
                result++;
    return result;
}





