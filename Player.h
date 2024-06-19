#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h" 
#include "Food.h"

class Player{
    public:
        Player(GameMechs* thisGMRef, Food* foodRef);
        ~Player();

        objPosArrayList* getPlayerPos();

        void getPlayerPos(objPos &returnPos); 
        void updatePlayerDir();
        void movePlayer();
        void increasePlayerLength();
        bool checkSelfCollision();
        bool checkFoodConsumption();
        
    private:
        enum Dir {STOP, UP, DOWN, LEFT, RIGHT};  // This is the direction state (FSM)
        objPosArrayList *playerPosList;    
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* myFood;

        void initializePlayer();
            
};

    extern GameMechs* myGM; // Declare myGM as an external variable

#endif
