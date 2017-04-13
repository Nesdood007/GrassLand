#ifndef ANIMAL_H
#define ANIMAL_H

#include "Item.h"

using namespace std;

class Animal : public Item {
    public:
        Animal() {}
        int birthday; //date of Birth
        int lastEat; //Day that the Animal ate last
        virtual void run() =0;
};

#endif
