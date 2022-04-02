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
    bool success{false}, duplicate{false};

    // if Node headptr is nullptr, create new Node
    if (headPtr == nullptr)
    {
        headPtr = new Node<ItemType>(newEntry);
        success = true;
    }
    // if Node headptr is not nullptr, place new node in ascending order on list
    else
    {
        Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);
        Node<ItemType> *previousNodePtr = nullptr;
        Node<ItemType> *currentNodePtr = headPtr;

        // loop through list until new node is placed in correct position
        while (currentNodePtr != nullptr && newEntry >= currentNodePtr->getItem())
        {
            previousNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->getNext();
            // if new node item is equal to item in previous node, set duplicate to true
            if (newEntry == previousNodePtr->getItem())
            {
                duplicate = true;
            }
            else
            {
                duplicate = false;
            }
        }

        // if not duplicate, continue through decision structure
        if (!duplicate)
        {
            if (previousNodePtr == nullptr)
            {
                newNodePtr->setNext(headPtr);
                headPtr = newNodePtr;
            }
            // if new node is last in list, set new node at end of list
            else if (currentNodePtr == nullptr)
            {
                previousNodePtr->setNext(newNodePtr);
            }
            // if new node is in middle of list, set new node as middle
            else
            {
                previousNodePtr->setNext(newNodePtr);
                newNodePtr->setNext(currentNodePtr);
            }
            success = true;
        }
    }

    if (success)
        numItems++;

    return success;
}

template <class ItemType>
int LinkedList<ItemType>::getSize() const
{
    return numItems;
}

template <class ItemType>
std::vector<ItemType> LinkedList<ItemType>::toVector()
{
    std::vector<ItemType> listContents;
    Node<ItemType> *currentPtr = headPtr;

    for (int i = 0; i < numItems; i++)
    {
        listContents.push_back(currentPtr->getItem());
        currentPtr = currentPtr->getNext();
    }

    return listContents;
}

// destructor
// goes through each node and deletes them
template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    // create ptr to headPtr & create a temp ptr to the next node
    Node<ItemType> *currentPtr = headPtr;
    Node<ItemType> *nextPtr;

    // while currentPtr does not equal nullptr
    // goes through each node and deletes them
    while (currentPtr != nullptr)
    {
        nextPtr = currentPtr->getNext();
        delete currentPtr;
        currentPtr = nextPtr;
    }

    // final cleanup
    headPtr = nullptr;
    numItems = 0;

} // end destructor
