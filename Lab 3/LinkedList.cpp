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
    bool success{false};
    if (headPtr == nullptr)
    {
        headPtr = new Node<ItemType>(newEntry);
        success = true;
        numItems++;
    }
    else
    {
        Node<ItemType> *curPtr = headPtr;
        Node<ItemType> *prevPtr = nullptr;

        // while new entry is less than current node value, continue through the list until
        // it finds a value in the list that is greater or less than the new entry
        // && curPtr->getNext() != nullptr
        while (curPtr->getItem() > newEntry)
        {

            prevPtr = curPtr;
            curPtr = curPtr->getNext();

            // if getNext > newEntry, place newEntry before next node
            if (curPtr->getItem() > newEntry)
            {
                // create new node pointer inbetween previous node and next node
                Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry, curPtr->getNext());
                prevPtr->setNext(newNodePtr);
                success = true;
                numItems++;
            }
            // if getNext < newEntry, place newEntry after current node
            else if (curPtr->getItem() < newEntry)
            {
                // create new node pointer inbetween previous node and next node
                Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry, curPtr);
                prevPtr->setNext(newNodePtr);
                success = true;
                numItems++;
            }
        }
        // if an entry is less than the headPtr
        // if (newEntry < headPtr->getItem())
        // {

        //     // Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry, headPtr);
        //     // headPtr = newNodePtr;
        //     // success = true;
        //     // numItems++;
        // }
        // else
        // {
        // Node<ItemType> *curPtr = headPtr;
        // Node<ItemType> *prevPtr = nullptr;
        // while (curPtr != nullptr && newEntry > curPtr->getItem())
        // {
        //     prevPtr = curPtr;
        //     curPtr = curPtr->getNext();
        // }
        // if (curPtr == nullptr)
        // {
        //     prevPtr->setNext(new Node<ItemType>(newEntry));
        //     success = true;
        // }
        // else
        // {
        //     Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry, curPtr);
        //     prevPtr->setNext(newNodePtr);
        //     success = true;
        // }
        // numItems++;
        // }
    }

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
