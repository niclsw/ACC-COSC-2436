You will write a program to process the lines in a text file using a linked list ADT and raw pointers.

## Node class
You will create a class “Node” with the following private data attributes:
1. line – line from a file (string)
2. next - (pointer to a Node)

Put your class definition in a header file and the implementation of the methods in a .cpp file.
Follow the style they use in the book of having a "#include" for the implementation file at the bottom of the header file.
You will have the following public methods:
1. Accessors and mutators for each attribute
2. Constructor that initializes the attributes to nulls (empty string and nullptr)


## LinkedList class
You will create a class “LinkedList” with the following private data attributes:
1. headPtr – raw pointer to the head of the list
2. numItems – number of items in the list

Put your class definition in a header file and the implementation of the methods in a .cpp file.
Follow the style they use in the book of having a "#include" for the implementation file at the bottom of the header file.
You will have the following public methods:
1. Accessor to get the current size (numItems)
2. Constructor that initializes numItems to zero and headPtr to nullptr
3. Add a node – this method will take as input one string value. It will then create a node object and set the attribute. Then it will put it in the linked list at the correct position – ascending order – avoiding duplicates. You will do all of the work while building the linked list.
4. toVector – returns vector with the contents of the list. You will use only the “push_back” method to get the strings into the vector.

 
## Client program
Your program will ask the user for the file name, open the text file , read each line and invoke the addNode method.  Make sure the file opened correctly before you start processing it. You do not know how many lines are in the file so your program should read until it gets to the end of the file.
It will display the contents of the list (the lines that were read from the file in sorted order with no duplicates) using the LinkedList class method “toVector” that puts all of the lines into a vector and returns it to the program that will display it.
Your client program will do the following:
1. Read file name from user
2. Display the number of lines that were read out of the file and were passed to the addNode method.
3. Display the lines in your linked list using the class method toVector to get the lines.
4. Display the number of lines in the vector.

I have attached three files you can use to test your program. Blackboard handles files in a strange way sometimes. You may not be able to directly download the files, but you can open them, copy and paste the contents into a notepad file and save that file.
You will write all of the code for processing the linked list - do not use any predefined objects in C++.  You do not need to offer a user interface – simply display the number of lines read from the file, the list using the “toVector” method and the number of lines in the vector.