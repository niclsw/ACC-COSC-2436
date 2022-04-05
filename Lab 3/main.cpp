#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "LinkedList.h"

// Prototypes
std::fstream getFile(std::string &fileName);
void readToList(LinkedList<std::string> &list, std::fstream &file, int &lineCount);
void displayList(const LinkedList<std::string> &list);

int main()
{
    // Initialize variables
    std::string fileName{""};
    int lineCount{0};

    // Initialize LinkedList object
    LinkedList<std::string> list;

    // Initialize file object and get contents from getFile()
    std::fstream file = getFile(fileName);

    // if file is openable pull contents into LinkedList
    if (file)
    {
        // Send file to readToList function
        readToList(list, file, lineCount);

        // Display list
        std::cout << "\nList Bag Contents from " + fileName + ":" << std::endl;
        displayList(list);

        // Display final line counts
        std::cout << "\nList Size: " << list.getSize() << std::endl;
        std::cout << "Line Count from File: " << lineCount << std::endl;
    }
    else
    {
        std::cout << "Error - Program Ending..." << std::endl;
    }

    // cleanup
    file.close();
    return 0;

} // end main

std::fstream getFile(std::string &fileName)
{

    // initialize file stream
    std::fstream file;

    // get file name from user
    std::cout << "Enter file name: ";
    std::cin >> fileName;

    // open file
    file.open(fileName, std::ios::in);

    // Error check the file open. If it fails, print an error message.
    try
    {
        if (!file)
            throw std::invalid_argument("File failed to open");
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
    }

    return file;
} // end getFile

void readToList(LinkedList<std::string> &list, std::fstream &file, int &lineCount)
{
    // initialize variables
    std::string line;

    // while there is a line in the file, add it to the list
    while (std::getline(file, line))
    {
        // increment file line count
        lineCount++;

        // add line to list
        list.addNode(line);
    }
} // end readToList

void displayList(const LinkedList<std::string> &list)
{
    // get list contents from toVector in list
    std::vector<std::string> listContents = list.toVector();

    // print out list contents
    for (auto i : listContents)
        std::cout << i << std::endl;

} // end displayList