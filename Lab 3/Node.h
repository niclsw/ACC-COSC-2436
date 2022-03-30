#ifndef _NODE
#define _NODE

template <class ItemType>
class Node : public LinkedList
{
private:
    ItemType line;
    Node<ItemType> *next;

public:
    Node();
    Node(const ItemType &aLine);
    Node(const ItemType &aLine, Node<ItemType> *nextNodePtr);
    void setLine(const ItemType &aLine);
    void setNext(Node<ItemType> *nextNodePtr);
    ItemType getLine() const;
    Node<ItemType> *getNext() const;
}; // end Node

#include "Node.cpp"
#endif