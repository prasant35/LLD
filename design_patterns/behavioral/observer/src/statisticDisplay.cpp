#include "../include/Display.hpp"
#include "../include/Observer.hpp"
#include "../include/Subject.hpp"
#include <iostream>

class StatisticDisplay : public Observer, public Display{
    float maxTemp = 0.0f;
    float minTemp = 1000.0f;
    Subject* weatherData;
public:
    StatisticDisplay(Subject* weatherData) : weatherData(weatherData) {
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure) override{
        if(temperature > maxTemp){
            maxTemp = temperature;
        }
        if(temperature < minTemp){
            minTemp = temperature;
        }
        display();
    }
    void display() override{
        std::cout << "Max/Min temperature: " << maxTemp << "/" << minTemp << std::endl;
    }

    void remove(){
        weatherData->removeObserver(this);
    }
};
