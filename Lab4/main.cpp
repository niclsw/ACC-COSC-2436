#include <string>
#include <fstream>
#include "BinaryNodeTree.h"

int main() {

    BinaryNodeTree tree;

    std::string name1 = "Alpha";
    std::string name2 = "Beta";
    std::string name3 = "Gamma";
    std::string name4 = "Delta";

    int id1 = 1;
    int id2 = 2;
    int id3 = 3;
    int id4 = 4;
    

    tree.insert(name1, id1);
    tree.insert(name2, id2);
    tree.insert(name3, id3);
    tree.insert(name4, id4);


    std::cout << "Tree: " << std::endl;

    if (tree.find(id1)) {
        std::cout << "Found " << id1 << std::endl;
    }
    else {
        std::cout << "Not found " << id1 << std::endl;
    }

    return 0;
}