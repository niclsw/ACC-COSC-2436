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
    LinkedList();                           // default constructor
    virtual ~LinkedList();                  // destructor
    bool addNode(const ItemType &newEntry); // adds a node to the list
    int getSize() const;                    // returns the number of items in the list
    std::vector<ItemType> toVector();       // converts the list to a vector
};

#include "LinkedList.cpp"
#endif