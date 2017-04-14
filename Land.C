#include "Land.h"

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

/*
//Returns a square subset of the Land by size (Diameter) and the center
//Invalid Spots will = NULL
Land ** subset(int size, int x, int y) {
    Land ** toReturn =  new Land*[size];
    int rad = size / 2;
    for (int i = x - rad; i < x + rad; i++) {
        toReturn[i] = new Land[size];
        for (int j = y - rad; j < y + rad; j++) {
            if (i > 0 && j > 0 && i < 512 && j < 512) {
                toReturn[i - x - rad][j - y - rad] = simfield[i][j];
            } else {
                toReturn[i - x - rad][j - y - rad] = NULL;
            }
        }
    }
    return toReturn;
}
*/
