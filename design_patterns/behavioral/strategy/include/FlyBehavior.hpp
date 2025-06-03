#ifndef FLY_BEHAVIOR
#define FLY_BEHAVIOR

class FlyBehavior{
    public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() = default;
};

#endif