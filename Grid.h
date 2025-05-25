//
// Created by SDulatuly on 24.05.2025.
//

#ifndef GRID_H
#define GRID_H
#include "Food.h"
#include "Worm.h"
#include "WormPart.h"


class Grid {
public:
    Worm* worm;
    bool collision;

    Grid(int width, int height, char wormPart, char wall, int horizontalSpacesNumber, Worm* worm);
    Grid(Worm* worm);
    void printGrid();
    void updateGrid(Worm::Direction newDirection);
    void startGrid();
    void updateGrid();
private:
    int width;
    int height;
    char wormPart;
    char wall;
    int horizontalSpacesNumber;
    Food food;
    Food collisionPlace;

    void appearRandomFood();
    bool detectCollision();
    bool detectEatingFood();
    void indicateCollision(int x, int y);
};



#endif //GRID_H
