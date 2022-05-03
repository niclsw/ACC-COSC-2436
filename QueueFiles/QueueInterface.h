#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE

#include "PrecondViolatedExcep.h"

template<class ItemType>
class QueueInterface
{
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const ItemType& newEntry) = 0;
    virtual bool dequeue() = 0;
    virtual ItemType peekFront() const throw(PrecondViolatedExcep) = 0;
};
#endif
