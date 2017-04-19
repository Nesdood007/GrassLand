#include <iostream>
#include <queue>

#include "Item.h"
#include "Animal.h"
#include "Rabbit.h"
#include "Wolf.h"
#include "Land.h"

using namespace std;

priority_queue<Item*, vector<Item*>, compareItem> pq;
//Land for the Simulation
Land simfield[512][512];
//Keeps track of dead animals
//{Active Rabbit, Lazy Rabbit, Wolf}
int deaths[3];

void initiateField();

int main() {
    initiateField();
    //@TODO Make the Placement of the animals random and put them in seperate spots on the board.
    Item *temp;
    //Active Rabbits
    for (int i = 0; i < 10; i++) {
        temp = new ActiveRabbit(0, 0, 0);
        temp -> time = 0;
        pq.push(temp);
    }
    //Lazy Rabbits
    for (int i = 0; i < 10; i++) {
        temp = new LazyRabbit(0, 0, 0);
        temp -> time = 0;
        pq.push(temp);
    }
    //Wolves
    for (int i = 0; i < 10; i++) {
        temp = new Wolf(0, 0, 0);
        temp -> time = 0;
        pq.push(temp);
    }
    
    int currTime = 0;
    while(currTime < 10000 && !pq.empty()) {
        temp = pq.top();
        pq.pop();
        currTime = temp -> time;
        temp -> run();
    }
    
    //Print Stats
    cout << "=====Simulation Deaths=====" << endl;
    cout << "Animals:\tDeaths" << endl;
    cout << "Active Rabbits:\t" << deaths[0] << endl;
    cout << "Lazy Rabbits:\t" << deaths[1] << endl;
    cout << "Wolves:\t\t" << deaths[2] << endl;
    
}

void initiateField() {
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            simfield[i][j].grass = new Grass();
        }
    }
}
