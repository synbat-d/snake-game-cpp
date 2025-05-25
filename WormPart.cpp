#include "WormPart.h"
#include <iostream>

WormPart::WormPart(int x, int y) {
    this->x = x;
    this->y = y;
    this->next = nullptr;
}

void WormPart::print() {
    std::cout << "Worm part at(" << x << ", " << y << ")" << std::endl;
}