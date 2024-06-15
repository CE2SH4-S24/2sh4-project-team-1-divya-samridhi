#include "objPosArrayList.h" 

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
        aList = new objPos[ARRAY_MAX_CAP]; // 2500 elements on the heap 
        listSize = 0; // initial list
        arrayCapacity = ARRAY_MAX_CAP; // array capacity at max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // this is becuase aList is an array
}

int objPosArrayList::getSize()
{
return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    if (listSize != arrayCapacity){

    

        for (int i = listSize; i >0; i--){
            aList[i].setObjPos(aList[i-1]);
        }

        aList[0].setObjPos(thisPos); // this shuffles all elements towards the tail
        listSize++;
} 

}

void objPosArrayList::insertTail(objPos thisPos)
{

}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{

}