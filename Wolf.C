#include <typeinfo>
#include "Wolf.h"
#include "Rabbit.h"

const int RANGE = 65;
Wolf::Wolf(int DOB) {
    birthday = DOB;
}

//Run Function
void Wolf::run() {
    std::cout << "Wolf Ran" << std::endl;
    
    if (time - lastEat > 20) {
        cout << "Wolf died of hunger" << endl;
        simfield[x][y].animal = NULL;
        return;
    }
    if (time - birthday > 800 && rand() % 100 == 1) {
        cout << "Wolf died of old age" << endl;
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
        int tempX = x - (RANGE / 2);
        int tempY = y - (RANGE / 2);
        if (tempX < 0) tempX = 0;
        if (tempY < 0) tempY = 0;
        while (simfield[newX][newY].animal != NULL) {
            newX = (rand() % RANGE) + tempX;
            newY = (rand() % RANGE) + tempY;
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
