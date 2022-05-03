#include "ListQueue.h"

template<class ItemType>
ListQueue<ItemType>::ListQueue()
{
    listPtr = new LinkedList<ItemType>();
} // end default constructor

template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue &aQueue) : listPtr(aQueue.listPtr)
{
} // end copy constructor

template<class ItemType>
ListQueue<ItemType>::~ListQueue()
{
    //delete listPtr;
} // end destructor

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
    return listPtr->isEmpty();
} // end isEmpty

template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    return listPtr->insert(listPtr->getLength() + 1, newEntry);
} // end enqueue

template<class ItemType>
bool ListQueue<ItemType>::dequeue()
{
    return listPtr->remove(1);
} // end dequeue

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
    if (listPtr->isEmpty())
    {
        throw PrecondViolatedExcep("peekFront() called with empty queue.");
    }
    else
    {
        return listPtr->getEntry(1);
    }
} // end peekFront

