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

// Player class
class Player{
    int position;
    string name;
public:

    Player(string name) : name(name), position(1) {}
    void move(int steps){
        position += steps;
    }

    void setPosition(int position){ // due to snake and ladder, we need to set the position of the player
        this->position = position;
    }

    int getPosition(){
        return position;
    }
}

// Board class
class Board{
    int size;
    unordered_map<int, int> snakes, ladders;
public:
    Board(int size) : size(size) {}
    void addSnake(int start, int end){  // assuming no snake share the same start point
        snakes[start] = end;
    }

    int checkPositionForSnake(int position){
        if(snakes.count(position)){
            return snakes[position];
        }else return position;
    }
}