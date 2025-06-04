#ifndef BEVERAGE
#define BEVERAGE
#include <string>

class Beverage{
public:
    virtual float cost() = 0;
    virtual std::string getDescription() = 0;
    virtual ~Beverage() = default;
};

#endif