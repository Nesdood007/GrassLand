#include <typeinfo>
#include "Wolf.h"
#include "Rabbit.h"

const int RANGE = 65;
const int TIMEOUT = 100;

Wolf::Wolf(int DOB, int x, int y) {
    birthday = DOB;
    time = DOB;
    this->x = x;
    this->y = y;
    //cout << "Wolf Coords: " << x << ", " << y << endl;
    simfield[x][y].animal = this;
}

//Run Function
void Wolf::run() {
    std::cout << "Day " << time << ":Wolf Ran" << std::endl;
    
    
    if (time - lastEat > 20) {
        cout << "Wolf died of hunger" << endl;
        simfield[x][y].animal = NULL;
        deaths[2]++;
        return;
    }
    if (time - birthday > 800 && rand() % 100 == 1) {
        cout << "Wolf died of old age" << endl;
        simfield[x][y].animal = NULL;
        deaths[2]++;
        return;
    }
    
    int newX = x, newY = y;
    bool foundRabbit = false;
    for (int i = x - (RANGE / 2); i < x + (RANGE / 2) && !foundRabbit; i++) {
        for (int j = y - (RANGE / 2); j < y + (RANGE / 2) && !foundRabbit; j++) {
            if (i > 0 && i < 512 && j > 0 && j < 512) {
                //@TODO Check if the animal there is a rabbit, and eat it.
                if (typeid(Rabbit) == typeid(simfield[i][j].animal)) {
                    foundRabbit = true;
                    newX = i - x + (RANGE / 2) + 1;
                    newY = j - y + (RANGE / 2) + 1;
                    Rabbit* temp = static_cast<Rabbit*>(simfield[i][j].animal);
                    temp -> kill();
                }
            }
        }
    }
    //@TODO If a rabbit is not found, go to a random, empty spot.
    //@TODO Otherwise, Set the spot to where the rabbit was.
    //@TODO Make sure to update the simfield of the Wolf's position
    
    if (!foundRabbit) {
        cout << "\tLooking for random spot" << endl;
        //cout << "\tWolf orig Coords: " << x << ", " << y << endl;
        //cout << "\tRANGE/2:" << (RANGE / 2) << endl;
        int tempX = x - (RANGE / 2);
        int tempY = y - (RANGE / 2);
        //cout << "\tWolf temp Coords: " << tempX << ", " << tempY << endl;
        if (tempX < 0) tempX = 0;
        //if (tempX - RANGE > 512) tempX = x
        if (tempY < 0) tempY = 0;
        int to = 0;
        while (newX >= 512 || newY >= 512 || simfield[newX][newY].animal != NULL || to < TIMEOUT) {
            newX = (rand() % RANGE) + tempX;
            newY = (rand() % RANGE) + tempY;
            //cout << "\tWolf Coords: " << newX << ", " << newY << endl;
            to++;
        }
        if (to >= TIMEOUT) {
            newX = x;
            newY = y;
        }
        
    }
    simfield[x][y].animal = NULL;
    x = newX;
    y = newY;
    cout << "\t{" << x << "," << y << "}" << endl;
    simfield[x][y].animal = this;
    
    time += 4;
    pq.push(this);
}
