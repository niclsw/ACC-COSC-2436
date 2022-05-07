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
    // if node is not nullptr place newnode in the correct place
    else if (newNode->getId() < node->getId()) {
        if (node->getLeft() == nullptr) {
            node->setLeft(newNode);
        }
        else {
            insertHelper(node->getLeft(), newNode);
        }
    }
    else {
        if (node->getRight() == nullptr) {
            node->setRight(newNode);
        }
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
    printHelper(root);
}

void BinaryNodeTree::printHelper(std::shared_ptr<EmployeeInfo> node) {
    while (node != nullptr) {
        std::cout << node->getId() << " " << node->getName() << std::endl;
        node = node->getRight();
    }
}

void BinaryNodeTree::insert(std::string &name, int &id) {

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