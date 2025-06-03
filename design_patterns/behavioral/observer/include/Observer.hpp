#ifndef OBSERVER
#define OBSERVER

class Observer{
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() = default;    
};

#endif