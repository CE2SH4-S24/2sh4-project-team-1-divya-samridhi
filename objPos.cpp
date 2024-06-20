#include "objPos.h"

// Default constructor
objPos::objPos() {
    x = 0;
    y = 0;
    symbol = '\0'; // NULL character
}

// Copy constructor
objPos::objPos(const objPos &o) {
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

// Special constructor
objPos::objPos(int xPos, int yPos, char sym) {
    x = xPos;
    y = yPos;
    symbol = sym;
}

// Setter method using another objPos object
void objPos::setObjPos(const objPos &o) {
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

// Setter method using individual values
void objPos::setObjPos(int xPos, int yPos, char sym) {
    x = xPos;
    y = yPos;
    symbol = sym;
}

// Getter method to copy objPos object
void objPos::getObjPos(objPos &returnPos) const {
    returnPos.setObjPos(x, y, symbol);
}

// Getter for symbol
char objPos::getSymbol() const {
    return symbol;
}

// Check if positions are equal
bool objPos::isPosEqual(const objPos* refPos) const {
    return (refPos->x == x && refPos->y == y);
}

// Get symbol if positions are equal
char objPos::getSymbolIfPosEqual(const objPos* refPos) const {
    if (isPosEqual(refPos)) {
        return getSymbol();
    } else {
        return '\0'; // Return NULL character if positions are not equal
    }
}


    

        
