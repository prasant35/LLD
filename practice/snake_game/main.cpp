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
};

// Player class
class Player{
    int position;
    string name;
public:

    Player(string name) : name(name), position(1) {}
    void move(int steps){
        position += steps;
    }

    string getName(){
        return name;
    }

    void setPosition(int position){ // due to snake and ladder, we need to set the position of the player
        this->position = position;
    }

    int getPosition(){
        return position;
    }
};

// Board class
class Board{
    int size;
    unordered_map<int, int> snakes, ladders;
public:
    Board(int size) : size(size) {}

    int getSize(){
        return size;
    }

    void addSnake(int start, int end){  // assuming no snake share the same start point
        snakes[start] = end;
    }

    int checkPositionForSnake(int position){
        if(snakes.count(position)){
            return snakes[position];
        }else return position;
    }
};

// Game class
class Game{
    queue<Player> players;
    Board board;
    Dice* dice;
public:
    Game(queue<Player> players, Board board, Dice* dice) : players(players), board(board), dice(dice) {}
    bool gameEnded(int position){
        return position >= board.getSize();
    }
    void startGame(){
        while(true){
            Player currentPlayer = players.front();
            players.pop();
            int step = dice->roll();
            int initialPosition = currentPlayer.getPosition();
            currentPlayer.move(step);
            int playerPosition = currentPlayer.getPosition();
            playerPosition = board.checkPositionForSnake(playerPosition);
            currentPlayer.setPosition(playerPosition);

            cout<<currentPlayer.getName()<<" rolled a "<<step<<" and moved from "<<initialPosition<<" to "<<playerPosition<<endl;

            if(gameEnded(playerPosition)) break;
            
            players.push(currentPlayer);
        }
    }

};

int main() {
    // Initialize random seed
    srand(time(0));

    queue<Player> players;
    players.push(Player("Player1"));
    players.push(Player("Player2"));

    
    Board board(100);

    
    board.addSnake(99, 10);
    board.addSnake(70, 50);
    board.addSnake(28, 5);
    board.addSnake(43, 17);

    // Create a normal dice
    NormalDice* dice = new NormalDice();

    // Create and start the game
    Game game(players, board, dice);
    cout << "Starting Snake and Ladder game with 2 players...\n";
    game.startGame();
    cout << "Game Over!\n";

    
    delete dice;
    return 0;
} 