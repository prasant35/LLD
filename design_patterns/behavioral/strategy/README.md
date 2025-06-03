# Duck Strategy Pattern Example

This project demonstrates the Strategy Pattern using a Duck simulation example from the Head First Design Patterns book.

## Overview

The Strategy Pattern defines a family of algorithms, encapsulates each one, and makes them interchangeable. It lets the algorithm vary independently from clients that use it.

In this example:
- `Duck` is the context class that uses the strategies
- `FlyBehavior` and `QuackBehavior` are the strategy interfaces
- Concrete strategies include:
  - `FlyWithWings` and `FlyNoWay` for flying behavior
  - `Quack`, `MuteQuack`, and `Squeak` for quacking behavior

## Directory Structure
```
strategy/
├── include/                    # Header files
│   ├── Duck.hpp               # Abstract Duck class
│   ├── FlyBehavior.hpp        # Flying strategy interface
│   └── QuackBehavior.hpp      # Quacking strategy interface
│
├── src/                       # Source files
│   ├── FlyWithWings.cpp      # Concrete flying behavior
│   ├── FlyNoWay.cpp          # Concrete flying behavior
│   ├── Quack.cpp             # Concrete quacking behavior
│   ├── MuteQuack.cpp         # Concrete quacking behavior
│   ├── MallardDuck.cpp       # Concrete duck type
│   └── RubberDuck.cpp        # Concrete duck type
│
├── main.cpp                   # Main program
└── README.md                  # This file
```

## Class Structure

- `Duck` (abstract base class)
  - Contains `FlyBehavior` and `QuackBehavior` interfaces
  - Delegates flying and quacking to behavior classes
  
- `MallardDuck` (concrete duck)
  - Implements specific display behavior
  - Initializes with default behaviors

- Behavior Interfaces
  - `FlyBehavior`: Interface for flying algorithms
  - `QuackBehavior`: Interface for quacking algorithms

## Key Features

1. Runtime Behavior Changes
   - Behaviors can be changed dynamically
   - Uses composition over inheritance
   
2. Encapsulated Behaviors
   - Each behavior is in its own class
   - Easy to add new behaviors without changing existing code

3. Flexible Design
   - Ducks can have different combinations of behaviors
   - New duck types can reuse existing behaviors

## Building and Running

Compile all .cpp files and run the executable:

```bash
g++ main.cpp -o duck_program
.\duck_program
```

## Design Pattern Benefits

- Eliminates conditional statements
- Makes it easy to add new behaviors
- Allows behavior changes at runtime
- Promotes code reuse through composition
