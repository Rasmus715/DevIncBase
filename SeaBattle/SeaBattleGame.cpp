//
// Created by Ivan Zaitsev on 7/12/22.
//

#include "SeaBattleGame.h"
#include "Cell.h"
#include "iomanip"
#include <chrono>
#include <thread>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::this_thread::sleep_for;
using std::string;

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
            Hotseat();
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

    string firstPlayer = "You";
    string secondPlayer = "PC";
    PrintLogo();

    Cell** playerCells = Preset(1);
    Cell** enemyCells = Preset(1);
    int playerAliveShipCells = CalculateAliveShipCells(playerCells);
    int enemyAliveShipCells = CalculateAliveShipCells(enemyCells);

    RenderGrid("Your", secondPlayer, playerCells, enemyCells, debug);

    bool playerGoesFirst = FlipTheCoin(firstPlayer, secondPlayer);
    system("clear");

    char playerXCoordinate = 'A';
    int playerYCoordinate = 0;

    while (playerAliveShipCells > 0 or enemyAliveShipCells > 0)
    {
        RenderGrid("Your", secondPlayer, playerCells, enemyCells, debug);
        cout << endl;
        cout << "In cycle" << endl;
        if(playerGoesFirst)
        {
            cout << R"(Please, enter the X and Y coordinate, according to the format ("E 4", "A 2"))" << endl;
            cin >> playerXCoordinate >> playerYCoordinate;
            if(ShootAction(playerCells,false,playerYCoordinate, playerXCoordinate));
                enemyAliveShipCells--;
        }
        else
        {
            cout << "calling PC's ShootAction" << endl;
            bool x = ShootAction(enemyCells,true);
                playerAliveShipCells--;
        }
    }

        //ShootAction(enemyCells,)

    cin.ignore();
    cin.ignore();

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

    Cell** playerCells = Preset(1);
    Cell** enemyCells = Preset(1);


    RenderGrid(firstPlayer + "'s", secondPlayer + "'s", playerCells, enemyCells, debug, true);

    if(FlipTheCoin(firstPlayer, secondPlayer))

        cin.ignore();
    cin.ignore();

}


Cell ** SeaBattleGame::Preset(int number)
{
    Cell** result = 0;
    result = new Cell*[10];
    for(int i = 0; i < 10; i++)
    {
        result[i] = new Cell[10];
    }

    //First row
    result[0][0] = Cell(true,true,true);
    result[0][1] = Cell();
    result[0][2] = Cell(true,true,true);
    result[0][3] = Cell();
    result[0][4] = Cell();
    result[0][5] = Cell();
    result[0][6] = Cell();
    result[0][7] = Cell();
    result[0][8] = Cell();
    result[0][9] = Cell();

    //Second row
    result[1][0] = Cell();
    result[1][1] = Cell();
    result[1][2] = Cell(true,true,true);
    result[1][3] = Cell();
    result[1][4] = Cell();
    result[1][5] = Cell();
    result[1][6] = Cell();
    result[1][7] = Cell();
    result[1][8] = Cell();
    result[1][9] = Cell();

    //Third row
    result[2][0] = Cell();
    result[2][1] = Cell();
    result[2][2] = Cell(true,true,true);
    result[2][3] = Cell();
    result[2][4] = Cell();
    result[2][5] = Cell();
    result[2][6] = Cell();
    result[2][7] = Cell(true,true,true);
    result[2][8] = Cell();
    result[2][9] = Cell();

    //Fourth row
    result[3][0] = Cell();
    result[3][1] = Cell();
    result[3][2] = Cell();
    result[3][3] = Cell();
    result[3][4] = Cell();
    result[3][5] = Cell(true,true,true);
    result[3][6] = Cell();
    result[3][7] = Cell(true,true,true);
    result[3][8] = Cell();
    result[3][9] = Cell(true,true,true);

    //Fifth row
    result[4][0] = Cell();
    result[4][1] = Cell(true,true,true);
    result[4][2] = Cell();
    result[4][3] = Cell();
    result[4][4] = Cell();
    result[4][5] = Cell(true,true,true);
    result[4][6] = Cell();
    result[4][7] = Cell();
    result[4][8] = Cell();
    result[4][9] = Cell();

    //Sixth row
    result[5][0] = Cell();
    result[5][1] = Cell(true,true,true);
    result[5][2] = Cell();
    result[5][3] = Cell();
    result[5][4] = Cell();
    result[5][5] = Cell(true,true,true);
    result[5][6] = Cell();
    result[5][7] = Cell();
    result[5][8] = Cell();
    result[5][9] = Cell();

    //Seventh row
    result[6][0] = Cell();
    result[6][1] = Cell(true,true,true);
    result[6][2] = Cell();
    result[6][3] = Cell();
    result[6][4] = Cell();
    result[6][5] = Cell();
    result[6][6] = Cell();
    result[6][7] = Cell();
    result[6][8] = Cell(true,true,true);
    result[6][9] = Cell();

    //Eight row
    result[7][0] = Cell();
    result[7][1] = Cell(true,true,true);
    result[7][2] = Cell();
    result[7][3] = Cell();
    result[7][4] = Cell();
    result[7][5] = Cell();
    result[7][6] = Cell();
    result[7][7] = Cell();
    result[7][8] = Cell(true,true,true);
    result[7][9] = Cell();

    //Ninth row
    result[8][0] = Cell();
    result[8][1] = Cell();
    result[8][2] = Cell();
    result[8][3] = Cell();
    result[8][4] = Cell();
    result[8][5] = Cell();
    result[8][6] = Cell();
    result[8][7] = Cell();
    result[8][8] = Cell(true,true,true);
    result[8][9] = Cell();

    //Ninth row
    result[9][0] = Cell();
    result[9][1] = Cell();
    result[9][2] = Cell();
    result[9][3] = Cell();
    result[9][4] = Cell(true,true,true);
    result[9][5] = Cell(true,true,true);
    result[9][6] = Cell(true,true,true);
    result[9][7] = Cell();
    result[9][8] = Cell();
    result[9][9] = Cell();

    return result;
}

