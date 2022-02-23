#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include "ArrayBag.h"

void displayContents(ArrayBag<int>& bag);
void addItems(ArrayBag<int>& bag);
void removeItems(ArrayBag<int>& bag);
void sortBag(ArrayBag<int>& bag);
void binaryIterativeSearch(ArrayBag<int>& bag, bool isSorted);
void binaryRecursiveSearch(ArrayBag<int>& bag, bool isSorted);
bool isInt(const std::string& str);
void menu();
void endProgram();

int main()
{
	bool isSorted{false};
	char input{};
	ArrayBag<int> bag;
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	
	std::cout << "Adding positive integers to the bag... " << std::endl;

	for (int i = 0; i < 20; i++) {
		bag.add(items[i]);
	}  // end for
	

	do {
		// flush output buffer stream to keep the menu from taking in leftover input from user
		// Usefull once the user starts going through the menu
		fflush(stdin);

		// Display the menu
		menu();

		// cout "Enter Choice: "
		// scanf with a specifier and sub-specifier will only take the first char the user enters
		scanf("%1c", &input); 
		std::cin.ignore(100, '\n');
		

		// Switch case to drive the menu
		switch (input) {
			case '1': {
				displayContents(bag);
				break;
			}
			case '2': {
				addItems(bag);
				isSorted = false;
				break;
			}
			case '3': {
				removeItems(bag);
				isSorted = false;
				break;
			}
			case '4': {
				sortBag(bag);
				isSorted = true;
				break;
			}
			case '5': {
				binaryIterativeSearch(bag, isSorted);
				break;
			}
			case '6': {
				binaryRecursiveSearch(bag, isSorted);
				break;
			}
			case '0': {
				endProgram();
				break;
			}
			default: {
				// COMPLETE
				// DEFAULT : Anything other than acceptable input

				std::cout << "\nError - Please pick a valid option from the menu..." << std::endl;
				break;
			}
		}
	} while(input != '0');


   return 0;
   
}  // end main

////////////////////////////////////////////////////////////////////////////////
// Function:   isInt
// Inputs:     reference string
// Outputs:    Boolean value ( True / False)
//                     
// Purpose:    This function go through entire string using a for loop to 
//             check if user entered all integers in a string. It will return
// 			   true if all chars are ints and false if one or more is not a int 
////////////////////////////////////////////////////////////////////////////////

bool isInt(const std::string& str) {

	bool isInt{true};
	size_t i{0};

	// Check if string user enters is an integer. As soon as it detects a char that
	// is not an integer, it sets isInt to false and ends the while loop.
    while (i < str.length() && isInt) {
        if (!isdigit(str[i]))
            isInt = false;
        i++;
    }

    return isInt;
} // end isInt

////////////////////////////////////////////////////////////////////////////////
// Function:   displayContents
// Inputs:     ArrayBag<int> bag object
// Outputs:    Contents of Bag
//                     
// Purpose:    This function displays the contents of the bag to the user
////////////////////////////////////////////////////////////////////////////////

void displayContents(ArrayBag<int>& bag) {
	auto displayBag = bag.toVector();

	std::cout << "\nBag Contents: | ";

	// Display Bag Contents
	for (size_t i{0}; i < displayBag.size(); i++) {
		std::cout << displayBag[i] << " | ";
	}

	std::cout << std::endl;

} //end displayContents

////////////////////////////////////////////////////////////////////////////////
// Function:  addItems
// Inputs:    ArrayBag<int> bag object
// Outputs:   N/A
//                     
// Purpose:   This function gives the user the ability to add items to the
//            bag. It will call isInt to make sure the item entered is an
// 			  integer. It will also check to make sure the item is not already
//  		  in the bag.
////////////////////////////////////////////////////////////////////////////////

