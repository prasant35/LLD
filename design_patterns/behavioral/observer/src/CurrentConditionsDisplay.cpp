#include "include/Display.hpp"
#include "include/Observer.hpp"
#include "include/Subject.hpp"
#include <iostream>

class CurrentConditionsDisplay : public Observer, public Display{

    float temperature;
    float humidity;
    Subject* weatherData; // to register and unregister

public:

    CurrentConditionsDisplay(Subject* weatherData) : weatherData(weatherData) , temperature(0), humidity(0){
        weatherData->registerObserver(this); // we pass pointer of the observers
    }

    void update(float temperature, float humidity, float pressure) override{
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }

    void display() override{
        std::cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity" << std::endl;
    }
};