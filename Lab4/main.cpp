#include <string>
#include <fstream>
#include "BinaryNodeTree.h"

std::fstream getFile();
void readToTree(BinaryNodeTree &tree, std::fstream &file);

int main() {

    BinaryNodeTree tree;
    std::fstream file = getFile();
    




    tree.print();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Name:       getFile
// Inputs:     std::string &fileName
// Outputs:    std::fstream
// Purpose:    Used to get file name from user and error check file open. The file
//             is then returned to the calling function.
////////////////////////////////////////////////////////////////////////////////

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
    catch (std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }

    return file;
} // end getFile