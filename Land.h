#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <queue>
#include <cstdlib>

#include "Item.h"
#include "Animal.h"

using namespace std;

extern priority_queue<Item*, vector<Item*>, compareItem> pq;
struct Land;
extern Land simfield[512][512];
extern int deaths[3];
extern int created[3];


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

//Doubles the Animals in the Simulation
class Doubler : public Item {
    public:
        Doubler() {time = 350 + rand() % 100;}
        void run();
};

//Returns a square subset of the Land by size (Diameter) and the center
//Invalid Spots will = NULL
//Land ** subset(int, int, int);

#endif
