#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food {
    private:
      
        objPosArrayList* foodBucket; // Array list to hold multiple food items
        int numSpecialFoods; // Number of special food items
        int maxSpecialFoods; // Maximum number of special food items allowed


    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);

        int getNumFoodBucketElements(); // Get the number of food items in the bucket
        void getFoodBucketElement(objPos& returnPos, int index); // Get food item at index

        bool isSpecialFood(int index); // Check if food item at index is specia
        int findFoodIndex(const objPos& foodPos);
        void removeFoodBucketElement(int index); // Method to remove food item from bucket
        void addFood(objPos foodPos, char symbol, bool special=false);

};

#endif

