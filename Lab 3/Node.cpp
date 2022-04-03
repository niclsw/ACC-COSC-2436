#include <string>

#include "Node.h"

// default constructor
template <class ItemType>
Node<ItemType>::Node() {
    item{""}
    next{nullptr};
}

// constructor which takes in a Item value
template <class ItemType>
Node<ItemType>::Node(const ItemType &aItem) {
    item = aItem;
    next = nullptr;
}

// constructor which takes in a Item value and a pointer to the next node
template <class ItemType>
Node<ItemType>::Node(const ItemType &aItem, Node<ItemType> *nextNodePtr) {
    item = aItem;
    next = nextNodePtr;
}

// setter for Item value
template <class ItemType>
void Node<ItemType>::setItem(const ItemType &aItem) {
    item = aItem;
}

// setter for pointer to next node
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr) {
    next = nextNodePtr;
}

// getter for Item value
template <class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

// getter for pointer to next node
template <class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const {
    return next;
}