#include "src/CurrentConditionsDisplay.cpp"
#include "src/WeatherData.cpp"
#include "src/statisticDisplay.cpp"
#include <iostream>

int main(){
    WeatherData weatherData;
    CurrentConditionsDisplay currentConditionsDisplay(&weatherData);
    StatisticDisplay statisticDisplay(&weatherData);

    weatherData.setMeasurements(80, 65, 30.4f);
    weatherData.setMeasurements(82, 70, 29.2f);

    statisticDisplay.remove(); // for testing remove observer

    weatherData.setMeasurements(78, 90, 29.2f);

    return 0;
}