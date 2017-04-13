#ifndef RABBIT_H
#define RABBIT_H

#include "Animal.h"

using namespace std;

class Rabbit : public Animal {
    public:
        Rabbit() {}
        virtual void run() =0;
};

class LazyRabbit : public Rabbit {
    public:
        LazyRabbit(int DOB);
        void run();
};

class ActiveRabbit : public Rabbit {
    public:
        ActiveRabbit(int DOB);
        void run();
};

#endif
