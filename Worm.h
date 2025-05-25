//
// Created by SDulatuly on 24.05.2025.
//

#ifndef WORM_H
#define WORM_H

#include "WormPart.h"

class Worm {
public:
    enum Direction {
        UP, RIGHT, DOWN, LEFT
    };

    Worm(int startX, int startY);

    void move();
    void grow();
    void turn(Direction newDirection);

    WormPart* getHead();
    int getsize() const;
    Direction getDirection() const;

private:
    WormPart* head;
    int size;
    Direction direction;

    void addPartToFront();
    void removeTail();
};
#endif //WORM_H
