#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <queue>

#include "Item.h"
#include "Animal.h"

using namespace std;

extern priority_queue<Item*, vector<Item*>, compareItem> pq;

struct Land;

extern Land simfield[512][512];

class Grass;

//Constainer for the Land
struct Land {
    Animal* animal;
    Grass* grass;
};

//Grass 
class Grass : public Item {
    private:
        bool eaten;
    public:
        Grass() {}
        bool isEaten();
        void run();
        void eat();
};

//Returns a square subset of the Land by size (Diameter) and the center
//Invalid Spots will = NULL
//Land ** subset(int, int, int);

#endif
