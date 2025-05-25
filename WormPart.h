#ifndef WORMPART_H
#define WORMPART_H

class WormPart {
public:
    int x;
    int y;
    WormPart* next;
    WormPart(int x, int y);
    void print();
};

#endif //WORMPART_H
