#include<bits/stdc++.h>
using namespace std;

/*
Chess:
    The game is played between two players. One player controls an army of white pieces and the other controls the army of black pieces.
    Each army includes the following pieces: 1 King, 1 Queen, 2 Knights, 2 Rooks, 2 Bishops, 8 Pawns
    Each piece has its own way of moving on the board.
    A player may move only to an empty cell unless it is trying to capture a piece of the other player.
    A piece is captured when a player moves to a position currently occupied by a piece of the opponent.
    Each player needs to move a piece in each turn.
    The game starts with the player owning the white pieces making the first move. After this, the players play alternate turns.
    There are more rules but it is outside the scope of this problem.
*/

enum class Color{
    BLACK,
    WHITE
};

class Position{
    int row, col;
public:
    void setPosition(string s){
        row = s[0]-'a';
        col = s[1]-'1';
    }
    int getRow(){
        return row;
    }
    int getCol(){
        return col;
    }
    string getPosition(){
        return string(1, 'a'+row) + string(1, '1'+col);
    }
};

class Piece{
    Color color;
    Position position;
public:
    virtual bool isValid() = 0;
    virtual ~Piece() = default;
};