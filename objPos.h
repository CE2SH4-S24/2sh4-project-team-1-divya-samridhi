#ifndef OBJPOS_H 
#define OBJPOS_H

class objPos {
    private:
        int x;
        int y;
        char symbol;

    public:
        objPos();
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym);

        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        void getObjPos(objPos &returnPos);
        char getSymbol();
        bool isPosEqual(const objPos* refPos);
        char getSymbolIfPosEqual(const objPos* refPos);

        int getX(){ 
            return x; 
        }

        int getY(){ 
            return y; 
        }
};
#endif