#include<bits/stdc++.h>
using namespace std;

// Dice class
class Dice{
public:
    virtual int roll() = 0;
};

class NormalDice : public Dice{
public:
    int roll() override{
        return rand()%6 + 1;
    }
};

class CrookedDice : public Dice{ // this is a crooked dice, it will always roll a even number
public:
    int roll() override{ 
        return (rand()%3 + 1) * 2;
    }
}