void addItems(ArrayBag<int>& bag) {
	// COMPLETE
	// CASE 2 : Add value to bag
	
	// declare variables to be used in this case
	std::string newItem{""};

	// Do while newItem is not "MENU"
	do {
		std::cout << "\nAdd Value to Bag - Enter 'MENU' to exit" << std::endl;
		std::cout << "Enter and Integer to add: ";
		std::cin >> newItem;
		std::cin.ignore(100, '\n');

		// Check if user entered something other than MENU
		if (newItem != "MENU") {

			// Check if newItem is an integer
			if (isInt(newItem)) {

				// Check if newItem is already in bag, else display error message
				if (!bag.contains(stoi(newItem))) {
					
					// Add item to bag. Returns false if bag is full, display error message in that case
					if (bag.add(stoi(newItem))) {
						std::cout << "\nSuccess! " << newItem << " has been added to the bag." << std::endl;
					}
					else {
						std::cout << "\nCould not add " << newItem << ". The bag is full." << std::endl;
					}
				}	
				else { 
					// Item is already in bag, display message of failure
					std::cout << "\nCould not add " << newItem << ". this item is already in the bag." << std::endl;
				}
			}
			else {
				std::cout << "\nItem must be an integer..." << std::endl;
			}
		}

	} while(newItem != "MENU");

	// Bag could not be sorted so set to false

}

////////////////////////////////////////////////////////////////////////////////
// Function:   removeItems
// Inputs:     ArrayBag<int> bag object
// Outputs:    N/A
//                     
// Purpose:    This function gives the user the option to remove certain items
//             from the bag. It will call isInt to make sure the item entered
// 			   is an integer. It will also check to make sure that item is in
//			   the bag.
////////////////////////////////////////////////////////////////////////////////

void removeItems(ArrayBag<int>& bag) {
	// COMPLETE
	// CASE 3 : Remove an item from the bag
	
	// declare variables to be used in this case
	std::string removedItem{""};

	// Do while removedItem is not "MENU"
	do {
		std::cout << "\nRemove Value from Bag - Enter 'MENU' to exit" << std::endl;
		std::cout << "Enter and Integer to remove: ";
		std::cin >> removedItem;
		std::cin.ignore(100, '\n');

		// Check if user entered something other than MENU
		if (removedItem != "MENU") {

			// Check if removedItem is an integer
			if (isInt(removedItem)) {

				// return true if bag contains removedItem
				if (bag.contains(stoi(removedItem))) {

					//Remove item and display message of success
					bag.remove(stoi(removedItem));
					std::cout << "\nSuccess! " << removedItem << " has been removed from the bag..." << std::endl;
				}
				else {
					// removedItem is not in the bag, display error message
					std::cout << "\nCould not remove " << removedItem << ". This item is not in the bag." << std::endl;
				}
			}
			else {
				std::cout << "\nError - Item must be an integer." << std::endl;
			}
		}

	} while(removedItem != "MENU");

	// Bag could not be sorted so set to false

}

////////////////////////////////////////////////////////////////////////////////
// Function:   sortBag
// Inputs:     ArrayBag<int> bag object
// Outputs:    N/A
//                     
// Purpose:    This function will sort the bag. No error checking required.
////////////////////////////////////////////////////////////////////////////////

