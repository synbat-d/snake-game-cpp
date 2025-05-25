//
// Created by SDulatuly on 24.05.2025.
//

#include "Grid.h"

#include <iostream>
#include <random>
#include <set>
#include <vector>
#include "Worm.h"

Grid::Grid(int width, int height, char wormPart, char wall, int horizontalSpacesNumber, Worm* worm)
    : width(width), height(height), wormPart(wormPart), wall(wall),
      horizontalSpacesNumber(horizontalSpacesNumber), worm(worm),
      collision(false), food(-1, -1)  // ✅ initialize `food` here
{
    // Constructor body is now empty or only for logic
}

void Grid::appearRandomFood() {
    std::set<Food> foodSet;
    WormPart * temp = this->worm->getHead();
    while (temp != NULL) {
        foodSet.insert(Food(temp->x, temp->y));
        temp = temp->next;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distX(0, width-1);
    std::uniform_int_distribution<> distY(0, height-1);

    Food randomFood(distX(gen), distY(gen));
    while (foodSet.contains(randomFood)) {
        randomFood = Food(distX(gen), distY(gen));
    }
    this->food = randomFood;
}



void Grid::printGrid() {
    std::string spaces = "";
    for (int i = 0; i < this->horizontalSpacesNumber-1; i++) {
        spaces += " ";
    }
    std::string wallString = std::string(1, wall) + spaces;
    std::string wormPartString = std::string(1, wormPart) + spaces;
    std::string freeSpace = " " + spaces;
    std::vector<std::vector<std::string>> grid(height, std::vector<std::string>(width, freeSpace));
    WormPart *temp = this->worm->getHead();
    while (temp != nullptr) {
        grid[temp->y][temp->x] = wormPartString;
        temp = temp->next;
    }
    for (int i=0; i<width+2; i++) {
        std::cout << wallString;
    }
    std::cout << '\n';
    for (int i=height-1; i>=0; i--) {
        std::cout << wallString;
        for (int j=0; j<width; j++) {
            std::cout << grid[i][j];
        }
        std::cout << wallString<<std::endl;
    }
    for (int i=0; i<width+2; i++) {
        std::cout << wallString;
    }
}


