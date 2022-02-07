#ifndef SIMPLE_INTERFACE_
#define SIMPLE_INTERFACE_

template<class SimpleType>
class SimpleInterface {
    public:
        virtual void setItem(const SimpleType& i) = 0;
        virtual SimpleType getItem() const = 0;;
};

#endif