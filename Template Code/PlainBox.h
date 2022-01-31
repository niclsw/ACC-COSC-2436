#ifndef PLAIN_BOX
#define PLAIN_BOX

// C++ 003
// typedef double ItemType

// C++ 11
using ItemType = double;

class PlainBox {
    private:
        ItemType item;

    public:
        PlainBox();

        PlainBox(const ItemType& theItem);

        void setItem(const ItemType& theItem);

        ItemType getItem() const;
};

#endif