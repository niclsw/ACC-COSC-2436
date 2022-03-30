#include <vector>
#include <string>

#include "LinkedList.h"

template <class ItemType>
LinkedList<ItemType>::LinkedList()
{
    headPtr = nullptr;
    numItems = 0;
}

template <class ItemType>
LinkedList<ItemType>::LinkedList(ItemType *headPtr)
{
    headPtr = headPtr;
    numItems = 0;
}

template <class ItemType>
bool LinkedList<ItemType>::addNode(const ItemType &newEntry)
{
    bool success { false }
    if (headPtr == nullptr)
    {
        headPtr = new Node<ItemType>(newEntry);
        success = true;
    }
    else
    {

        // if an entry is less than the headPtr
        if (newEntry < headPtr->getLine())
        {
            Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry, headPtr);
            headPtr = newNodePtr;
            success = true;
        }
        else
        {
            Node<ItemType> *curPtr = headPtr;
            Node<ItemType> *prevPtr = nullptr;
            while (curPtr != nullptr && newEntry > curPtr->getLine())
            {
                prevPtr = curPtr;
                curPtr = curPtr->getNext();
            }
            if (curPtr == nullptr)
            {
                prevPtr->setNext(new Node<ItemType>(newEntry));
                success = true;
            }
            else
            {
                Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry, curPtr);
                prevPtr->setNext(newNodePtr);
                success = true;
            }
        }




        // Node<ItemType> *currentPtr = headPtr;
        // while (currentPtr->getNext() != nullptr)
        // {
            
        //     currentPtr = currentPtr->getNext();
        // }
        // currentPtr->setNext(new Node<ItemType>(newEntry));
        // success = true;
        // numItems++;
    }

    return success;
}

template <class ItemType>
int LinkedList<ItemType>::getSize() const
{
    return numItems;
}

template <class ItemType>
ItemType LinkedList<ItemType>::toVector()
{
    ItemType vector;
    Node<ItemType> *currentPtr = this->headPtr;

    for (int i = 0; i < this->numItems; i++)
    {
        vector.push_back(currentPtr->getItem());
        currentPtr = currentPtr->getNext();
    }

    return vector;
} 

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    Node<ItemType> *currentPtr = this->headPtr;
    Node<ItemType> *tempPtr;

    while (currentPtr != nullptr)
    {
        tempPtr = currentPtr;
        currentPtr = currentPtr->getNext();
        delete tempPtr;
    }
}
