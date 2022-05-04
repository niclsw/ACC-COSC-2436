#ifndef BINARY_TREE_INTERFACE
#define BINARY_TREE_INTERFACE

template <class ItemType>
class BinaryTreeInterface
{
    // public
    //------------------------------------------------------------
    virtual bool isEmpty() const = 0;
    virtual int getHeight() const = 0;
    virtual int getNumberOfNodes() const = 0;
    virtual ItemType getRootData() const = 0;
    virtual void setRootData(const ItemType &newData) = 0;
    virtual bool add(const ItemType &newData) = 0;
    virtual bool remove(const ItemType &data) = 0;
    virtual void clear() = 0;
    virtual ItemType getEntry(const ItemType &anEntry) const = 0;
    virtual bool contains(const ItemType &anEntry) const = 0;

    virtual ~BinaryTreeInterface() {}

}; // end BinaryTreeInterface
#endif