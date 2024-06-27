#include "Food.h"
#include <cstdlib> //srand() and rand();
#include <ctime> // time()

#define boardSizeX 20
#define boardSizeY 10 // initial board size
using namespace std;

Food::Food(){
    srand(time(NULL)); // seeding random number generator
    foodBucket = new objPosArrayList();
    numSpecialFoods = 0;
    maxSpecialFoods = 2; //  Maximum of 2 special food items
}   

Food::~Food() {
    delete foodBucket;
}

void Food::generateFood(objPos blockOff) {
   foodBucket->clear();
   numSpecialFoods = 0;
   int generatedFoods = 0;


   while (generatedFoods < 5) {
       int xPos, yPos;
       bool overlap = false;

       do {
           xPos = rand() % (boardSizeX-3); // THIS IS THE BIGGEST MISTAKE WE MADE it should not be outside the boarder!!
           yPos = rand() % (boardSizeY-3); // By making it -3, it ensures that the food doesn't overlap with the boarder coordinates and so the 5 food items are clearly visible
          
           overlap = false; // Reset overlap for each new position
          
           // Check if the generated position overlaps with existing food items NEXT BIGGEST MISTAKE WE MADE
           for (int j = 0; j < foodBucket->getSize(); j++) {
               objPos currentPos;
               foodBucket->getElement(currentPos, j);
               if (currentPos.getX() == xPos && currentPos.getY() == yPos) {
                   overlap = true; // There is an overlap
                   break; // Exit the loop, this is how overlap is being handled within food items
               }
           }


           // Check if the generated position is overlapping with the player 
           if (xPos == blockOff.getX() && yPos == blockOff.getY()) {
               overlap = true; // There is an overlap with the player
           }

       } while (overlap); // Repeat until no overlap is found


    
       char symbol = 'o';
       if (numSpecialFoods < maxSpecialFoods && rand() % 5 < 2) {
           symbol = '$'; // Special food 
           numSpecialFoods++;
       }


       objPos foodPos(xPos, yPos, symbol);
       foodBucket->insertTail(foodPos); // Insert the new food item into the bucket

       generatedFoods++;
   }
}


void Food::getFoodPos(objPos& returnPos) {
    foodBucket->getHeadElement(returnPos); // Example: Get the first food item in the bucket
}

int Food::getNumFoodBucketElements() {
    return foodBucket->getSize(); // Example: Get the number of food items in the bucket
}

void Food::getFoodBucketElement(objPos& returnPos, int index) {
    foodBucket->getElement(returnPos, index); // Example: Get food item at index in the bucket
}

bool Food::isSpecialFood(int index) {
    objPos food;
    foodBucket->getElement(food, index);
    return (food.getSymbol() == '$'); // Example: Check if food item at index is special
}


int Food::findFoodIndex(const objPos& foodPos) {
    for (int i = 0; i < foodBucket->getSize(); i++) {
        objPos currentFood;
        foodBucket->getElement(currentFood, i);
        if (currentFood.isPosEqual(&foodPos)) {
            return i;
        }
    }
    return -1; // Not found
}

void Food::removeFoodBucketElement(int index) {
    foodBucket->removeElementAtIndex(index); // Example: Remove food item at index from the bucket
}

void Food::addFood(objPos foodPos, char symbol, bool special) {
    foodPos.setObjPos(foodPos.getX(), foodPos.getY(), symbol);
    foodBucket->insertTail(foodPos); // Add food to the bucket
}