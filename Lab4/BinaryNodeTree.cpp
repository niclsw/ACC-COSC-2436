#include "BinaryNodeTree.h"
#include "iostream"

BinaryNodeTree::BinaryNodeTree() : root(nullptr) {}

BinaryNodeTree::BinaryNodeTree(std::shared_ptr<EmployeeInfo> root) : root(root) {}

// helper functions

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

bool BinaryNodeTree::removeHelper(std::shared_ptr<EmployeeInfo> node, int id) {
    bool result{false};

    if (node == nullptr) {
        result = false;
    }
    else if (id < node->getId()) {
        removeHelper(node->getLeft(), id);
    }
    else if (id > node->getId()) {
        removeHelper(node->getRight(), id);
    }
    else {
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            node = nullptr;
        }
        else if (node->getLeft() == nullptr) {
            node = node->getRight();
        }
        else if (node->getRight() == nullptr) {
            node = node->getLeft();
        }
        else {
            std::shared_ptr<EmployeeInfo> temp = node->getLeft();
            while (temp->getRight() != nullptr) {
                temp = temp->getRight();
            }
            node->setId(temp->getId());
            node->setName(temp->getName());
            removeHelper(node->getLeft(), temp->getId());
        }
        result = true;
    }

    return result;
}

std::shared_ptr<EmployeeInfo> BinaryNodeTree::findHelper(std::shared_ptr<EmployeeInfo> node, int id) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (id < node->getId()) {
        return findHelper(node->getLeft(), id);
    }
    else if (id > node->getId()) {
        return findHelper(node->getRight(), id);
    }
    else {
        return node;
    }
}

void BinaryNodeTree::print() {
    printHelper("", root, false);
}

void BinaryNodeTree::printHelper(const std::string &prefix, const std::shared_ptr<EmployeeInfo> node, bool isLeft) {
    // printing binary node tree
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "[__" );

        // print the value of the node with ID and name
        std::cout << node->getId() << " - " << node->getName() << std::endl;

        // enter the next tree level - left and right branch
        printHelper( prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
        printHelper( prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
    }
}

void BinaryNodeTree::insert(const std::string &name, const int &id) {

    std::shared_ptr<EmployeeInfo> newNode = std::make_shared<EmployeeInfo>(id, name);


    insertHelper(root, newNode);
}

bool BinaryNodeTree::remove(int id) {

    bool result = removeHelper(root, id);

    return result;
}

std::shared_ptr<EmployeeInfo> BinaryNodeTree::find(int id) {
    return findHelper(root, id);
}