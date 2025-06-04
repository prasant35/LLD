#include "../include/Bevarage.hpp"
#include <iostream>
#include <string>

class DarkRoast : public Beverage{
public:
    float cost() override{
        return 0.99;
    }

    std::string getDescription() override{
        return "Dark Roast";
    }
        
};
