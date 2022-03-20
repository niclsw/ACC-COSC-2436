/** @file StackInterface.h */

#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

template <class ItemType>
class StackInterface
{
public:
	// returns a boolean value true if the stack is empty
	// otherwise it will return false
	virtual bool isEmpty() const = 0;

	// pushes variable to stack
	virtual bool push(const ItemType &newEntry) = 0;

	// LIFO deletes last item in the stack
	virtual bool pop() = 0;

	// Returns the most recent item in the stack
	virtual ItemType peek() const = 0;

	// Destructor
	virtual ~StackInterface() {}
}; // end StackInterface

#endif
