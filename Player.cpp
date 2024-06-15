#include "Player.h"
#define row 10
#define colomn 20

 
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included



 playerPos.setObjPos(
        (mainGameMechsRef->getBoardSizeX()) / 2,
        (mainGameMechsRef->getBoardSizeY()) / 2,
        '-'
    );//  starting position middle of board


}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    
    char input = mainGameMechsRef->getInput();

    switch (input) {
        case 'w': // go up
            if (myDir != DOWN) {
                myDir = UP;
            }
            break;

        case 'a': // go left
            if (myDir != RIGHT) {
                myDir = LEFT;
            }
            break;

        case 's': // go down
            if (myDir != UP) {
                myDir = DOWN;
            }
            break;

        case 'd': // go right
            if (myDir != LEFT) {
                myDir = RIGHT;
            }
            break;
    }

}




void Player::movePlayer() {
    // Finite State Machine logic for moving the player
    switch (myDir) {
        case UP:
            playerPos.y = (playerPos.y == 0) ? mainGameMechsRef->getBoardSizeY() - 1 : playerPos.y - 1;
            break;
        case DOWN:
            playerPos.y = (playerPos.y == mainGameMechsRef->getBoardSizeY() - 1) ? 0 : playerPos.y + 1;
            break;
        case LEFT:
            playerPos.x = (playerPos.x == 0) ? mainGameMechsRef->getBoardSizeX() - 1 : playerPos.x - 1;
            break;
        case RIGHT:
            playerPos.x = (playerPos.x == mainGameMechsRef->getBoardSizeX() - 1) ? 0 : playerPos.x + 1;
            break;
        case STOP:
            // Do nothing
            break;
    }
}