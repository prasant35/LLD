#ifndef CONDIMENTDECORATOR
#define CONDIMENTDECORATOR
#include "Bevarage.hpp"

class CondimentDecorator : public Beverage{ // we are doing this for type matching
protected:
    Beverage* beverage; // pointer to the beverage object, since this is a decorator, it will wrap around the beverage object
public:
    CondimentDecorator(Beverage* beverage) : beverage(beverage) {}
    virtual ~CondimentDecorator() = default;
};

#endif