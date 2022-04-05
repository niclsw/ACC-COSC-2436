#include <vector>
#include <string>

#include "LinkedList.h"

template <class ItemType>
LinkedList<ItemType>::LinkedList()
{
    headPtr = nullptr;
    numItems = 0;
} // end default constructor

template <class ItemType>
bool LinkedList<ItemType>::addNode(const ItemType &newEntry)
{
    // bool value to return and bool for if newEntry is duplicate
    bool success{false}, duplicate{false};

    // if Node headptr is nullptr, create new Node and add it to end of list
    if (headPtr == nullptr)
    {
        headPtr = new Node<ItemType>(newEntry);
        success = true;
    }
    // if Node headptr is not nullptr, determine where to put it in node
    else
    {
        // create previousNodePtr for temp storage
        // create currentNodePtr to traverse linked list
        Node<ItemType> *previousNodePtr = nullptr;
        Node<ItemType> *currentNodePtr = headPtr;

        // loop through list until new node is placed in correct position
        // >= to determine if currentNode-getItem() is greater or equal to newEntry
        while (currentNodePtr != nullptr && newEntry >= currentNodePtr->getItem())
        {
            // assign previous to currentNodePtr
            // currentNodePtr is assigned the next node in linked list
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
            // Now we need to set memory asside for new node
            Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);

            // if previous ptr is nullptr, new node ptr next is set to headPtr
            if (previousNodePtr == nullptr)
            {
                newNodePtr->setNext(headPtr);
                headPtr = newNodePtr;
            }
            // if currentNodePtr is last in list with a nullptr, set new node at end of list
            else if (currentNodePtr == nullptr)
            {
                previousNodePtr->setNext(newNodePtr);
            }
            // if not last in list, set newNodePtr inbetween current and previous ptrs
            // already determined newEntry is not greater than currentNodePtr
            else
            {
                previousNodePtr->setNext(newNodePtr);
                newNodePtr->setNext(currentNodePtr);
            }

            // set success to true
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
std::vector<ItemType> LinkedList<ItemType>::toVector() const
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
