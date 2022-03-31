#ifndef _NODE
#define _NODE

template <class ItemType>
class Node
{
private:
    ItemType item;
    Node<ItemType> *next;

public:
    Node();
    Node(const ItemType &aItem);
    Node(const ItemType &aItem, Node<ItemType> *nextNodePtr);
    void setItem(const ItemType &aItem);
    void setNext(Node<ItemType> *nextNodePtr);
    ItemType getItem() const;
    Node<ItemType> *getNext() const;
}; // end Node

#include "Node.cpp"
#endif