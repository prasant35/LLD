#include "include/Subject.hpp"
#include "include/Observer.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class WeatherData : public Subject{

    std::vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

public:

    WeatherData() : temperature(0), humidity(0), pressure(0) {}

    void registerObserver(Observer* o) override{
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() override{
        for(auto observer : observers){
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temperature, float humidity, float pressure){
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }

    void measurementsChanged(){
        notifyObservers();
    }      
};
