//
// Created by SDulatuly on 24.05.2025.
//

#ifndef WORM_H
#define WORM_H

#include "WormPart.h"

class Worm {
public:
    WormPart* head;
    enum Direction {
        UP, RIGHT, DOWN, LEFT
    };
    Direction direction;

    Worm(int startX, int startY);
    ~Worm();

    void move();
    void grow();
    void turn(Direction newDirection);

    WormPart* getHead();
    int getsize() const;
    Direction getDirection() const;

private:
    int size;

    void addPartToFront();
    void removeTail();
};
#endif //WORM_H
