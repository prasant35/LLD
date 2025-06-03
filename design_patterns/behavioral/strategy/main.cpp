#include "src/MallardDuck.cpp"
#include "src/RubberDuck.cpp"
#include <iostream>

int main(){
    Duck* mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();

    mallard->setFlyBehavior(new FlyNoWay());  // runtime behavior change
    mallard->performFly();
    
    mallard->performQuack();
    delete mallard;

    Duck* rubberDuck = new RubberDuck();
    rubberDuck->display();
    rubberDuck->performFly();
    rubberDuck->performQuack();
    delete rubberDuck;

    return 0;
}