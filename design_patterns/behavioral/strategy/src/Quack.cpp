#include "../include/QuackBehavior.hpp"
#include <iostream>

class Quack : public  QuackBehavior{
    public:
    void quack() override{
        std::cout<<"Quack quack"<<std::endl;
    }
};