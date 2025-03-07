//Brady O'Leary, Viraj Patel
//CSCE 240 Spring 2017 Project 7 - GrassLand Simulator
//19 April 2017
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
extern int deaths[3];

class Rabbit : public Animal {
    protected:
        bool isKilled;
    public:
        Rabbit() {}
        virtual void run() {}//=0
        void kill();
};

class LazyRabbit : public Rabbit {
    public:
        LazyRabbit(int DOB, int x, int y);
        void run();
};

class ActiveRabbit : public Rabbit {
    int deathDay;
    public:
        ActiveRabbit(int DOB, int x, int y);
        void run();
};

#endif
