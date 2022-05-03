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
    makeEmpty();
} // end destructor

template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
    return rootPtr == nullptr;
} // end isEmpty

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
    return getHeightHelper(rootPtr);
} // end getHeight

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(const std::shared_ptr<BinaryNode<ItemType>> nodePtr) const
{
    if (nodePtr == nullptr)
        return 0;
    else
    {
        int leftHeight = getHeightHelper(nodePtr->getLeftPtr());
        int rightHeight = getHeightHelper(nodePtr->getRightPtr());
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    } // end if
} // end getHeightHelper

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
    return getNumberOfNodesHelper(rootPtr);
} // end getNumberOfNodes

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(const std::shared_ptr<BinaryNode<ItemType>> nodePtr) const
{
    if (nodePtr == nullptr)
        return 0;
    else
    {
        int leftNumber = getNumberOfNodesHelper(nodePtr->getLeftPtr());
        int rightNumber = getNumberOfNodesHelper(nodePtr->getRightPtr());
        return leftNumber + rightNumber + 1;
    } // end if
} // end getNumberOfNodesHelper

template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{
    preorder(visit, rootPtr);
} // end preorderTraverse

template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType &), const std::shared_ptr<BinaryNode<ItemType>> nodePtr) const
{
    if (nodePtr != nullptr)
    {
        ItemType item = nodePtr->getItem();
        visit(item);
        preorder(visit, nodePtr->getLeftPtr());
        preorder(visit, nodePtr->getRightPtr());
    } // end if
} // end preorder

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
    inorder(visit, rootPtr);
} // end inorderTraverse

template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType &), const std::shared_ptr<BinaryNode<ItemType>> nodePtr) const
{
    if (nodePtr != nullptr)
    {
        inorder(visit, nodePtr->getLeftPtr());
        ItemType item = nodePtr->getItem();
        visit(item);
        inorder(visit, nodePtr->getRightPtr());
    } // end if
} // end inorder

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
    postorder(visit, rootPtr);
} // end postorderTraverse

template <class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType &), const std::shared_ptr<BinaryNode<ItemType>> nodePtr) const
{
    if (nodePtr != nullptr)
    {
        postorder(visit, nodePtr->getLeftPtr());
        postorder(visit, nodePtr->getRightPtr());
        ItemType item = nodePtr->getItem();
        visit(item);
    } // end if
} // end postorder