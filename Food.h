#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

class Food {
private:
    objPos foodPos;

public:
    Food(); // Constructor
    ~Food(); // Destructor

    void generateFood(objPos blockOff);
    void getFoodPos(objPos &returnPos);
};

#endif