void sortBag(ArrayBag<int>& bag) {
	// COMPLETE
	// CASE 4 : Sort the bag

	bag.bubbleSort();

	std::cout << "\nSuccess! The bag has been sorted" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Function:   binaryIterativeSearch
// Inputs:     ArrayBag<int> bag object & boolean isSorted
// Outputs:    N/A
//                     
// Purpose:    This function will search the bag for an item the user picks
//             using an interative approach. It will error check to make sure
// 			   the user enters an integer by calling isInt.
////////////////////////////////////////////////////////////////////////////////

void binaryIterativeSearch(ArrayBag<int>& bag, bool isSorted) {
	// COMPLETE
	// CASE 5 : Iterative Search

	// declare variables to be used in this case
	std::string searchItemStr{""};
	bool isFound{false};

	// check if bag is sorted, else send user back to main menu to sort the bag
	if (isSorted) { 
		do {
			std::cout << "\nIterative Search - Enter 'MENU' to exit" << std::endl;
			std::cout << "Enter an integer to search for: ";
			std::cin >> searchItemStr;
			std::cin.ignore(100, '\n');

			// if user entry does not equal MENU continue
			//   check if search item is an int, else make user try again
			if (searchItemStr != "MENU") { 
				if (isInt(searchItemStr)) {

					// get boolean value if item is found in bag
					if (bag.binarySearchIterative(stoi(searchItemStr))) {
						std::cout << "\nSuccess! We found " << searchItemStr << " in the bag." << std::endl;
					}
					else {
						std::cout << "\nWe could not find " << searchItemStr << " in the bag." << std::endl;
					}
				}
				else {
					std::cout << "\nError - must be an integer..." << std::endl;
				}
			}
		} while (searchItemStr != "MENU");
	}
	else {
		std::cout << "\nError - The bag must be sorted before you can search for an item..." << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Function:   binarySearchRecursive
// Inputs:     ArrayBag<int> bag object, boolean isSorted
// Outputs:    N/A
//                     
// Purpose:    This function searches the bag for an item the user chooses
//             recursively. It will also error check to make sure the user
// 			   enters an integer to search for.
////////////////////////////////////////////////////////////////////////////////

void binaryRecursiveSearch(ArrayBag<int>& bag, bool isSorted) {
	// COMPLETE
	// CASE 6 : Binary Recursive Search

	// Declare variables to be used in the recursive search
	std::string searchItemStr{""};
	bool isFound{false};

	// check if bag is sorted, else send user back to main menu to sort the bag
	if (isSorted) { 
		do {
			std::cout << "\nRecursive Search - Enter 'MENU' to exit" << std::endl;
			std::cout << "Enter an integer to search for: ";
			std::cin >> searchItemStr;
			std::cin.ignore(100, '\n');

			// if user entry does not equal MENU continue
			//   check if search item is an int, else make user try again
			if (searchItemStr != "MENU") { 
				if (isInt(searchItemStr)) { 

					// get boolean value if item is found in bag
					if (bag.binarySearchRecursiveHelper(stoi(searchItemStr))) {
						std::cout << "\nSuccess! We found " << searchItemStr << " in the bag." << std::endl;
					}
					else {
						std::cout << "\nWe could not find " << searchItemStr << " in the bag." << std::endl;
					}
				}
				else {
					std::cout << "\nError - must be an integer..." << std::endl;
				}
			}

		} while(searchItemStr != "MENU");
	}
	else {
		std::cout << "\nError - The bag must be sorted before you can search for an item..." << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Function:   menu
// Inputs:     N/A
// Outputs:    N/A
//                     
// Purpose:    This function displays the menu options	   
////////////////////////////////////////////////////////////////////////////////

void menu() {

	std::cout << "\n============ Bag Array : Menu ============" << std::endl;
	std::cout << "(1) Display Contents of Bag" << std::endl;
	std::cout << "(2) Add Value" << std::endl;
	std::cout << "(3) Remove Value" << std::endl;
	std::cout << "(4) Sort The Bag" << std::endl;
	std::cout << "(5) Iterative Search" << std::endl;
	std::cout << "(6) Recursive Search" << std::endl;
	std::cout << "(0) End Program" << std::endl;
	std::cout << "Enter Option: ";

} // end menu

////////////////////////////////////////////////////////////////////////////////
// Function:   endProgram
// Inputs:     N/A
// Outputs:    N/A
//                     
// Purpose:    This function clears the screen and ends the program.	   
////////////////////////////////////////////////////////////////////////////////

void endProgram() {
	// COMPLETE
	// CASE 0 : End Program

	// Clear screen and announce the program is ending
	std::cout << std::string(100, '\n'); 
	std::cout << "\nProgram Ending..." << std::endl;

} // end endProgram

