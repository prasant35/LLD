#include "Duck.hpp"
#include "FlyNoWay.cpp"
#include "MuteQuack.cpp"
#include <iostream>

class RubberDuck : public Duck{
public:
    RubberDuck(){
        flyBehavior = new FlyNoWay();
        quackBehavior = new MuteQuack();
    }

    void display() override{
        std::cout<<"I am Rubber Duck!"<<std::endl;
    }
};