#include "Rabbit.h"

const int size = 11;
const int sizeA = 21;

LazyRabbit::LazyRabbit(int DOB, int x, int y) {
    birthday = DOB;
    this->x = x;
    this->y = y;
    //srand(time(NULL));
}

//Run Function
void LazyRabbit::run() {
    cout << "Lazy Rabbit Ran" << endl;
    if (time - lastEat > 5 || time - birthday > 450) {
        cout << "\tLazy Rabbit has Died" << endl;
        simfield[x][y].animal = NULL;
        return;
    }
    cout << "\t[x,y]:[" << x << "," << y <<"]" << endl;
    if (!simfield[x][y].grass -> isEaten()) {
        //If the rabbit is standing on grass, eat it.
        simfield[x][y].grass -> eat();
        lastEat = time;
    } else {
    cout << "\tFinding Grass..." << endl;
        int newX = x, newY = y;
        bool grassFound = false;
        //If grass is found, then move to grass, otherwise, pick a random spot to move to
        for (int i = x - (size / 2 ); i < x + (size / 2) && !grassFound; i++) {
            for (int j = y - (size / 2); j < y + (size / 2) && !grassFound; j++) {
                if (i > 0 && j > 0 && i < 512 && j < 512 && !simfield[i][j].grass -> isEaten()) {
                    //Grass is found, move here
                    grassFound = true; newX = i - x + (size / 2) + 1; newY = j - y + (size / 2) + 1;
                    simfield[i][j].grass -> eat();
                    lastEat = time;
                   
                }
            }
        }
        if (!grassFound) {
            //Find Random Spot
            cout << "\tWill Look for Random Spot" << endl;
            int tempX = x - (size / 2);
            int tempY = y - (size / 2);
            if (tempX < 0) tempX = 0;
            if (tempY < 0) tempY = 0;
            newX = (rand() % size) + tempX;
            newY = (rand() % size) + tempY;
            
        }
        x = newX;
        y = newY;
        cout << "\t{" << x << "," << y << "}" << endl;
    }
    time += 1;
    pq.push(this);
}

ActiveRabbit::ActiveRabbit(int DOB, int x, int y) {
    birthday = DOB;
    this->x = x;
    this->y = y;
}

//Run Function
//@TODO Make ACtive Rabbit behave properly
void ActiveRabbit::run() {
    cout << "Active Rabbit Ran" << endl;
    if (time - lastEat > 5 || time - birthday > 450) {
        cout << "\tActive Rabbit has Died" << endl;
        simfield[x][y].animal = NULL;
        return;
    }
    cout << "\t[x,y]:[" << x << "," << y <<"]" << endl;
    if (!simfield[x][y].grass -> isEaten()) {
        //If the rabbit is standing on grass, eat it.
        simfield[x][y].grass -> eat();
        lastEat = time;
    } else {
    cout << "\tFinding Grass..." << endl;
        int newX = x, newY = y;
        bool grassFound = false;
        //If grass is found, then move to grass, otherwise, pick a random spot to move to
        for (int i = x - (sizeA / 2 ); i < x + (sizeA / 2) && !grassFound; i++) {
            for (int j = y - (sizeA / 2); j < y + (sizeA / 2) && !grassFound; j++) {
                if (i > 0 && j > 0 && i < 512 && j < 512 && !simfield[i][j].grass -> isEaten()) {
                    //Grass is found, move here
                    grassFound = true; newX = i - x + (sizeA / 2) + 1; newY = j - y + (sizeA / 2) + 1;
                    simfield[i][j].grass -> eat();
                    lastEat = time;
                   
                }
            }
        }
        if (!grassFound) {
            //Find Random Spot
            cout << "\tWill Look for Random Spot" << endl;
            int tempX = x - (sizeA / 2);
            int tempY = y - (sizeA / 2);
            if (tempX < 0) tempX = 0;
            if (tempY < 0) tempY = 0;
            newX = (rand() % sizeA) + tempX;
            newY = (rand() % sizeA) + tempY;
            
        }
        x = newX;
        y = newY;
        cout << "\t{" << x << "," << y << "}" << endl;
    }
    time += 2;
    pq.push(this);
}
