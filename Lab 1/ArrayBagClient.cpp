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
		fflush(stdin); // flush output buffer stream to keep the menu from taking in leftover input from user

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
				// COMPLETE
				// CASE 2 : Add value to bag
				
				// declare variables to be used in this case
				std::string newItem;

				// Do while newItem is not "EXIT"
				do {
					std::cout << "Type EXIT to return to the main menu" << std::endl;
					std::cout << "Enter and Integer to add: ";
					std::cin >> newItem;

					// Check if user entered something other than exit
					if (newItem != "EXIT") {

						// Check if newItem is an integer
						if (isInt(newItem)) {

							// Check if newItem is already in bag, else display error message
							if (!bag.contains(stoi(newItem))) {
								
								// Add item to bag. Returns false if bag is full, display error message in that case
								if (bag.add(stoi(newItem))) {
									std::cout << "Success! " << newItem << " has been added to the bag." << std::endl;
								}
								else {
									std::cout << "Item not added. The bag is full..." << std::endl;
								}
							}	
							else { 
								// Item is already in bag, display message of failure
								std::cout << newItem << " this item is already in the bag..." << std::endl;
							}
						}
						else {
							std::cout << "Item must be an integer..." << std::endl;
						}
					}
		
				} while(newItem != "EXIT");

				// Bag could not be sorted so set to false
				isSorted = false;
				
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
				// COMPLETE
				// CASE 5 : Iterative Search

				std::string searchItemStr;
				bool isFound;

				// check if bag is sorted, else send user back to main menu to sort the bag
				if (isSorted) { 
					do {
						std::cout << "Enter EXIT to go back to main menu" << std::endl;
						std::cout << "Enter an integer to search for: ";
						std::getline(std::cin, searchItemStr);

						// if user entry does not equal EXIT continue
						//   check if search item is an int, else make user try again
						if (searchItemStr != "EXIT") { 
							if (isInt(searchItemStr)) {

								isFound = bag.binarySearchIterative(stoi(searchItemStr));

								// get boolean value if item is found in bag
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
					} while (searchItemStr != "EXIT");
				}
				else {
					std::cout << "The bag must be sorted before you can search for an item..." << std::endl;
				}
				break;
			}
			case '6': {
				// COMPLETE
				// CASE 6 : Binary Recursive Search

				// Declare variables to be used in the recursive search
				std::string searchItemStr;
				bool isFound;

				// check if bag is sorted, else send user back to main menu to sort the bag
				if (isSorted) { 
					do {
						std::cout << "Enter EXIT to go back to main menu" << std::endl;
						std::cout << "Enter an integer to search for: ";
						std::getline(std::cin, searchItemStr);

						// if user entry does not equal EXIT continue
						//   check if search item is an int, else make user try again
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
				// COMPLETE
				// CASE 0 : End Program

				std::cout << std::endl;
				std::cout << "Program Ending..." << std::endl;

				return 1;
			}
			default: {
				// COMPLETE
				// DEFAULT : Anything other than acceptable input

				std::cout << std::endl;
				std::cout << "Error - Please pick a valid option from the menu..." << std::endl;
				break;
			}
		}
	} while(input != '0');

   return 0;
   
}  // end main

/******************************************************************************/
/* Function:   isInt
/* Inputs:     reference string
/* Outputs:    Boolean value ( True / False)
/*                     
/* Purpose:    This function go through entire string using lamba functions to 
/*             check if user entered all integers in a string. It will return
/* 			   true if all chars are ints and false if one or more is not a int 
/******************************************************************************/

bool isInt(const std::string& str) {

	// return true if string is not empty
	//  return true if string contains only char(s) equal to a digit 0-9
	// 	 uses Lamba functions to check each char for digits. 
	//    Instant false if char is not digit
	return !str.empty() &&
        std::find_if(str.begin(), str.end(),
            [](unsigned char c) { return !std::isdigit(c); }) == str.end();
}


