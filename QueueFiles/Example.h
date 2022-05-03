#ifndef EXAMPLE
#define EXAMPLE
// C++ 03
//typedef double ItemType;

// C++ 11
using ItemType = double;

class Example {
    private:
        ItemType item;
    public:
        // Default Constructor
        Example();

        // Paramater constructor can be init when user does --Example myItem(item)--
        // Useful when you want to init an obj with a pre-defined value by user
        // Pass by const reference to avoid breaking the ADT wall 
        Example(const ItemType& theItem);

        // Method to change the value of the data field
        void setItem(const ItemType& theItem);

        // Method to get the value of the item
        ItemType getItem() const;
};
#endif