#include "../include/Duck.hpp"
#include "FlyWithWings.cpp"
#include "Quack.cpp"
#include <iostream>

class MallardDuck : public Duck{
public:
    MallardDuck(){
        flyBehavior = new FlyWithWings();
        quackBehavior = new Quack();
    }
    void display() override{
        std::cout<<"I am Mallard Duck!"<<std::endl;
    }
};