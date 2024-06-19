#ifndef OBJPOS_H 
#define OBJPOS_H

class objPos {
    private:
        int x;
        int y;
        char symbol;

    public:
        objPos();
        objPos(const objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym);

        void setObjPos(const objPos &o);        
        void setObjPos(int xPos, int yPos, char sym);

        void getObjPos(objPos &returnPos) const;

        char getSymbol() const;
        bool isPosEqual(const objPos* refPos) const;
        char getSymbolIfPosEqual(const objPos* refPos) const;

        int getX() const { 
            return x; 
        }

        int getY() const{ 
            return y; 
        }

};
#endif
