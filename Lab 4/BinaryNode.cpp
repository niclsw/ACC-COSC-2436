#include "BinaryNode.h"

template <class ItemType>
BinaryNode<ItemType>::BinaryNode() : leftPtr(nullptr), rightPtr(nullptr)
{
} // end default constructor

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const int &anID, const std::string &aName) : ID(aID), name(aName), leftPtr(nullptr), rightPtr(nullptr)
{
} // end constructor

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const int &aID, const std::string &aName, const std::shared_ptr<BinaryNode<ItemType>> leftPtr, const std::shared_ptr<BinaryNode<ItemType>> rightPtr) : ID(aID), name(aName), leftPtr(leftPtr), rightPtr(rightPtr)
{
} // end constructor

template <class ItemType>
void BinaryNode<ItemType>::setLeftPtr(const std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
    this->leftPtr = leftPtr;
} // end setLeftPtr

template <class ItemType>
void BinaryNode<ItemType>::setRightPtr(const std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
    this->rightPtr = rightPtr;
} // end setRightPtr

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftPtr() const
{
    return leftPtr;
} // end getLeftPtr

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightPtr() const
{
    return rightPtr;
} // end getRightPtr

template <class ItemType>
int BinaryNode<ItemType>::getID() const
{
    return ID;
} // end getID

template <class ItemType>
std::string BinaryNode<ItemType>::getName() const
{
    return name;
} // end getItem