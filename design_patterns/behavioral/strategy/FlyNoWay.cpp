#include "FlyBehavior.hpp"
#include <iostream>

class FlyNoWay : public FlyBehavior{
    public:
    void fly() override{
        std::cout<<"I cant fly"<<std::endl;
    }
};