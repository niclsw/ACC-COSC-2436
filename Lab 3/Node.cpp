#include <string>

#include "Node.h"

// default constructor
template <class ItemType>
Node<ItemType>::Node()
{
    line = "";
    next = nullptr;
} // end default constructor

// constructor which takes in a Item value
template <class ItemType>
Node<ItemType>::Node(const ItemType &aLine)
{
    line = aLine;
    next = nullptr;
} // end constructor

// constructor which takes in a Item value and a pointer to the next node
template <class ItemType>
Node<ItemType>::Node(const ItemType &aLine, Node<ItemType> *nextNodePtr)
{
    line = aLine;
    next = nextNodePtr;
} // end constructor

// setter for Item value
template <class ItemType>
void Node<ItemType>::setItem(const ItemType &aLine)
{
    line = aLine;
} // end setItem

// setter for pointer to next node
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr)
{
    next = nextNodePtr;
} // end setNext

// getter for Item value
template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return line;
} // end getItem

// getter for pointer to next node
template <class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const
{
    return next;
} // end getNext