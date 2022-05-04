#ifndef BINARY_TREE_INTERFACE
#define BINARY_TREE_INTERFACE

template <class ItemType>
class BinaryTreeInterface
{
    // public
    //------------------------------------------------------------
    virtual bool add(const ItemType &newData) = 0;
    virtual bool remove(const ItemType &data) = 0;
    virtual ItemType getEntry(const ItemType &anEntry) const = 0;

    virtual ~BinaryTreeInterface() {}

}; // end BinaryTreeInterface
#endif