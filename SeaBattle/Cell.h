//
// Created by Ivan Zaitsev on 7/13/22.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H


class Cell {
public:
    bool fogOfWar = true;
    bool ship = false;
    bool cellState = true;
    Cell(bool fogOfWar = false, bool ship = false, bool cellState = true) : fogOfWar(fogOfWar), ship(ship), cellState(cellState) {};
};


#endif //UNTITLED_CELL_H
