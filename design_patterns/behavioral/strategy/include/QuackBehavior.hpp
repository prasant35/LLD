#ifndef QUACK_BEHAVIOR
#define QUACK_BEHAVIOR

class QuackBehavior{
  public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() = default;
};

#endif