# Structural Design Patterns

Structural patterns are design patterns that focus on how classes and objects are composed to form larger structures and systems. They help ensure that when parts of a system change, the entire system doesn't need to change.

## Key Characteristics of Structural Patterns:
- They deal with relationships between entities
- Help in building flexible and efficient relationships between objects
- Make it easier to add new features without changing existing code
- Promote loose coupling between objects

## Common Structural Patterns:
1. **Decorator** - Adds new behaviors to objects dynamically by placing them inside wrapper objects
2. **Adapter** - Allows incompatible interfaces to work together
3. **Bridge** - Separates an abstraction from its implementation
4. **Composite** - Composes objects into tree structures
5. **Facade** - Provides a simplified interface to a complex subsystem
6. **Flyweight** - Reduces memory usage by sharing common object data
7. **Proxy** - Provides a surrogate for another object to control access to it

### Benefits:
- Follows Single Responsibility Principle
- Extends behavior at runtime
- Provides flexible alternative to subclassing
- Supports Open/Closed Principle

### Use Cases:
- Adding optional features to objects
- When extension by subclassing is impractical
- When you need to modify object behavior at runtime