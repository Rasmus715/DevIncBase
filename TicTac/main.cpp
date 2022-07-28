#include "iostream"

using namespace std;

void renderGrid(int[]);
int decidePlayerFigure();
void clearScreen();
void printScore(int gameNumber);
void makeAMove(bool isPC, bool pcGoesFirstFlag, bool pcOpenings[], int gameNumber);
bool checkWinCondition(int figure);
bool checkFreeCells(int cells);
void ticTacGame(bool playerGoesFirstFlag, int freeCells, bool pcOpenings[], bool playersOpenings[], int gameNumber);
void clearGrid();

const int EMPTY = 0;
const int CIRCLE = 1;
const int CROSS = 2;
int playerFigure = 0;
int pcFigure = 0;
int pcScore = 0;
int playerScore = 0;
int grid[9] = {0,0,0,0,0,0,0,0,0};

int main()
{
    bool pcOpenings[8] = {false};
    bool playersOpenings[8] = {false};
    int gameNumber = 1;

    while(gameNumber <= 8)
    {
        if(gameNumber == 1)
        {
            playerFigure = decidePlayerFigure();
            if (playerFigure == CIRCLE)
                pcFigure = CROSS;
            else
                pcFigure = CIRCLE;
        }

        clearScreen();
        printScore(gameNumber);
        renderGrid(grid);

        bool playerGoesFirstFlag = false;
        if(playerFigure == CROSS)
            playerGoesFirstFlag = true;
        int freeCells = 9;

        ticTacGame(playerGoesFirstFlag, freeCells, pcOpenings, playersOpenings, gameNumber);

        if(gameNumber == 8)
        {
            clearScreen();
            printScore(gameNumber);
            cout << "Game over!" << endl;
            if (pcScore > playerScore)
                cout << "PC won." << endl;
            if (pcScore == playerScore)
                cout << "Draw." << endl;
            if (playerScore > pcScore)
                cout << "You won! Congratulations :D" << endl;
            cout << "Press \"Enter\" key to exit..." << endl;
            cin.ignore();
            break;
        }

        clearGrid();
        clearScreen();
        printScore(gameNumber);

        if(gameNumber == 4)
        {
            clearScreen();
            printScore(gameNumber);
            renderGrid(grid);
            cout << "Switching figures..." << endl;
            cout << "Now you're playing: ";

            if (playerFigure == CIRCLE)
            {
                playerFigure = CROSS;
                pcFigure = CIRCLE;
            }
            else
            {
                playerFigure = CIRCLE;
                pcFigure = CROSS;
            }

            if(playerFigure == CROSS)
                cout << "Crosses" << endl;
            else
                cout << "Circles" << endl;
            cout << "Press \"Enter\" key to continue..." << endl;
            cin.ignore();
        }
        gameNumber++;
    }

}

void printScore(int gameNumber)
{
    cout << "Game " << gameNumber << endl;
    cout << "You: " << playerScore << " VS PC: " << pcScore << endl;
}

void ticTacGame(bool playerGoesFirstFlag, int freeCells, bool pcOpenings[], bool playersOpenings[], int gameNumber)
{
    bool pcGoesFirstFlag = playerGoesFirstFlag ? false : true;

    do
    {
        if (playerGoesFirstFlag)
        {
            makeAMove(false, playerGoesFirstFlag, playersOpenings, gameNumber);
            clearScreen();
            printScore(gameNumber);
            renderGrid(grid);
            playerGoesFirstFlag = false;
            freeCells--;
        }

        makeAMove(true, pcGoesFirstFlag, pcOpenings, gameNumber);
        if(pcGoesFirstFlag)
            pcGoesFirstFlag = false;
        clearScreen();
        printScore(gameNumber);
        renderGrid(grid);
        freeCells--;
        if (checkFreeCells(freeCells))
        {
            cout << "Draw." << endl;
            cout << "Press \"Enter\" key to continue..." << endl;
            pcScore += 1;
            playerScore += 1;
            cin.ignore();
            cin.ignore();
            break;
        }
        if (checkWinCondition(pcFigure))
        {
            cout << "PC won!" << endl;
            cout << "Press \"Enter\" key to continue..." << endl;
            pcScore += 3;
            cin.ignore();
            cin.ignore();
            break;
        }

        makeAMove(false, pcGoesFirstFlag, playersOpenings, gameNumber);
        clearScreen();
        printScore(gameNumber);
        renderGrid(grid);
        freeCells--;
        if (checkFreeCells(freeCells))
        {
            cout << "Draw." << endl;
            cout << "Press \"Enter\" key to continue..." << endl;
            pcScore += 1;
            playerScore += 1;
            cin.ignore();
            cin.ignore();
            break;
        }

        if (checkWinCondition(playerFigure))
        {
            cout << "Yon won! That's impossible...";
            cout << "Press \"Enter\" key to continue...";
            playerScore += 3;
            cin.ignore();
            cin.ignore();
            break;
        }
    } while (freeCells > 0);
}