void SeaBattleGame::RenderGrid(string firstPlayer, string secondPlayer, Cell **playerCells, Cell **enemyCells, bool debug, bool hotseat)
{
    cout << "        " << firstPlayer << " grid                   " << secondPlayer << " grid" << "     " << endl;
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
                    cout << "_|";
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
                if (enemyCells[column][row].ship) {
                    if (enemyCells[column][row].cellState)
                        cout << "O|";
                    if (!enemyCells[column][row].cellState)
                        cout << "X|";
                } else
                    cout << "_|";
            }
        }
        else
        {
            for (int row = 0; row < 10; row++)
                if(enemyCells[column][row].fogOfWar)
                    cout << "_|";
                else {
                    if (!enemyCells[column][row].ship)
                        cout << "_|";
                    else
                        if (!enemyCells[column][row].cellState)
                            cout << "X|";
                        else
                            cout << "M|";
                }
        }
        cout << endl;
        rowNumber++;
        }

}

bool SeaBattleGame::FlipTheCoin(string firstPlayer, string secondPlayer)
{
    cout << endl << "Flipping the coin..." << endl;
    Sleep(1000);
    bool result = rand() > (RAND_MAX / 2);
    if (result)
        cout << firstPlayer <<  " goes first." << endl;
    else
        cout << secondPlayer << " goes first." << endl;
    cout << "Press \"Enter\" to continue";
    cin.ignore();
    cin.ignore();
    return result;

}

bool SeaBattleGame::ShootAction(Cell **cells, bool isPC, int yCoordinate, char xCoordinate)
{
    cout << "PC's xCoordinate:" << xCoordinate;
    cout << "PC's yCoordinate:" << yCoordinate;

    if(isPC)
    {
        bool isCellAlive = true;
        while(isCellAlive)
        {
            yCoordinate = rand() * 1.0 / RAND_MAX * (9+1);
            int xCoordinateInt = rand() * 1.0 / RAND_MAX * (9+1);
            cout << "PC's xCoordinate:" << xCoordinateInt;
            cout << "PC's yCoordinate:" << yCoordinate;
            if (!cells[xCoordinate][yCoordinate].cellState)
                isCellAlive = true;
            else
            {
                cout << "PC hit " << xCoordinateInt << " " << (char)yCoordinate;
                if(cells[xCoordinateInt][yCoordinate].ship)
                {
                    cells[xCoordinateInt][yCoordinate].cellState = false;
                    cout << " and hit your ship.";
                    return true;
                }
                cout << " and missed.";
                return false;
            }
        }
    }
    return false;
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





