#ifndef CONDIMENTDECORATOR
#define CONDIMENTDECORATOR
#include "Bevarage.hpp"

class CondimentDecorator : public Bevarage{
protected:
    Beverage* beverage; // pointer to the beverage object, since this is a decorator, it will wrap around the beverage object
public:
    CondimentDecorator(Beverage* beverage) : beverage(beverage) {}
    virtual std::string getDescription() = 0;
    virtual ~CondimentDecorator() = default;
};

#endif