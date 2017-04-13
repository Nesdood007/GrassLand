// @TODO Compile Problem: http://stackoverflow.com/questions/11072244/c-multiple-definitions-of-a-variable
#ifndef LAND_H
#define LAND_H

#include "Item.h"
#include "Animal.h"

using namespace std;

class Grass;

//Constainer for the Land
struct Land {
    Animal* animal;
    Grass* grass;
};

//Land for the Simulation
Land simfield[512][512];

//Grass 
class Grass : public Item {
    public:
        Grass() {}
        bool isEaten;
        int age;
};

#endif
