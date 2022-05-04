#ifndef BINARY_NODE
#define BINARY_NODE

#include <memory>
#include <string>

template <class ItemType>
class BinaryNode
{
private:
    int ID;
    std::string name;
    std::shared_ptr<BinaryNode<ItemType>> leftPtr;
    std::shared_ptr<BinaryNode<ItemType>> rightPtr;

public:
    BinaryNode();
    BinaryNode(const int &aID, const std::string &aName);
    BinaryNode(const int &aID, const std::string &aName, const std::shared_ptr<BinaryNode<ItemType>> leftPtr, const std::shared_ptr<BinaryNode<ItemType>> rightPtr);

    int getID() const;
    std::string getName() const;

    void setLeftPtr(const std::shared_ptr<BinaryNode<ItemType>> leftPtr);
    void setRightPtr(const std::shared_ptr<BinaryNode<ItemType>> rightPtr);
    std::shared_ptr<BinaryNode<ItemType>> getLeftPtr() const;
    std::shared_ptr<BinaryNode<ItemType>> getRightPtr() const;

}; // end BinaryNode
#endif