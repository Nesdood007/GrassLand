#ifndef WOLF_H
#define WOLF_H

#include <iostream>
#include <queue>
#include "Animal.h"

using namespace std;

extern priority_queue<Item*, vector<Item*>, compareItem> pq;

class Wolf : public Animal {
    public:
        Wolf(int DOB);
        void run();
};

#endif
