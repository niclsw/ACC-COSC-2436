#include <iostream>
#include <string>
#include "Simple.h"

int main() {

    Simple<int> intObj(12312);
    Simple<std::string> strObj("Test");

    int value;

    std::cout << "Initial Value: " << intObj.getItem() << std::endl;

    std::cout << "Value: ";
    std::cin >> value;
    intObj.setItem(value);
    std::cout << "New Value: " << intObj.getItem();

    return 0;
}