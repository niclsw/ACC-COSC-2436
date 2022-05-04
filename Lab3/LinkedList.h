#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <vector>
#include <string>

#include "ListInterface.h"
#include "Node.h"

template <class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType> *headPtr; // Pointer to first node in the chain
    int numItems;            // Current number of entries in list

public:
    LinkedList();                           // Default constructor
    LinkedList(const ItemType *headPtr);    // Constructor with a head pointer
    virtual ~LinkedList();                  // Destructor
    bool addNode(const ItemType &newEntry); // Adds a node to the list
    int getSize() const;                    // Returns the size of the list
    std::vector<ItemType> toVector() const; // Returns the list as a vector
};

#include "LinkedList.cpp"
#endif