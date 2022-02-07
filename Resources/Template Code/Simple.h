#ifndef SIMPLE_
#define SIMPLE_

#include "SimpleInterface.h"

//using SimpleType = double;

template<class SimpleType>
class Simple : public SimpleInterface<SimpleType> {
    private:
        SimpleType item;

    public:
        Simple();
        Simple(const SimpleType& initialValue);

        // Const keeps the data from being modified while pasing by reference
        void setItem(const SimpleType& i);

        // Const keeps getItem from modifying any attributes
        SimpleType getItem() const;
};
#include "Simple.cpp"
#endif