//
// Created by SDulatuly on 24.05.2025.
//

#include "Worm.h"

#include <cmath>
#include <stdlib.h>

Worm::Worm(int startX, int startY) {
    this->head = new WormPart(startX, startY);
    this->size = 1;
    this->direction = Worm::Direction::RIGHT;
}

Worm::~Worm() {
    // Clean up all parts
    WormPart* current = head;
    while (current != nullptr) {
        WormPart* temp = current;
        current = current->next;
        delete temp;
    }
}

void Worm::move() {
    addPartToFront();
    removeTail();
}

void Worm::grow() {
    addPartToFront();
}

void Worm::turn(Direction newDirection) {
    bool turnIsValid = abs(newDirection-this->direction)%2 < 2;
    if (turnIsValid)
        this->direction = newDirection;
}

WormPart* Worm::getHead() {\
return this->head;
}

int Worm::getsize() const {
    return this->size;
}

Worm::Direction Worm::getDirection() const {
    return this->direction;
}

void Worm::addPartToFront() {
    int previousX = this->head->x;
    int previousY = this->head->y;
    int newX = previousX;
    int newY = previousY;
    if (this->direction == Worm::Direction::RIGHT) {
        newX += 1;
    }
    else if (this->direction == Worm::Direction::LEFT) {
        newX -= 1;
    }
    else if (this->direction == Worm::Direction::UP) {
        newY += 1;
    }
    else {
        newY -= 1;
    }
    WormPart* newPart = new WormPart(newX, newY);
    newPart->next = this->head;
    this->head = newPart;
    size++;
}

void Worm::removeTail() {
    WormPart* tailBefore = this->head;
    while (tailBefore->next->next != NULL) {
        tailBefore = tailBefore->next;
    }
    WormPart* tail = tailBefore->next;
    tailBefore->next = nullptr;
    delete tail;
    size--;
}






