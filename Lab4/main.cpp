////////////////////////////////////////////////////////////////////////////////
// Nicklaus Walker
// Lab 3 - COSC-2436-003
// This will ask the user for a file and load the values into a binary tree and
// allow the user to view and add to the tree. Each action will automatically display
// the tree.
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <fstream>
#include "BinaryNodeTree.h"

// Prototypes
void getFile(std::string &fileName, std::fstream &file);
void readToTree(BinaryNodeTree &tree, std::fstream &file);

int main() {

    // Initialize variables
    std::string fileName{""};
    BinaryNodeTree tree;
    std::fstream file;
    char choice;

    // Get file from user
    getFile(fileName, file);

    // Read file to tree
    readToTree(tree, file);
    std::cout << "File read to tree" << std::endl;

    // while loop to keep the program running
    do {

        // Clear input stream
        std::cin.clear();
        std::cin.ignore(100, '\n');

        // Print tree
        std::cout << "\nTHE TREE: " << std::endl;
        tree.print();

        // print the menu
        std::cout << "\n1. Insert" << std::endl;
        std::cout << "2. Find" << std::endl;
        std::cout << "3. Exit" << std::endl;

        // get the user's choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // switch statement to define the user's choice
        switch (choice) {
            case '1': {
                // Insert node

                // Clear input stream
                std::cin.clear();
                std::cin.ignore(100, '\n');

                std::string name{""}, id{""};

                std::cout << "Enter the name: ";
                std::getline(std::cin, name);

                std::cout << "Enter the id: ";
                std::cin >> id;

                // send name and ID to tree
                tree.insert(name, stoi(id));

                break;
            }
            case '2': {
                // Find ID

                int id{0};
                
                std::cout << "Enter the id: ";
                std::cin >> id;

                if (tree.find(id) != nullptr) {
                    std::cout << "Found: " << std::endl;

                    std::cout << tree.find(id)->getId() << " " << tree.find(id)->getName() << std::endl;
                }
                else {
                    std::cout << "Not found" << std::endl;
                }

                break;
            }
            case '3': {
                // Exit

                std::cout << "Exiting..." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    } while (choice != '3');

    // close file
    file.close();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Name:       getFile
// Inputs:     std::string &fileName
// Outputs:    std::fstream
// Purpose:    Used to get file name from user and error check file open. The file
//             is then returned to the calling function.
////////////////////////////////////////////////////////////////////////////////

void getFile(std::string &fileName, std::fstream &file)
{

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
    catch (std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
} // end getFile


////////////////////////////////////////////////////////////////////////////////
// Name:       readToTree
// Inputs:     BinaryNodeTree &tree, const std::fstream &file
// Outputs:    void
// Purpose:    Reads the file and inserts the values into the tree.
////////////////////////////////////////////////////////////////////////////////

void readToTree(BinaryNodeTree &tree, std::fstream &file)
{
    // initialize variables
    std::string line;
    int idValue;

    // read file line by line
    while (std::getline(file, line))
    {
        // convert line to int
        idValue = std::stoi(line);
        std::getline(file, line);

        // insert value into tree
        tree.insert(line, idValue);
    }
} // end readToTree

