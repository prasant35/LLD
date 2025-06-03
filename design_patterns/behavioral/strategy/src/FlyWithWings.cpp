#include "../include/FlyBehavior.hpp"
#include <iostream>

class FlyWithWings : public FlyBehavior{
    public:
    void fly() override{
        std::cout<<"I am flying with wings"<<std::endl;
    }
};