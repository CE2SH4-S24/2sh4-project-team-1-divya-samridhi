#include "objPosArrayList.h" 

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.



objPosArrayList::objPosArrayList(){
    aList = new objPos[ARRAY_MAX_CAP]; // 2500 elements on the heap 
    sizeList = 0; // initial list
    sizeArray = ARRAY_MAX_CAP; // array capacity at max
}

objPosArrayList::~objPosArrayList(){
    delete[] aList; // this is becuase aList is an array
}


void objPosArrayList::insertHead(objPos thisPos){

    if (sizeList != sizeArray){
        for (int i = sizeList; i >0; i--){
            aList[i].setObjPos(aList[i-1]); 
        }

        aList[0].setObjPos(thisPos); // shuffles all elements towards the tail
        sizeList++;
    } 
}

void objPosArrayList::insertTail(objPos thisPos){
    if(sizeList < sizeArray){
        aList[sizeList] = thisPos; 
        sizeList++;
    }
}

void objPosArrayList::removeHead(){
    if (sizeList > 0) {
        for (int i = 0; i < sizeList - 1; i++){
            aList[i] = aList[i + 1];
        }
    sizeList--;
    }
}

void objPosArrayList::removeTail(){
    if (sizeList > 0) {
        sizeList--;
    }
}

void objPosArrayList::removeElementAtIndex(int index) {
    if (index >= 0 && index < sizeList) {
        for (int i = index; i < sizeList - 1; ++i) {
            aList[i] = aList[i + 1];
        }
        sizeList--;
    }
}

int objPosArrayList::getSize() {
    return sizeList;
}

void objPosArrayList::getHeadElement(objPos &returnPos){
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos){
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index){
    if (index >= 0 && index < sizeList) {
        returnPos = aList[index];
    }
}

void objPosArrayList::clear() {
    sizeList = 0; // Reset size to 0, effectively clearing the list
}
