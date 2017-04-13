#include <iostream>
#include <queue>

#include "Item.h"
#include "Animal.h"
#include "Rabbit.h"
#include "Wolf.h"
#include "Land.h"

using namespace std;

priority_queue<Item*, vector<Item*>, compareItem> pq;

int main() {
    Item *temp;
    //Active Rabbits
    for (int i = 0; i < 10; i++) {
        temp = new ActiveRabbit(0);
        temp -> time = 0;
        pq.push(temp);
    }
    //Lazy Rabbits
    for (int i = 0; i < 10; i++) {
        temp = new ActiveRabbit(0);
        temp -> time = 0;
        pq.push(temp);
    }
    //Wolves
    for (int i = 0; i < 10; i++) {
        temp = new Wolf(0);
        temp -> time = 0;
        pq.push(temp);
    }
    
    int currTime = 0;
    while(currTime < 10000) {
        temp = pq.top();
        currTime = temp -> time;
        temp -> run();
        pq.pop();
    }
    
    
    
}
