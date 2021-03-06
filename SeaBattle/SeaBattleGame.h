//
// Created by Ivan Zaitsev on 7/12/22.
//

#ifndef UNTITLED_SEABATTLEGAME_H
#define UNTITLED_SEABATTLEGAME_H

#include <iostream>
#include "Cell.h"

using std::string;

class SeaBattleGame {

public:
    void PrintSplashScreen();
    void MainMenu();
    void NotImplemented();
    static void PrintLogo();
    void Singleplayer(bool debug = false);
    void Hotseat(bool debug = false);
    static void RenderGrid(string firstPlayer, string secondPlayer, Cell **playerCells, Cell **enemyCells, bool debug = false, bool hotseat = false);
    int CalculateAliveShipCells(Cell **cells);
    bool FlipTheCoin(string firstPlayer, string secondPlayer);
    bool ShootActionStatic(string firstPlayer, Cell **enemyCells, Cell **playerCells, bool debug = false, bool isPC = false);


    void Sleep(int milliseconds);
};

#endif //UNTITLED_SEABATTLEGAME_H
