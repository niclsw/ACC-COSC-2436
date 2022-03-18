//------------------------------------------------------------------
// Name: Nick Walker n2148996
// Class: COSC-2436-003
// Description: This program will ask the user for a file name and load
// each bid onto the stack. The winning bid will be shown at the end of
// the program.
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedStack.h"

int main()
{

    std::string fileName{""}, bid{""}, itemName{""};
    std::fstream auctionFile;
    LinkedStack<std::string> theStack;

    // Do while file error

    // Accept user input for file name
    std::cout << "Enter File Name: ";
    std::cin >> fileName;

    // Open the file
    auctionFile.open(fileName, std::ios::in);

    // Display error if error opening file
    if (!auctionFile)
    {
        std::cout << "Error opening file" << std::endl;
    }
    else
    {
        // Grab first line which will always be the items name
        std::getline(auctionFile, itemName);
        std::cout << "The Item up for Bid: " << itemName << std::endl;

        // while not end of file
        while (!auctionFile.eof())
        {
            std::getline(auctionFile, bid);

            // if stack is empty, push the first bid
            if (theStack.isEmpty())
            {
                // push bid to stack
                theStack.push(bid);
            }
            // if current item in stack is less than current bid, push the new top bid
            else if (theStack.peek() < bid)
            {
                // push bid to stack
                theStack.push(bid);
            }
        }
    }

    std::cout << "The winning bid is: $" << theStack.peek();

    return 0;
}