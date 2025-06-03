#ifndef SUBJECT
#define SUBJECT

class Subject{
public:
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

#endif