#include "EmployeeInfo.h"

EmployeeInfo::EmployeeInfo() : id(0), name("") {}

EmployeeInfo::EmployeeInfo(int id, std::string name) : id(id), name(name) {}

EmployeeInfo::~EmployeeInfo() {}

// methods to get and set the id and name

int EmployeeInfo::getId() { return id; }

std::string EmployeeInfo::getName() { return name; }

void EmployeeInfo::setId(int id) { this->id = id; }

void EmployeeInfo::setName(std::string name) { this->name = name; }

// methods to get and set the left and right pointers

std::shared_ptr<EmployeeInfo> EmployeeInfo::getLeft() { return left; }

std::shared_ptr<EmployeeInfo> EmployeeInfo::getRight() { return right; }

void EmployeeInfo::setLeft(std::shared_ptr<EmployeeInfo> left) { this->left = left; }

void EmployeeInfo::setRight(std::shared_ptr<EmployeeInfo> right) { this->right = right; }
