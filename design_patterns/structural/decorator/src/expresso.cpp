#include "../include/Bevarage.hpp"
#include <iostream>
#include <string>

class Expresso : public Beverage{
public:
    float cost() override{
        return 1.99;
    }

    std::string getDescription() override{
        return "Expresso";
    }
};