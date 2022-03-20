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

    std::string fileName{""}, itemName{""};
    int bid{0};
    std::fstream auctionFile;
    LinkedStack<int> theStack;

    do
    {
        // Accept user input for file name
        std::cout << "\nEnter File Name: ";
        std::cin >> fileName;

        // Open the file
        auctionFile.open(fileName, std::ios::in);

        // Display error if error opening file
        if (!auctionFile)
        {
            std::cout << "\nError opening file. Try Again" << std::endl;
        }

        // Clear input stream
        std::cin.clear();
        std::cin.ignore(100, '\n');
    } while (!auctionFile);

    // Grab first line and display item name
    std::getline(auctionFile, itemName);
    std::cout << "\nThe Item up for Bid: " << itemName << std::endl;

    // while not end of file
    while (!auctionFile.eof())
    {
        auctionFile >> bid;

        // if stack is empty or the LI in stack is less than bid, push bid
        if (theStack.isEmpty() || theStack.peek() < bid)
        {
            // push bid to stack
            theStack.push(bid);
        }
    }

    // Display final message with winning bid
    std::cout << "\nThe winning bid is: $" << theStack.peek();

    // cleanup
    auctionFile.close();

    return 0;
}