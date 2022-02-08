#include <iostream>
#include <string>
#include <algorithm>
#include "ArrayBag.h"

using namespace std;

bool isInt(const std::string& str);

int main()
{
	char input;
	ArrayBag<int> bag;
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
		
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		bag.add(items[i]);
	}  // end for

	do {
		std::cout << "============ Bag Array : Menu ============" << std::endl;
		std::cout << "(1) Display Contents of Bag" << std::endl;
		std::cout << "(2) Add Value" << std::endl;
		std::cout << "(3) Remove Value" << std::endl;
		std::cout << "(4) Sort The Bag" << std::endl;
		std::cout << "(5) Iterative Search" << std::endl;
		std::cout << "(6) Recursive Search" << std::endl;
		std::cout << "(0) End Program" << std::endl;
		std::cout << "Enter Option: ";
		std::cin >> input;

		switch (input) {
			case '1': {
				// Assign displayBag to the bag vector
				auto displayBag = bag.toVector();

				// Display Bag Contents
				for (int i{0}; i < displayBag.size(); i++) {
					std::cout << displayBag[i] << std::endl;
				}
				break;
			}
			case '2': {
				// Add Value to Bag
				std::string newItem;

				// Do while newItem is not an integer
				do {
					std::cout << "Enter an Integer: ";
					std::cin >> newItem;

					if (!isInt(newItem))
						std::cout << "Error - new item must be an integer..." << std::endl;

				} while (!isInt(newItem));

				// Add new item to bag 
				// stoi() converts string to int
				bag.add(stoi(newItem));
				
				break;
			}
			case '3': {
				// Remove an item from the bag
				std::string removedItem;

				// Do while removedItem is not "EXIT"
				do {
					std::cout << "Type EXIT to return to the main menu" << std::endl;
					std::cout << "Enter and Integer to remove: ";
					std::cin >> removedItem;

					// If is not an integer, display error
					if (!isInt(removedItem)) {
						std::cout << "Error - new item must be an integer..." << std::endl;
					}
					// Else if removedItem is not in bag, display error
					else if (!bag.contains(stoi(removedItem))) {
						std::cout << "This integer is not in the bag..." << std::endl;
					}
					// else, no errors, remove the item from the bag
					else {
						bag.remove(stoi(removedItem));
					}
				} while(removedItem != "EXIT");
				break;
			}
			case '4': {
				// Call bubbleSort()
				bag.bubbleSort();
				break;
			}
			case '5': {
				// Iterative Search
				break;
			}
			case '6': {
				// Recursive Search
				break;
			}
			case '0': {
				// End Program
				return 1;
			}
			default: {
				// Anything other than acceptable input
				std::cout << std::endl;
				std::cout << "Error - Please pick a valid option from the menu..." << std::endl;
				break;
			}
		}
	} while(input != '0');

   return 0;
   
}  // end main

bool isInt(const std::string& str) {

	// return true if string is not empty
	// 
	return !str.empty() &&
        std::find_if(str.begin(), str.end(),
            [](unsigned char c) { return !std::isdigit(c); }) == str.end();
}


