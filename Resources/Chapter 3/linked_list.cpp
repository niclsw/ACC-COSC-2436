#include <iostream>
#include <string>
#include <vector>


class Node {
    private:
        int item;
        Node* next;
    public:
        Node();
        Node(int anItem);
        Node(int anItem, Node* nextNodePtr);

        void setItem(int anItem);
        void setNext(Node* nextNodePtr);
        int getItem();
        Node* getNext();
};

Node::Node() { next = nullptr; }
Node::Node(int anItem) {
    item = anItem;
    next = nullptr;
}
Node::Node(int anItem, Node* nextNodePtr) {
    item = anItem;
    next = nextNodePtr;
}

void Node::setItem(int anItem) { item = anItem; }
void Node::setNext(Node* nextNodePtr) { next = nextNodePtr; }
int Node::getItem() { return item;}
Node* Node::getNext() { return next;}

const int QUIT = 4;

int getOption();
void addNode(Node* &);
void removeNode(Node* &);
void displayList(Node*);

int main() {

    int option;

    Node* headPtr = nullptr;
    
    option = getOption();

    while (option != QUIT) {
        switch(option)
        {
            case 1:
                addNode(headPtr);
                break;
            case 2:
                removeNode(headPtr);
                break;
            case 3:
                displayList(headPtr);
                break;
        }
        option = getOption();
    }

    return 0;
}

int getOption() {
    int choice;

    std::cout << "1. Add Node \n"
              << "2. Remove Node \n"
              << "3. Display List \n"
              << "4. Quite \n"
              << "Choice: ";
    std::cin >> choice;

    return choice;
}

void addNode(Node* &headPtr) {
    int item;
    

    std::cout << "Enter an integer: ";
    std::cin >> item;
    Node* newNodePtr = new Node(item);

    if (!headPtr) {
        headPtr = newNodePtr;
    }
    else {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
}

void removeNode(Node* &headPtr) {
    int item;
    bool isFound{false};
    Node* curPtr = headPtr;
    Node* removePtr = headPtr;

    std::cout << "Enter an integer: ";
    std::cin >> item;
    

    while (curPtr && !isFound) {
        if (item == curPtr->getItem()) {
            isFound = true;
        }
        else {
            curPtr = curPtr->getNext();
        }
    }

    if (isFound) {
        curPtr->setItem(headPtr->getItem());
        headPtr = headPtr->getNext();
        removePtr->setNext(nullptr);
        delete removePtr;
        removePtr = nullptr;
    }

}

void displayList(Node* headPtr) {
    std::cout << "Display List!" << std::endl;

    Node* curPtr = headPtr;

    while (curPtr != nullptr) {
        std::cout << curPtr->getItem() << std::endl;
        curPtr = curPtr->getNext();
    }
}