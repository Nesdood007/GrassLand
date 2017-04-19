#include "Rabbit.h"

const int size = 11;
const int sizeA = 21;
const int TIMEOUT = 50;

void Rabbit::kill() {
    isKilled = true;
}

LazyRabbit::LazyRabbit(int DOB, int x, int y) {
    birthday = DOB;
    time = DOB;
    this->x = x;
    this->y = y;
    //srand(time(NULL));
    isKilled = false;
    simfield[x][y].animal = this;
}

//Run Function
void LazyRabbit::run() {
    cout << "Day " << time << ": Lazy Rabbit Ran" << endl;
    if (time - lastEat > 5 || time - birthday > 450 || isKilled) {
        cout << "\tLazy Rabbit has Died" << endl;
        simfield[x][y].animal = NULL;
        deaths[1]++;
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
                if (i > 0 && j > 0 && i < 512 && j < 512 && !simfield[i][j].grass -> isEaten() && simfield[i][j].animal == NULL) {
                    //Empty Grass spot is found, move here
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
            int to = 0;
            while (newX >= 512 || newY >= 512 || simfield[newX][newY].animal != NULL || to < TIMEOUT) {
                newX = (rand() % size) + tempX;
                newY = (rand() % size) + tempY;
                to++;
            }
            //If timeout Expires, then don't move
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
    }
    time += 1;
    pq.push(this);
}

ActiveRabbit::ActiveRabbit(int DOB, int x, int y) {
    birthday = DOB;
    time = DOB;
    this->x = x;
    this->y = y;
    deathDay = 18 + rand() % 4;
    isKilled = false;
    simfield[x][y].animal = this;
}

//Run Function
void ActiveRabbit::run() {
    cout << "Day " << time << ":Active Rabbit Ran" << endl;
    if (time - lastEat > 20) {
        cout << "\tActive Rabbit has died of hunger" << endl;
        simfield[x][y].animal = NULL;
        deaths[0]++;
        return;
    }
    //Kill Active Rabbit if it is too old and the chance is correct
    if (time - birthday > deathDay && rand() % 20 == 1) {
        cout << "\tActive Rabbit has died of old age" << endl;
        simfield[x][y].animal = NULL;
        deaths[0]++;
        return;
    }
    if (isKilled) {
        cout << "Active Rabbit has been eaten and was killed" << endl;
        //Don't need to change the spot because the wolf will be there
        deaths[0]++;
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
                if (i > 0 && j > 0 && i < 512 && j < 512 && !simfield[i][j].grass -> isEaten() && simfield[i][j].animal == NULL) {
                    //Grass is found and spot is empty, move here
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
            int to = 0;
            while (newX >= 512 || newY >= 512 || simfield[newX][newY].animal != NULL || to < TIMEOUT) {
                newX = (rand() % sizeA) + tempX;
                newY = (rand() % sizeA) + tempY;
                to++;
            }
            //If timeout Expires, then don't move
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
    }
    time += 2;
    pq.push(this);
}
