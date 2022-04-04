#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "LinkedList.h"

int main()
{
    // Initialize variables and the LinkedList
    std::fstream file;
    std::string fileName{""}, line{""};
    int lineCount{0};
    LinkedList<std::string> list;

    // get file name from user
    std::cout << "Enter file name: ";
    std::cin >> fileName;

    // open file
    file.open(fileName, std::ios::in);

    // if file is openable pull contents into LinkedList
    if (file)
    {

        // read file into LinkedList
        while (!file.eof())
        {
            // getline from file and send to list object using addNode method
            std::getline(file, line);
            list.addNode(line);

            // increment line count
            lineCount++;
        }

        std::cout << "\nFile opened successfully and read " << lineCount << " lines from " << fileName << std::endl;
    }
    else
    {
        std::cout << "File failed to open" << std::endl;
    }

    // get list contents from toVector in list
    std::vector<std::string> listContents = list.toVector();

    // print out list contents
    for (auto i : listContents)
        std::cout << i << std::endl;

    std::cout << "\nList Size: " << list.getSize() << std::endl;
    std::cout << "Line Count from File: " << lineCount << std::endl;

    // close file
    file.close();

    return 0;
}