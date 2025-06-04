#include "src/darkRoast.cpp"
#include "src/expresso.cpp"
#include "src/mocha.cpp"
#include "src/soy.cpp"
#include <iostream>

int main(){
    Beverage* beverage = new Expresso(); // we are creating an espresso object
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

    Beverage* beverage2 = new DarkRoast(); // Dark roast with mocha condiment
    beverage2 = new Mocha(beverage2);
    std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;
    beverage2 = new Soy(beverage2); // Dark roast with mocha and soy condiment
    std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;

   return 0;
}