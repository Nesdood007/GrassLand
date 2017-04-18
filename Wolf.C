#include "Wolf.h"

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
    if (time - birthday > 800) {
        cout << "Wolf died of old age" << endl;
    }
    
    
    bool foundRabbit = false;
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < RANGE; j++) {
            if (i > 0 && i < 512 && j > 0 && j < 512) {
                //@TODO Check if the animal there is a rabbit, and eat it.
            }
        }
    }
    //@TODO If a rabbit is not found, go to a random, empty spot.
    //@TODO Otherwise, Set the spot to where the rabbit was.
    //@TODO Make sure to update the simfield of the Wolf's position
    
    time += 4;
    pq.push(this);
}
