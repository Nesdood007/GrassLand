#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"

using namespace std;

class Wolf : public Animal {
    public:
        Wolf(int DOB);
        void run();
};

#endif
