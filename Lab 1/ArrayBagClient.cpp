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
				auto displayBag = bag.toVector();
				for (int i{0}; i < displayBag.size(); i++) {
					std::cout << displayBag[i] << std::endl;
				}
				break;
			}
			case '2': {
				// Add Value to Bag
				std::string newItem;

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
				// Remove Value from bag
				break;
			}
			case '4': {
				// Sort Bag
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

	return !str.empty() &&
        std::find_if(str.begin(), str.end(), // find_if 
            [](unsigned char c) { return !std::isdigit(c); }) == str.end();
}


