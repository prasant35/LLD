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

struct Position{
    int row, col;
    Position(string s){
        // positions in chess are flipped, cell(0,0) is a8, (0,8) is a1
        col = s[0]-'a';
        row = 8 - (s[1] - '0');;
    }

    string getPosition(){
        return string(1, 'a' + col) + to_string(8 - row);
    }
};
 
class Piece{
protected: // this members are going to get inherited by derived classes, if we make then private, they wont be able to access it.
    Color color;
    Position position;
public:
    Piece(Color color, Position position) : color(color), position(position) {}
    virtual ~Piece() = default;

    Color getColor() {return color;}
    Position getPos() {return position;}
    
    virtual bool isValidMove(Position from, Position to, const vector<vector<Piece*>>& board) = 0;
    virtual string getSymbol() = 0; // for printing the chessboard
};

class Knight : public Piece{

public:
    Knight(Color color, Position position) : Piece(color, position) {}

    bool isValidMove(Position from, Position to, const vector<vector<Piece*>>& board){
        int dx = abs(from.row - to.row);
        int dy = abs(from.col - to.col);

        // knight makes L-shape move
        if(!((dx == 2) && (dy == 1)) && !((dy == 2) && (dx == 1))){
            return false;
        }

        // cant capture our own color piece
        Piece *target = board[to.row][to.col];
        if(target and target->getColor() == this-> color){
            return false;
        }

        return true;
    }

    string getSymbol(){
        return (getColor() == Color::WHITE ? "WN" : "BN");
    }
};

class Board{
    vector<vector<Piece*>> board;
public:
    Board(){
        board = vector<vector<Piece*>>(8, vector<Piece*>(8, nullptr));
    }

    void setPiece(Piece* piece, Position pos){
        board[pos.row][pos.col] = piece;
    }

    Piece* getPieceAt(Position pos){
        return board[pos.row][pos.col];
    }

    void init(){
        // manually initiallize the board to starting position
        Piece* WN1 = new Knight(Color::WHITE, Position("b1"));
        Piece* WN2 = new Knight(Color::WHITE, Position("g1"));

        Piece* BN1 = new Knight(Color::BLACK, Position("b8"));
        Piece* BN2 = new Knight(Color::BLACK, Position("g8"));

        setPiece(WN1, WN1->getPos());
        setPiece(WN2, WN2->getPos());
        setPiece(BN1, BN1->getPos());
        setPiece(BN2, BN2->getPos());
    }

    void printBoard(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]){
                    cout<<board[i][j]->getSymbol()<<" ";
                }else cout<<"-- ";
            }cout<<endl;
        }
    }

};

int main(){
    // vector<vector<Piece*>> board(8, vector<Piece*>(8, nullptr));
    // board[7][1] = new Knight(Color::WHITE, Position("b1"));
    // cout<<board[7][1]->isValidMove(Position("b1"), Position("d2"), board)<<endl;

    // board[6][3] = new Knight(Color::WHITE, Position("d2"));

    // cout<<board[7][1]->isValidMove(Position("b1"), Position("d2"), board)<<endl;
    // cout<<board[7][1]->isValidMove(Position("b1"), Position("d1"), board)<<endl;

    Board *board = new Board();
    board->init();
    board->printBoard();
}