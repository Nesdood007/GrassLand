#include "Wolf.h"

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
        cout << "" << endl;
    }
    
    
    time += 4;
    pq.push(this);
}
