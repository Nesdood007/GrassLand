//Brady O'Leary, Viraj Patel
//CSCE 240 Spring 2017 Project 7 - GrassLand Simulator
//19 April 2017
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
    public:
        Item() {}
        int time;
        virtual void run() =0;
};

//Makes Item comparable for the priotiry_queue
struct compareItem {
    bool operator()(const Item* t1, const Item* t2) const {
        return (t1 -> time) > (t2 -> time);
    }
};

#endif
