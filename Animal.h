#ifndef ANIMAL_H
#define ANIMAL_H

#include "Item.h"

using namespace std;

class Animal : public Item {
    protected:
        int x, y; //Coordinates of the Animal in the Land
    public:
        Animal() {}
        int birthday; //date of Birth
        int lastEat; //Day that the Animal ate last
        virtual void run() =0;
};

#endif
