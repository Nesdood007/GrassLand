#ifndef RABBIT_H
#define RABBIT_H

#include <iostream>
#include <queue>
#include <cstdlib>
#include "Animal.h"
#include "Land.h"

using namespace std;

extern priority_queue<Item*, vector<Item*>, compareItem> pq;
extern Land simfield[512][512];

class Rabbit : public Animal {
    public:
        Rabbit() {}
        virtual void run() =0;
};

class LazyRabbit : public Rabbit {
    public:
        LazyRabbit(int DOB, int x, int y);
        void run();
};

class ActiveRabbit : public Rabbit {
    public:
        ActiveRabbit(int DOB, int x, int y);
        void run();
};

#endif