void renderGrid(int array[])
{
    cout << "Numeration of cells: " << endl;
    cout << " _____" << endl;
    for (int i = 0; i < 9; i++)
    {
        int j = i;
        while (j < i + 3)
        {
            if (j % 3 == EMPTY)
                cout << "|";
            cout << j + 1 << "|";
            j++;
        }
        i = j - 1;
        cout << endl;
    }
    cout << endl;

    cout << "Current game grid: " << endl;
    cout << " _____" << endl;
    for (int i = 0; i < 9; i++)
    {
        int j = i;
        while (j < i + 3)
        {
            if(j % 3 == EMPTY)
                cout << "|";
            if (array[j] == CIRCLE)
                cout << "0|";
            else
                if(array[j] == CROSS)
                    cout << "X|";
                else
                    cout << "_|";
            j++;
        }
        i = j - 1;
        cout << endl;
    }
    cout << endl;
}

int decidePlayerFigure()
{
    int option = 0;
    do
    {
        cout << "Please, enter the figure you want to play:" << endl;
        cout << "1. Circles" << endl << "2. Crosses" << endl;
        cin >> option;
        if(option < 1 || option > 2)
        {
            clearScreen();
            cout << "Please, enter valid option." << endl;
        }
    }
    while (option < 1 || option > 2);
    return option;
}

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void makeAMove(bool isPC, bool pcGoesFirstFlag, bool openings[], int gameNumber)
{
    if (!isPC)
    {
        int option;
        do
        {
            cout << "Please, enter the number of cell, according to numeration above: ";
            cin >> option;
            if (option > 9 || option < 1)
            {
                clearScreen();
                printScore(gameNumber);
                renderGrid(grid);
                cout << "Please, enter the valid number of cell." << endl;
            }
            else if (grid[option - 1] != EMPTY)
            {
                clearScreen();
                printScore(gameNumber);
                renderGrid(grid);
                cout << "This cell is already occupied. Please, choose another cell." << endl;
            }

            else if (pcGoesFirstFlag && openings[option - 1])
            {
                clearScreen();
                printScore(gameNumber);
                renderGrid(grid);
                cout << "You played this cell in another opening. Try another cell." << endl;
            }

        }
        while ((option > 9 || option < 1) || grid[option - 1] != EMPTY || (pcGoesFirstFlag && openings[option - 1]));

        if(pcGoesFirstFlag)
            openings[option - 1] = true;

        grid[option - 1] = playerFigure;
    }
    else
    {
        //PCs algorithm

        //Win condition paths
        //Horizontal
        //Row 1
        if (grid[0] == pcFigure && grid[1] == pcFigure && grid[1] == EMPTY)
            grid[2] = pcFigure;
        else if (grid[0] == pcFigure && grid[2] == pcFigure && grid[1] == EMPTY)
            grid[1] = pcFigure;
        else if (grid[1] == pcFigure && grid[2] == pcFigure && grid[0] == EMPTY)
            grid[0] = pcFigure;

        //Row 2
        else if (grid[3] == pcFigure && grid[4] == pcFigure && grid[5] == EMPTY)
            grid[5] = pcFigure;
        else if (grid[4] == pcFigure && grid[5] == pcFigure && grid[3] == EMPTY)
            grid[3] = pcFigure;
        else if (grid[3] == pcFigure && grid[5] == pcFigure && grid[4] == EMPTY)
            grid[4] = pcFigure;

        //Row 3
        else if (grid[6] == pcFigure && grid[7] == pcFigure && grid[8] == EMPTY)
            grid[8] = pcFigure;
        else if (grid[7] == pcFigure && grid[8] == pcFigure && grid[6] == EMPTY)
            grid[6] = pcFigure;
        else if (grid[6] == pcFigure && grid[8] == pcFigure && grid[7] == EMPTY)
            grid[7] = pcFigure;

        //Vertical
        //Column 1
        else if (grid[0] == pcFigure && grid[3] == pcFigure && grid[6] == EMPTY)
            grid[6] = pcFigure;
        else if (grid[0] == pcFigure && grid[6] == pcFigure && grid[3] == EMPTY)
            grid[3] = pcFigure;
        else if (grid[3] == pcFigure && grid[6] == pcFigure && grid[0] == EMPTY)
            grid[0] = pcFigure;

        //Column 2
        else if (grid[1] == pcFigure && grid[4] == pcFigure && grid[7] == EMPTY)
            grid[7] = pcFigure;
        else if (grid[1] == pcFigure && grid[7] == pcFigure && grid[4] == EMPTY)
            grid[4] = pcFigure;
        else if (grid[4] == pcFigure && grid[7] == pcFigure && grid[1] == EMPTY)
            grid[1] = pcFigure;

        //Column 3
        else if (grid[2] == pcFigure && grid[5] == pcFigure && grid[8] == EMPTY)
            grid[8] = pcFigure;
        else if (grid[2] == pcFigure && grid[8] == pcFigure && grid[5] == EMPTY)
            grid[5] = pcFigure;
        else if (grid[5] == pcFigure && grid[8] == pcFigure && grid[2] == EMPTY)
            grid[2] = pcFigure;

        //Diagonal
        else if (grid[0] == pcFigure && grid[4] == pcFigure && grid[8] == EMPTY)
            grid[8] = pcFigure;
        else if (grid[0] == pcFigure && grid[8] == pcFigure && grid[4] == EMPTY)
            grid[4] = pcFigure;
        else if (grid[2] == pcFigure && grid[4] == pcFigure && grid[6] == EMPTY)
            grid[6] = pcFigure;

        //Defensive

        //Horizontal
        //1st row
        else
        if(grid[0] == playerFigure && grid[1] == playerFigure && grid[2] == EMPTY)
            grid[2] = pcFigure;
        else if(grid[1] == playerFigure && grid[2] == playerFigure && grid[0] == EMPTY)
                grid[0] = pcFigure;
        else if(grid[2] == playerFigure && grid[0] == playerFigure && grid[1] == EMPTY)
                grid[1] = pcFigure;

        //2nd row
        else if (grid[3] == playerFigure && grid[4] == playerFigure && grid[5] == EMPTY)
            grid[5] = pcFigure;
        else if (grid[4] == playerFigure && grid[5] == playerFigure && grid[3] == EMPTY)
            grid[3] = pcFigure;
        else if (grid[3] == playerFigure && grid[5] == playerFigure && grid[4] == EMPTY)
            grid[4] = pcFigure;

        //3rd row
        else if (grid[6] == playerFigure && grid[7] == playerFigure && grid[8] == EMPTY)
            grid[8] = pcFigure;
        else if (grid[7] == playerFigure && grid[8] == playerFigure && grid[6] == EMPTY)
            grid[6] = pcFigure;
        else if (grid[6] == playerFigure && grid[8] == playerFigure && grid[7] == EMPTY)
            grid[7] = pcFigure;

        //Vertical
        //1st column
        else if (grid[0] == playerFigure && grid[3] == playerFigure && grid[6] == EMPTY)
            grid[6] = pcFigure;
        else if (grid[3] == playerFigure && grid[6] == playerFigure && grid[0] == EMPTY)
            grid[0] = pcFigure;
        else if (grid[3] == playerFigure && grid[0] == playerFigure && grid[3] == EMPTY)
            grid[3] = pcFigure;

        //2nd column
        else if (grid[1] == playerFigure && grid[4] == playerFigure && grid[7] == EMPTY)
            grid[7] = pcFigure;
        else if (grid[4] == playerFigure && grid[7] == playerFigure && grid[1] == EMPTY)
            grid[1] = pcFigure;
        else if (grid[7] == playerFigure && grid[1] == playerFigure && grid[4] == EMPTY)
            grid[4] = pcFigure;

        //3rd column
        else if (grid[2] == playerFigure && grid[5] == playerFigure && grid[8] == EMPTY)
            grid[8] = pcFigure;
        else if (grid[5] == playerFigure && grid[8] == playerFigure && grid[2] == EMPTY)
            grid[2] = pcFigure;
        else if (grid[8] == playerFigure && grid[2] == playerFigure && grid[5] == EMPTY)
            grid[5] = pcFigure;

        //Diagonal
        //1-5-9
        else if (grid[0] == playerFigure && grid[4] == playerFigure && grid[8] == EMPTY)
            grid[8] = pcFigure;
        else if (grid[0] == playerFigure && grid[8] == playerFigure && grid[4] == EMPTY)
            grid[4] = pcFigure;
        else if (grid[4] == playerFigure && grid[8] == playerFigure && grid[0] == EMPTY)
            grid[0] = pcFigure;

        //3-5-7
        else if (grid[2] == playerFigure && grid[4] == playerFigure && grid[6] == EMPTY)
            grid[6] = pcFigure;
        else if (grid[2] == playerFigure && grid[6] == playerFigure && grid[4] == EMPTY)
            grid[4] = pcFigure;
        else if (grid[4] == playerFigure && grid[6] == playerFigure && grid[2] == EMPTY)
            grid[2] = pcFigure;

        //Offensive
        //First move states here.
        //The PC will try to get center(4) cell, then the corner cells
        //if PC goes first, the pcOpenings array fills with "true" value according to cell
        else if(pcGoesFirstFlag)
        {
            if (!openings[4])
            {
                grid[4] = pcFigure;
                openings[4] = true;
            }
            else if (!openings[0])
            {
                grid[0] = pcFigure;
                openings[0] = true;
            }
            else if(!openings[6])
            {
                grid[6] = pcFigure;
                openings[6] = true;
            }
            else if (!openings[2])
            {
                grid[2] = pcFigure;
                openings[2] = true;
            }

            else if(!openings[3])
            {
                grid[3] = pcFigure;
                openings[3] = true;
            }

            else if(!openings[5])
            {
                grid[5] = pcFigure;
                openings[5] = true;
            }
            else if(!openings[1])
            {
                grid[1] = pcFigure;
                openings[1] = true;
            }
            else if(!openings[7])
            {
                grid[7] = pcFigure;
                openings[7] = true;
            }
            else if(!openings[8])
            {
                grid[8] = pcFigure;
                openings[8] = true;
            }
        }
        else if (grid[4] == EMPTY)
            grid[4] = pcFigure;
        else if (grid[0] == EMPTY)
            grid[0] = pcFigure;
        else if(grid[6] == EMPTY)
            grid[6] = pcFigure;
        else if (grid[2] == EMPTY)
            grid[2] = pcFigure;
        else if (grid[8] == EMPTY)
            grid[8] = pcFigure;

        //Less favorable moves
        else if(grid[3] == EMPTY)
            grid[3] = pcFigure;
        else if(grid[5] == EMPTY)
            grid[5] = pcFigure;
        else if(grid[1] == EMPTY)
            grid[1] = pcFigure;
        else if(grid[7] == EMPTY)
            grid[7] = pcFigure;
    }
}

bool checkWinCondition(int figure)
{
    //Horizontal lines
    if(grid[0] == figure && grid[1] == figure && grid[2] == figure)
        return true;
    if(grid[3] == figure && grid[4] == figure && grid[5] == figure)
        return true;
    if(grid[6] == figure && grid[7] == figure && grid[8] == figure)
        return true;

    //Vertical lines
    if(grid[0] == figure && grid[3] == figure && grid[6] == figure)
        return true;
    if(grid[1] == figure && grid[4] == figure && grid[7] == figure)
        return true;
    if(grid[2] == figure && grid[5] == figure && grid[8] == figure)
        return true;

    //Diagonal lines
    if(grid[2] == figure && grid[4] == figure && grid[6] == figure)
        return true;
    if(grid[0] == figure && grid[4] == figure && grid[8] == figure)
        return true;

    return false;
}

bool checkFreeCells(int cells)
{
    if(cells == EMPTY)
        return true;
    return false;
}

void clearGrid()
{
    for(int i = 0; i < 9; i++)
        grid[i] = 0;
}
