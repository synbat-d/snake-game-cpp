#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cctype>

#include "Grid.h"

bool waitForStart() {
    std::cout << "Start game? (Y/N): ";
    while (true) {
        char input = _getch();  // instantly gets keypress
        input = std::toupper(input);  // make case-insensitive

        if (input == 'Y') {
            std::cout << "Starting game...\n";
            return true;
        } else if (input == 'N') {
            std::cout << "Exiting...\n";
            return false;
        } else {
            std::cout << "\nInvalid input. Please press Y or N: ";
        }
    }
}

Worm::Direction getInputOrDefault(Worm::Direction currentDirection) {
    if (_kbhit()) {
        char ch = _getch(); // get character input (does not wait)
        switch (ch) {
            case 'w':
            case 'W':
                if (currentDirection != Worm::DOWN)
                    return Worm::UP;
                break;
            case 's':
            case 'S':
                if (currentDirection != Worm::UP)
                    return Worm::DOWN;
                break;
            case 'a':
            case 'A':
                if (currentDirection != Worm::RIGHT)
                    return Worm::LEFT;
                break;
            case 'd':
            case 'D':
                if (currentDirection != Worm::LEFT)
                    return Worm::RIGHT;
                break;
        }
    }
    return currentDirection; // default to previous if no input or invalid
}

int main() {
    Worm* worm = new Worm(5,5);
    Grid* grid = new Grid(worm);

    while (waitForStart()) {
        grid->startGrid();
        while (true) {
            Worm::Direction someDir = getInputOrDefault(worm->getDirection());
            grid->updateGrid(someDir);
            if (grid->collision) {
                std::cout << "Collision detected Game Over" << std::endl;
                break;
            }// prints the updated grid, moves worm
            Sleep(500);
        }
    }
    delete grid->worm;
    delete grid;
    Sleep(5000);
    return 0;
}
