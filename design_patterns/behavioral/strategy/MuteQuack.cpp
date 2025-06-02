#include "QuackBehavior.hpp"
#include <iostream>

class MuteQuack : public QuackBehavior{
    public:
    void quack() override{
        std::cout<<"I am mute"<<std::endl;
    }
}