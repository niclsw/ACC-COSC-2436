#ifndef _NODE
#define _NODE

template <class ItemType>
class Node
{
private:
    ItemType line;
    Node<ItemType> *next;

public:
    Node();                                                    // default constructor
    Node(const ItemType &aLine);                               // constructor with an line          
    Node(const ItemType &aLine, Node<ItemType> *nextNodePtr);  // constructor with an line and a next pointer
    void setItem(const ItemType &aLine);                       // mutator for line
    void setNext(Node<ItemType> *nextNodePtr);                 // mutator for next
    ItemType getItem() const;                                  // accessor for line            
    Node<ItemType> *getNext() const;                           // accessor for next
}; // end Node

#include "Node.cpp"
#endif