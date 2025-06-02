#ifndef DUCK
#define DUCK

#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

class Duck{
protected:
    //composition over inheritance
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;
public:
    virtual void display() = 0;
    virtual void performFly() {
        flyBehavior->fly();
    }
    virtual void performQuack(){
        quackBehavior->quack();
    }

    void setFlyBehavior(FlyBehavior* fb){
        flyBehavior = fb;
    }
    void setQuackBehavior(QuackBehavior* qb){
        quackBehavior = qb;
    }
    virtual ~Duck() = default;
};

#endif