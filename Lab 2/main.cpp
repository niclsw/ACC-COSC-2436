#include <iostream>
#include <fstream>
#include <string>


int main() {

    std::string fileName{""};
    std::fstream file;

    // Do while file error
    do {
        // Accept user input for file name
        std::cout << "Enter File Name: ";
        std::cin >> fileName;

        // Open the file
        file.open(fileName, std::ios::in);

        // Display error if error opening file
        if(!file) { std::cout << "Error opening file" << std::endl; }
    } while (!file);


    return 0;
    
}