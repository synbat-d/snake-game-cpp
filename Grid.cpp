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
      collision(false), food(-1, -1), collisionPlace(-1,-1)  // ✅ initialize `food` here
{
    // Constructor body is now empty or only for logic
}

Grid::Grid(Worm *worm)
: width(20), height(20), wormPart('o'), wall('#'),
  horizontalSpacesNumber(3), worm(worm),
  collision(false), food(-1, -1), collisionPlace(-1,-1)
{
}


void Grid::appearRandomFood() {
    std::set<Food> foodSet;
    WormPart * temp = this->worm->getHead();
    while (temp != nullptr) {
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

bool Grid::detectCollision() {
    int previousX = this->worm->getHead()->x;
    int previousY = this->worm->getHead()->y;
    int newX = previousX;
    int newY = previousY;
    Worm::Direction direction = this->worm->getDirection();
    if (direction == Worm::Direction::RIGHT) {
        newX += 1;
    }
    else if (direction == Worm::Direction::LEFT) {
        newX -= 1;
    }
    else if (direction == Worm::Direction::UP) {
        newY += 1;
    }
    else {
        newY -= 1;
    }
    if (newX >= width || newY >= height || newX < 0 || newY < 0) {
        indicateCollision(newX, newY);
        return true;
    }
    std::set<Food> foodSet;
    WormPart * temp = this->worm->getHead();
    if (newX == this->food.x && newY == this->food.y) {
        while (temp != NULL) {
            foodSet.insert(Food(temp->x, temp->y));
            temp = temp->next;
        }
    }
    else {
        while (temp->next != NULL) {
            foodSet.insert(Food(temp->x, temp->y));
            temp = temp->next;
        }
    }
    Food newPath(newX, newY);
    if (foodSet.contains(newPath)) {
        indicateCollision(newX, newY);
        return true;
    }
    return false;
}


bool Grid::detectEatingFood() {
    int previousX = this->worm->getHead()->x;
    int previousY = this->worm->getHead()->y;
    int newX = previousX;
    int newY = previousY;
    Worm::Direction direction = this->worm->getDirection();
    if (direction == Worm::Direction::RIGHT) {
        newX += 1;
    }
    else if (direction == Worm::Direction::LEFT) {
        newX -= 1;
    }
    else if (direction == Worm::Direction::UP) {
        newY += 1;
    }
    else {
        newY -= 1;
    }
    if (newX == this->food.x && newY == this->food.y) {
        return true;
    }
    return false;
}

void Grid::updateGrid(Worm::Direction newDirection) {
    this->worm->turn(newDirection);
    if (detectCollision()) {
        std::cout << "GAME OVER" << std::endl;
    }
    if (detectEatingFood()) {
        this->worm->grow();
        if (!this->collision) {
            appearRandomFood();
        }
    }
    else {
        this->worm->move();
    }
    printGrid();
    std::cout << std::endl;
}

void Grid::updateGrid() {
    this->updateGrid(this->worm->getDirection());
}


void Grid::startGrid() {
    this->collision = false;
    this->food = Food(-1, -1);
    this->collisionPlace = Food(-1, -1);
    appearRandomFood();
    printGrid();
    std::cout << std::endl;
}


void Grid::indicateCollision(int x, int y) {
    this->collision = true;
    int currentX = this->worm->getHead()->x;
    int currentY = this->worm->getHead()->y;
    this->collisionPlace = Food(currentX, currentY);
}


void Grid::printGrid() {
    std::cout << std::endl;
    std::cout << std::endl;
    std::string spaces = "";
    for (int i = 0; i < this->horizontalSpacesNumber-1; i++) {
        spaces += " ";
    }
    std::string wallString = std::string(1, wall) + spaces;
    std::string wormPartString = std::string(1, wormPart) + spaces;
    std::string wormFoodString = std::string(1, '*') + spaces;
    std::string freeSpace = " " + spaces;
    std::string collisionPlaceString = std::string(1, 'X') + spaces;
    std::vector<std::vector<std::string>> grid(height, std::vector<std::string>(width, freeSpace));
    WormPart *temp = this->worm->getHead();
    while (temp != nullptr) {
        grid[temp->y][temp->x] = wormPartString;
        temp = temp->next;
    }
    grid[this->food.y][this->food.x] = wormFoodString;
    if (this->collision) {
        grid[this->collisionPlace.y][this->collisionPlace.x] = collisionPlaceString;
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


