
#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template <class ItemType>
class ListInterface
{
public:
    // returns a boolean value true if the list is empty
    // otherwise it will return false
    virtual bool addNode(const ItemType &newEntry) = 0;

    // Gets the number of items in the list
    virtual int getSize() const = 0;

    virtual std::vector<ItemType> toVector() = 0;

    // destructor
    virtual ~ListInterface() {}
};

#endif