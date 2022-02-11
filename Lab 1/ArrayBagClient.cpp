#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "ArrayBag.h"

bool isInt(const std::string& str);

int main()
{
	bool isSorted = false;
	char input;
	ArrayBag<int> bag;
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
		
	std::cout << "Adding positive integers to the bag: " << std::endl;
	for (int i = 0; i < 20; i++) {
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
		scanf("%c", &input); // scanf will only take the first char the user enters
		fflush(stdin); // flush output buffer stream

		switch (input) {
			case '1': {
				// COMPLETE
				// Display contents of bag
				
				// Assign displayBag to the bag vector
				auto displayBag = bag.toVector();

				// Display Bag Contents
				for (int i{0}; i < displayBag.size(); i++) {
					std::cout << displayBag[i] << std::endl;
				}
				break;
			}
			case '2': {
				// INCOMPLETE
				// CASE 2 : Add value to bag

				std::string newItem;

				// Do while newItem is not an integer
				if (!isSorted) {
					std::cout << "The bag must be sorted before an item is added" << std::endl;
				}
				else {
					do {
						std::cout << "Enter an Integer: ";
						std::cin >> newItem;

						// If item is not int display error message
						if (!isInt(newItem))
							std::cout << "Error - new item must be an integer..." << std::endl;
						// If item is already in bag display error message
						else if (bag.contains(stoi(newItem)))
							std::cout << "Error - this item is already in the bag..." << std::endl;
						else if (!bag.add(stoi(newItem)))
							std::cout << "Error - the bag is full..." << std::endl;

					} while (!isInt(newItem) && bag.contains(stoi(newItem)) && !bag.add(stoi(newItem)));
				}
				
				// Add new item to bag using inline if-else
				// if isSorted = true add item to bag
				// else do nothing
				isSorted ? bag.add(stoi(newItem)) : 0;
				
				break;
			}
			case '3': {
				// COMPLETE
				// CASE 3 : Remove an item from the bag
				
				// declare variables to be used in this case
				std::string removedItem;

				// Do while removedItem is not "EXIT"
				do {
					std::cout << "Type EXIT to return to the main menu" << std::endl;
					std::cout << "Enter and Integer to remove: ";
					std::cin >> removedItem;

					// Check if user entered something other than exit
					if (removedItem != "EXIT") {

						// Check if removedItem is an integer
						if (isInt(removedItem)) {

							// return true if bag contains removedItem
							if (bag.contains(stoi(removedItem))) {

								//Remove item and display message of success
								bag.remove(stoi(removedItem));
								std::cout << removedItem << " has been removed from the bag..." << std::endl;
							}
							else {
								// removedItem is not in the bag, display error message
								std::cout << "This item is not in the bag..." << std::endl;
							}
						}
						else {
							std::cout << "Item must be an integer..." << std::endl;
						}
					}
		
				} while(removedItem != "EXIT");

				// Bag could not be sorted so set to false
				isSorted = false;

				// break from case and endl to create some space
				std::cout << std::endl;
				break;
			}
			case '4': {
				// COMPLETE
				// CASE 4 : Sort the bag

				bag.bubbleSort();
				isSorted = true;

				std::cout << "The bag has been sorted..." << std::endl;

				break;
			}
			case '5': {
				// INCOMPLETE
				// CASE 5 : Iterative Search
				break;
			}
			case '6': {
				// COMPLETE
				// CASE 6 : Binary Recursive Search

				// Declare variables to be used in the recursive search
				std::string searchItemStr;
				bool isFound;

				if (isSorted) { // check if bag is sorted, else send user back to main menu to sort the bag
					do {
						std::cout << "Enter EXIT to go back to main menu" << std::endl;
						std::cout << "Enter an integer to search for: ";
						std::getline(std::cin, searchItemStr);

						// if user entry does not equal EXIT continue
						// check if search item is an int, else make user try again
						if (searchItemStr != "EXIT") { 
							if (isInt(searchItemStr)) { 

								// get boolean value if item is found in bag
								isFound = bag.binarySearchRecursiveHelper(stoi(searchItemStr)); 

								if (isFound) {
									std::cout << "Success! We found " << searchItemStr << " in the bag." << std::endl;
								}
								else {
									std::cout << "We could not find " << searchItemStr << " in the bag." << std::endl;
								}
							}
							else {
								std::cout << "Error - must be an integer..." << std::endl;
							}
						}

					} while(searchItemStr != "EXIT");
				}
				else {
					std::cout << "The bag must be sorted before you can search for an item..." << std::endl;
				}
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
	//  return true if string contains only char(s) equal to a digit 0-9
	// 	 uses Lamba functions to check each char for digits. 
	//    Instant false if char is not digit
	return !str.empty() &&
        std::find_if(str.begin(), str.end(),
            [](unsigned char c) { return !std::isdigit(c); }) == str.end();
}


