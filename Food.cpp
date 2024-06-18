#include "Food.h"
#include <cstdlib>
#include <ctime>

#define boardSizeX 20
#define boardSizeY 10


Food::Food() {
    srand(time(NULL));
}

Food::~Food() {
    // Destructor
}

void Food::generateFood(objPos blockOff) {
   
   
    
    // Generate food at a random position within the board size
  foodPos.setObjPos(rand() % (boardSizeX - 2), rand() % (boardSizeY - 2), 'o');



 // Check if generated position is already taken
        while (blockOff.isPosEqual(&foodPos)) {
            // Generate new coordinates until a free one is found
            foodPos.setObjPos(rand() % (boardSizeX - 2), rand() % (boardSizeY - 2), 'o');
    
        }


}

void Food::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}