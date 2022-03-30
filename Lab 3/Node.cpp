#include <string>

#include "Node.h"

// default constructor
template <class ItemType>
Node<ItemType>::Node() {
    next = nullptr;
}

// constructor which takes in a line value
template <class ItemType>
Node<ItemType>::Node(const ItemType &aLine) {
    line = aLine;
    next = nullptr;
}

// constructor which takes in a line value and a pointer to the next node
template <class ItemType>
Node<ItemType>::Node(const ItemType &aLine, Node<ItemType> *nextNodePtr) {
    line = aLine;
    next = nextNodePtr;
}

// setter for line value
template <class ItemType>
void Node<ItemType>::setLine(const ItemType &aLine) {
    line = aLine;
}

// setter for pointer to next node
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr) {
    next = nextNodePtr;
}

// getter for line value
template <class ItemType>
ItemType Node<ItemType>::getLine() const {
    return line;
}

// getter for pointer to next node
template <class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const {
    return next;
}