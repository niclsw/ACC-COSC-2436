#include <iostream>
#include <memory>
#include "BinaryNodeTree.h"

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
} // end default constructor

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem))
{
} // end constructor

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftPtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightPtr) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, leftPtr, rightPtr))
{
} // end constructor

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
    destroyTree(rootPtr);
} // end destructor

template <class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if (subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else
    {
        if (subTreePtr->getItem() > newNodePtr->getItem())
        {
            subTreePtr->setLeftChildPtr(balancedAdd(subTreePtr->getLeftChildPtr(), newNodePtr));
        }
        else
        {
            subTreePtr->setRightChildPtr(balancedAdd(subTreePtr->getRightChildPtr(), newNodePtr));
        }
        return subTreePtr;
    }
}

template <class ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if (subTreePtr == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getLeftChildPtr()->getItem() > subTreePtr->getItem())
        {
            subTreePtr->setItem(subTreePtr->getLeftChildPtr()->getItem());
            subTreePtr->setLeftChildPtr(moveValuesUpTree(subTreePtr->getLeftChildPtr()));
        }
        else if (subTreePtr->getRightChildPtr() != nullptr && subTreePtr->getRightChildPtr()->getItem() > subTreePtr->getItem())
        {
            subTreePtr->setItem(subTreePtr->getRightChildPtr()->getItem());
            subTreePtr->setRightChildPtr(moveValuesUpTree(subTreePtr->getRightChildPtr()));
        }
        else
        {
            return subTreePtr;
        }
    }
}

// template <class ItemType>
// void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
// {
//     if (subTreePtr != nullptr)
//     {
//         destroyTree(subTreePtr->getLeftChildPtr());
//         destroyTree(subTreePtr->getRightChildPtr());
//         subTreePtr->setLeftChildPtr(nullptr);
//         subTreePtr->setRightChildPtr(nullptr);
//     }
// }

template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType &newData)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType &data)
{
    rootPtr = removeValue(rootPtr, data);
}

template <class ItemType>
auto BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType &target, bool &success)
{
    if (subTreePtr == nullptr)
    {
        success = false;
        return nullptr;
    }
    if (subTreePtr->getItem() == target)
    {
        subTreePtr = moveValuesUpTree(subTreePtr);
        success = true;
        return subTreePtr;
    }
    else
    {
        if (subTreePtr->getItem() > target)
        {
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
        }
        else
        {
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
        }
    }
    return subTreePtr;
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType &anEntry) const
{
    return getEntryHelper(rootPtr, anEntry);
}

template <class ItemType>
auto BinaryNodeTree<ItemType>::getEntryHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType &target) const
{
    ItemType result;
    if (subTreePtr == nullptr)
    {
        result = nullptr;
    }
    else if (subTreePtr->getItem() == target)
    {
        result = subTreePtr->getItem();
    }
    else if (subTreePtr->getItem() > target)
    {
        result = getEntryHelper(subTreePtr->getLeftChildPtr(), target);
    }
    else
    {
        result = getEntryHelper(subTreePtr->getRightChildPtr(), target);
    }
    return result;
}