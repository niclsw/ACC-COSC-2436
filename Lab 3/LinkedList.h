
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"

template <class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain
    int numItems;            // Current number of entries in list

public:
    LinkedList();
    LinkedList(ItemType *headPtr);
    ~LinkedList();
    bool addNode(const ItemType& newEntry);
    int getSize() const;
    ItemType toVector();
};

#include "LinkedList.cpp"
#endif