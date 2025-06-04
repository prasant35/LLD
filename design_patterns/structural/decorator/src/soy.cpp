#include "../include/condimentDecorator.hpp"
#include "../include/Bevarage.hpp"
#include <iostream>
#include <string>

class Soy : public CondimentDecorator{
    
public:
    Soy(Beverage* beverage) : CondimentDecorator(beverage){}

    float cost() override{
        return beverage->cost() + 0.15;
    }

    std::string getDescription() override{
        return beverage->getDescription() + ", Soy";
    }
};
