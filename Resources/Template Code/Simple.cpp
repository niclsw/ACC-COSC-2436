#include <iostream>
#include "Simple.h"

template<class SimpleType>
Simple<SimpleType>::Simple() {}

template<class SimpleType>
Simple<SimpleType>::Simple(const SimpleType& initialValue) {
    item = initialValue;
}

template<class SimpleType>
void Simple<SimpleType>::setItem(const SimpleType& i) {
    item = i;
}

template<class SimpleType>
SimpleType Simple<SimpleType>::getItem() const {
    return item;
}