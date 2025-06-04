# Decorator Pattern - Coffee Shop Example

## 📚 Overview
Implementation of the Decorator pattern using a coffee shop scenario. This pattern allows behaviors to be added to individual objects dynamically without affecting other objects of the same class.

## 🎯 Implementation Details
- Base Component: `Beverage` (Abstract class)
- Concrete Components: `DarkRoast`, `Espresso`, etc.
- Decorator: `CondimentDecorator` (Abstract class)
- Concrete Decorators: `Soy`, `Mocha`, etc.

## 📂 Project Structure
```
decorator/
├── include/          # Header files
│   ├── Beverage.hpp
│   └── condimentDecorator.hpp
├── src/             # Implementations
│   └── soy.cpp
└── main.cpp         # Example usage
```

## 🚀 Usage Example
```cpp
cd design_patterns\structural\decorator
g++ main.cpp -o beverage_program
.\beverage_program
```
