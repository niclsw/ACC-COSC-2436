#ifndef _LIST_QUEUE
#define _LIST_QUEUE

// includes
#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ListQueue : public QueueInterface<ItemType>
{

private:
    LinkedList<ItemType> list;

public:
    ListQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const throw(PrecondViolatedExcep);
};
#include "ListQueue.cpp"
#endif