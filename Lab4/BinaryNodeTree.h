#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include <memory>

template <class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    auto getEntryHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType &target) const;

    // Recursively adds a new node to the tree in a left/right fashion to keep tree balanced.
    auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                     std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

    // Removes the target value from the tree.
    auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType &target, bool &success);

    // Copies values up the tree to overwrite value in current node until
    // a leaf is reached; the leaf is then removed, since its value is stored in the parent.
    auto moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

    // Recursively searches for target value.
    auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                  const ItemType &target, bool &isSuccessful) const;

    // Recursively deletes all nodes from the tree.
    //void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinaryNodeTree();
    BinaryNodeTree(const ItemType &rootItem);
    BinaryNodeTree(const ItemType &rootItem,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
    virtual ~BinaryNodeTree();

    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------

    bool add(const ItemType &newData); // Adds an item to the tree
    bool remove(const ItemType &data); // Removes specified item from the tree

    ItemType getEntry(const ItemType &anEntry) const;
}; // end BinaryNodeTree

#include "BinaryNodeTree.cpp"
#endif