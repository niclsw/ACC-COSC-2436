/** ADT stack: Link-based implementation.
 @file LinkedStack.h */

#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "StackInterface.h"
#include "Node.h"

template <class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
	Node<ItemType> *topPtr;

public:
	LinkedStack();
	LinkedStack(const LinkedStack<ItemType> &aStack);
	LinkedStack<ItemType> &operator=(const LinkedStack<ItemType> &aStack);
	virtual ~LinkedStack();
	bool isEmpty() const;
	bool push(const ItemType &newItem);
	bool pop();
	ItemType peek() const;
}; // end LinkedStack

#include "LinkedStack.cpp"
#endif
