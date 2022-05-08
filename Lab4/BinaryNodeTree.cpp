#include "BinaryNodeTree.h"
#include "iostream"

BinaryNodeTree::BinaryNodeTree() : root(nullptr) {}

BinaryNodeTree::BinaryNodeTree(std::shared_ptr<EmployeeInfo> root) : root(root) {}

// helper private functions
void BinaryNodeTree::insertHelper(std::shared_ptr<EmployeeInfo> node, std::shared_ptr<EmployeeInfo> newNode) {
    // if node is nullptr place newnode 
    if (node == nullptr) {
        root = newNode;
    }
    // if node is not nullptr
    else if (newNode->getId() < node->getId()) {
        // if node's left is nullptr place newnode
        if (node->getLeft() == nullptr) {
            node->setLeft(newNode);
        }
        // if node's left is not nullptr recurse left
        else {
            insertHelper(node->getLeft(), newNode);
        }
    }
    // if node is not nullptr & newnode's id is greater than node's id
    else {
        // if node's right is nullptr place newnode
        if (node->getRight() == nullptr) {
            node->setRight(newNode);
        }
        // if node's right is not nullptr recurse right
        else {
            insertHelper(node->getRight(), newNode);
        }
    }
}

std::shared_ptr<EmployeeInfo> BinaryNodeTree::findHelper(std::shared_ptr<EmployeeInfo> node, const int &id) {
    // recursive implementation of find
    if (node == nullptr) {
        return nullptr;
    }
    else if (id < node->getId()) {
        return findHelper(node->getLeft(), id);
    }
    else if (id > node->getId()) {
        return findHelper(node->getRight(), id);
    }
    
    return (node->getId() == id) ? node : nullptr;
}

void BinaryNodeTree::printHelper(const std::string &prefix, const std::shared_ptr<EmployeeInfo> node, bool isLeft) {
    // printing binary node tree
    if( node != nullptr )
    {
        std::cout << prefix;

        // set prefixes if node is left or right and check if node is root and assign special prefix if it is
        // if isLeft prefix is "├--" and if not prefix is "|__"
        std::cout << (getRoot()->getId() == node->getId() ? "RT-> " : (isLeft ? "|--" : "|__" ));

        // print the value of the node with ID and name
        std::cout << node->getId() << " - " << node->getName() << std::endl;

        // enter the next tree level - left and right branch
        // | is down
        printHelper(prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
        printHelper(prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
    }
}

std::shared_ptr<EmployeeInfo> BinaryNodeTree::getRoot() const {
    return root;
}

// public functions
void BinaryNodeTree::print() {
    // probably won't come accross this case but if root is not nullptr
    if (root != nullptr) {
        // send empty prefix string, root, and false to printHelper
        printHelper("", root, false);
    }
    else {
        std::cout << "Tree is empty" << std::endl;
    }
}



void BinaryNodeTree::insert(const std::string &name, const int &id) {

    // create new EmployeeInfo object
    std::shared_ptr<EmployeeInfo> newNode = std::make_shared<EmployeeInfo>(id, name);

    // call insertHelper function to insert new EmployeeInfo object
    insertHelper(root, newNode);
}

std::shared_ptr<EmployeeInfo> BinaryNodeTree::find(const int &id) {
    // call findHelper function to find EmployeeInfo object target ID
    return findHelper(root, id);
}