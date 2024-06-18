#include "Food.h"
#include <cstdlib> //srand() and rand();
#include <ctime> // time()

#define boardSizeX 20
#define boardSizeY 10 // initial board size


Food::Food(){
    srand(time(NULL)); // seeding random number generator
}

Food::~Food() {}

// random food generation
void Food::generateFood(objPos blockOff) {

    foodPos.setObjPos(rand() % (boardSizeX - 2), rand() % (boardSizeY - 2), 'o'); // random position within board 

    // Check if generated position is already taken
    while (blockOff.isPosEqual(&foodPos)) { 
        // Generate new coordinates until a free one is found
        foodPos.setObjPos(rand() % (boardSizeX - 2), rand() % (boardSizeY - 2), 'o');
    
    }
}

void Food::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}