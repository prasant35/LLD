#include "../include/condimentDecorator.hpp"
#include "../include/Bevarage.hpp"
#include <iostream>
#include <string>

class Mocha : public CondimentDecorator{
public:
    Mocha(Beverage* beverage) : CondimentDecorator(beverage){}

    float cost() override{
        return beverage->cost() + 0.20;
    }

    std::string getDescription() override{
        return beverage->getDescription() + ", Mocha";
    }
};
