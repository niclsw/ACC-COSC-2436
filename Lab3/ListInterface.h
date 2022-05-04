
#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template <class ItemType>
class ListInterface
{
public:
    // adds an item to the list. will return true if successful, false otherwise
    // INPUT  : Reference to newEntry
    // OUTPUT : True if successful, false otherwise
    virtual bool addNode(const ItemType &newEntry) = 0;

    // accessor for the number of items in the list
    // INPUT  : None
    // OUTPUT : Number of items in the list
    virtual int getSize() const = 0;

    // converts the list to a vector and returns as a vector
    // INPUT  : None
    // OUTPUT : Vector of list contents
    virtual std::vector<ItemType> toVector() const = 0;

    // destructor for the list interface
    virtual ~ListInterface() {}
};

#endif