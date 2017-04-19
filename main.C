#include <iostream>
#include <queue>
#include <cstdlib>

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
//Keeps track of all animals added to simulation
int created[3];

void initiateField();
void populateField(int ar, int lr, int w, int t);

int main() {
    srand(time(0));
    initiateField();
    //@TODO Make the Placement of the animals random and put them in seperate spots on the board.
    Item *temp;
    /*//Active Rabbits
    for (int i = 0; i < 10; i++) {
        temp = new ActiveRabbit(0, 0, 0);
        //temp -> time = 0;
        pq.push(temp);
    }
    //Lazy Rabbits
    for (int i = 0; i < 10; i++) {
        temp = new LazyRabbit(0, 0, 0);
        //temp -> time = 0;
        pq.push(temp);
    }
    //Wolves
    for (int i = 0; i < 10; i++) {
        temp = new Wolf(0, 0, 0);
        temp -> time = 0;
        pq.push(temp);
    }*/
    
    populateField(500, 500, 100, 0);
    pq.push(new Doubler());
    
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
    cout << "=====Animals Created=====" << endl;
    cout << "Animals:\tNumber" << endl;
    cout << "Active Rabbits:\t" << created[0] << endl;
    cout << "Lazy Rabbits:\t" << created[1] << endl;
    cout << "Wolves:\t\t" << created[2] << endl;
}

void initiateField() {
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            simfield[i][j].grass = new Grass();
        }
    }
}

//Populates the Field
//  ar - Active Rabbit
//  lr - Lazy Rabbit
//  w - Wolf
//  t - Time of the Simulation to set as birthday
void populateField(int ar, int lr, int w, int t) {
    created[0] += ar;
    created[1] += lr;
    created[2] += w;
    int x = 0, y = 0;
    Item *temp;
    for (int i = 0; i < ar; i++) {
        while (simfield[x][y].animal != NULL) {
            x = rand() % 512;
            y = rand() % 512;
        }
        cout << "AR:" << x << ", " << y << endl;
        temp = new ActiveRabbit(t, x, y);
        pq.push(temp);
    }
    for (int i = 0; i < lr; i++) {
        while (simfield[x][y].animal != NULL) {
            x = rand() % 512;
            y = rand() % 512;
        }
        cout << "LR:" << x << ", " << y << endl;
        temp = new LazyRabbit(t, x, y);
        pq.push(temp);
    }
    for (int i = 0; i < w; i++) {
        while (simfield[x][y].animal != NULL) {
            x = rand() % 512;
            y = rand() % 512;
        }
        cout << "W:" << x << ", " << y << endl;
        temp = new Wolf(t, x, y);
        pq.push(temp);
    }
}
