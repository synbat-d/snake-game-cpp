#include <iostream>
#include "WormPart.h"
#include "Food.h"
#include "Grid.h"

int main() {
    Grid grid(20,20, 'O', '#', 3);
    WormPart head(3,3);
    WormPart body1(4,3);
    WormPart body2(5,3);
    WormPart body3(6,3);
    WormPart body4(6,4);
    WormPart body5(6,5);
    WormPart body6(6,6);
    head.next=&body1;
    body1.next=&body2;
    body2.next=&body3;
    body3.next=&body4;
    body4.next=&body5;
    body5.next=&body6;
    grid.printGrid(&head);
}
