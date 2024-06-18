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
     foodPos.x = rand() % (boardSizeX -2);
    foodPos.y = rand() % (boardSizeY -2);
        
    foodPos.symbol = 'o';


 // Check if generated position is already taken
        while ((blockOff.x == foodPos.x  && blockOff.y == foodPos.y)) {
            // Generate new coordinates until a free one is found
            foodPos.x = rand() % (boardSizeX -2);
            foodPos.y = rand() % (boardSizeY -2);
              foodPos.symbol = 'o';
        
        }


}

void Food::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}