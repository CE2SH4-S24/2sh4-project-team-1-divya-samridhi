#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h" 

class Player
{
    public:
       

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        void increasePlayerLength();
        bool checkSelfCollision();
      //  bool checkFoodConsumption();
        
    private:
     enum Dir {STOP, UP, DOWN, LEFT, RIGHT};  // This is the direction state (FSM)
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

        void initializePlayer();
        
        
};

#endif