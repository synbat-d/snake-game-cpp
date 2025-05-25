//
// Created by SDulatuly on 24.05.2025.
//

#ifndef FOOD_H
#define FOOD_H
struct Food {
    int x;
    int y;

    Food(int x, int y) : x(x), y(y) {}

    bool operator<(const Food &other) const {
        return (x<other.x || (x==other.x && y<other.y));
    }
};

#endif //FOOD_H
