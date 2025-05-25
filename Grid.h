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
    void printGrid();
private:
    int width;
    int height;
    char wormPart;
    char wall;
    int horizontalSpacesNumber;
    Food food;

    void appearRandomFood();
    void detectCollision();
    void detectEatingFood();
};



#endif //GRID_H
