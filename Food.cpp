#include "Food.h"
#include <cstdlib> //srand() and rand();
#include <ctime> // time()

#define boardSizeX 20
#define boardSizeY 10 // initial board size


Food::Food(){
    srand(time(NULL)); // seeding random number generator
    foodBucket = new objPosArrayList();
    numSpecialFoods = 0;
    maxSpecialFoods = 2; //  Maximum of 2 special food items
}   

Food::~Food() {
    delete foodBucket;
}


// random food generation
void Food::generateFood(objPos blockOff) {

    foodBucket->clear(); // Clear current food items
    numSpecialFoods = 0; // Reset special food count



    for (int i = 0; i < 5; ++i) {
        int xPos, yPos;
        bool posIsBlocked = true;

        while (posIsBlocked) {
            xPos = rand() % boardSizeX;
            yPos = rand() % boardSizeY;

            if (xPos != blockOff.getX() || yPos != blockOff.getY()) {
                posIsBlocked = false;
            }
        }

        char symbol = 'o'; // Default food symbol
        if (numSpecialFoods < maxSpecialFoods && rand() % 5 < 2) {
            symbol = '$'; // Special food symbol
            ++numSpecialFoods;
        }

        objPos foodPos(xPos, yPos, symbol);
        foodBucket->insertTail(foodPos); // Add the food item to the foodBucket
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
    for (int i = 0; i < foodBucket->getSize(); ++i) {
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
