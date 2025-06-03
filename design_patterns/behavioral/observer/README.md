# Weather Station - Observer Pattern Implementation Guide

## Project Overview
This project implements a Weather Station system using the Observer Pattern, based on the example from Head First Design Patterns. The system displays various weather metrics through different display elements that automatically update when weather data changes.

## Project Structure
```
observer/
├── include/          # Header files
└── src/             # Source files
```

## Implementation Steps

### 1. Define Interfaces
Create three core interfaces:

#### Subject Interface
```cpp
// Key methods:
- registerObserver()
- removeObserver()
- notifyObservers()
```

#### Observer Interface
```cpp
// Key method:
- update(temperature, humidity, pressure)
```

#### DisplayElement Interface
```cpp
// Key method:
- display()
```

### 2. Weather Data Implementation
Create WeatherData class that:
- Inherits from Subject
- Manages observer list
- Handles weather measurements
- Notifies observers of changes

### 3. Display Classes
Implement these concrete observers:

#### Current Conditions Display
- Shows current temperature, humidity, pressure
- Updates in real-time

#### Statistics Display
- Tracks min/max/average values
- Updates statistics with new data

## Building and Running

Compile all .cpp files and run the executable:

```bash
g++ main.cpp -o weather_program
.\weather_program
```
*This is a learning project based on Head First Design Patterns' Weather Station example.* 