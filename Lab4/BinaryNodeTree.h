#ifndef BINARY_NODE_TREE_H
#define BINARY_NODE_TREE_H

#include <memory>

#include "EmployeeInfo.h"

class BinaryNodeTree
{
private:
    // smart pointer to EmployeeInfo root
    std::shared_ptr<EmployeeInfo> root;

    // helper function to insert a new EmployeeInfo into the tree
    void insertHelper(std::shared_ptr<EmployeeInfo> node, std::shared_ptr<EmployeeInfo> newNode);

    // helper function to remove an EmployeeInfo from the tree
    bool removeHelper(std::shared_ptr<EmployeeInfo> node, int id);

    // helper function to find an EmployeeInfo in the tree
    std::shared_ptr<EmployeeInfo> findHelper(std::shared_ptr<EmployeeInfo> node, int id);

    // helper function to print the tree
    void printHelper(const std::string &prefix, const std::shared_ptr<EmployeeInfo> node, bool isLeft);

public:
    // constructor
    BinaryNodeTree();
    BinaryNodeTree(std::shared_ptr<EmployeeInfo> root);
    BinaryNodeTree(std::shared_ptr<EmployeeInfo> root, std::shared_ptr<EmployeeInfo> left, std::shared_ptr<EmployeeInfo> right);

    // destructor
    ~BinaryNodeTree() {}

    // methods to insert a new EmployeeInfo into the tree
    void insert(const std::string &name, const int &id);

    // methods to remove an EmployeeInfo from the tree
    bool remove(int id);

    // methods to find an EmployeeInfo in the tree
    std::shared_ptr<EmployeeInfo> find(int id);

    // methods to print the tree
    void print();
};

#include "BinaryNodeTree.cpp"

#endif