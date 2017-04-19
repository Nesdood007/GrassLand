//Brady O'Leary, Viraj Patel
//CSCE 240 Spring 2017 Project 7 - GrassLand Simulator
//19 April 2017
#include "Land.h"
#include "Rabbit.h"
#include "Wolf.h"

void Grass::run() {
    eaten = false;
}

//Called when Rabbit eats the grass
void Grass::eat() {
    eaten = true;
    time += 10;
    pq.push(this);
}

bool Grass::isEaten() {
    return eaten;
}

void Doubler::run() {
    cout << "Day " << time << ": Population was Doubled" << endl;
    int ar = created[0] - deaths[0];
    int lr = created[1] - deaths[1];
    int w = created[2] - deaths[2];
    cout << "\t AR:" << ar << " LR:" << lr << " W:" << w << endl;
    if (ar == 0 && lr == 0 && w == 0) {
        cout << "\t...But there was nothing to double" << endl;
        return;
    }
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
        temp = new ActiveRabbit(time, x, y);
        pq.push(temp);
    }
    for (int i = 0; i < lr; i++) {
        while (simfield[x][y].animal != NULL) {
            x = rand() % 512;
            y = rand() % 512;
        }
        cout << "LR:" << x << ", " << y << endl;
        temp = new LazyRabbit(time, x, y);
        pq.push(temp);
    }
    for (int i = 0; i < w; i++) {
        while (simfield[x][y].animal != NULL) {
            x = rand() % 512;
            y = rand() % 512;
        }
        cout << "W:" << x << ", " << y << endl;
        temp = new Wolf(time, x, y);
        pq.push(temp);
    }
    time += 350 + rand() % 100;
    pq.push(this);
}
