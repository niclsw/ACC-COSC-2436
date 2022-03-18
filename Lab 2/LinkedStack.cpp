/** @file LinkedStack.cpp */

#include <cassert>
#include "LinkedStack.h"

template <class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
} // end default constructor

template <class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType> &aStack)
{
	Node<ItemType> *origChainPtr = aStack->topPtr;
	if (origChainPtr == nullptr)
		topPtr = nullptr;
	else
	{
		topPtr = new Node<ItemType>();
		topPtr->setItem(origChainPtr->getItem());
		Node<ItemType> *newChainPtr = topPtr;
		while (origChainPtr != nullptr)
		{
			origChainPtr = origChainPtr->getNext();
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType> *newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();
		} // end while
		newChainPtr->setNext(nullptr);
	} // end if
} // end copy constructor

template <class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	while (!isEmpty())
		pop();
} // end destructor

template <class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
} // end isEmpty

template <class ItemType>
bool LinkedStack<ItemType>::push(const ItemType &newItem)
{
	Node<ItemType> *newNodePtr = new Node<ItemType>(newItem, topPtr);
	topPtr = newNodePtr;
	newNodePtr = nullptr;
	return true;
} // end push

template <class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		Node<ItemType> *nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		result = true;
	} // end if
	return result;
} // end pop

template <class ItemType>
ItemType LinkedStack<ItemType>::peek() const
{
	assert(!isEmpty()); // Enforce precondition
	return topPtr->getItem();
} // end getTop

// end of implementation file
