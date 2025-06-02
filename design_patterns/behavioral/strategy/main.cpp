#include "MallardDuck.cpp"
#include <iostream>

int main(){
    Duck* mallard = new MallardDuck();
    mallard->performFly();
    mallard->performQuack();
    delete mallard;

    return 0;
}