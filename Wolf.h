#ifndef WOLF_H
#define WOLF_H

#include <iostream>
#include <queue>
#include "Animal.h"
#include "Land.h"

using namespace std;

extern priority_queue<Item*, vector<Item*>, compareItem> pq;
extern Land simfield[512][512];
extern int deaths[3];

class Wolf : public Animal {
    public:
        Wolf(int DOB, int x, int y);
        void run();
};

#endif
