#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <string>

class EmployeeInfo
{
private:
    int id;
    std::string name;

    // left and right pointers
    std::shared_ptr<EmployeeInfo> left;
    std::shared_ptr<EmployeeInfo> right;

public:
    EmployeeInfo();
    EmployeeInfo(int id, std::string name);
    ~EmployeeInfo();

    int getId();
    std::string getName();
    void setId(int id);
    void setName(std::string name);

    std::shared_ptr<EmployeeInfo> getLeft();
    std::shared_ptr<EmployeeInfo> getRight();

    void setLeft(std::shared_ptr<EmployeeInfo> left);
    void setRight(std::shared_ptr<EmployeeInfo> right);
};

#include "EmployeeInfo.cpp"

#endif