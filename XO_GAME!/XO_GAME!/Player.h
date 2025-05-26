#include<iostream>
#include"Board.h"
using namespace std;
class Player:Board {
public:
    char symbol;
    bool isHuman;

    Player(char s, bool human) 
: symbol(s), isHuman(human) {}

    void makeMove(Board& board) {
        int i, j;
        if (isHuman) {
            cout << "Enter two positions (i j): ";
            cin >> i >> j;
            while (!board.placeMark(i, j, symbol)) {
                cout << "Invalid move! Try again: ";
                cin >> i >> j;
            }
        }
        else {
            do {
                i = rand() % 3;
                j = rand() % 3;
            } while (!board.placeMark(i, j, symbol));
            cout << "Computer placed at: " << i << ", " << j << endl;
        }
    }
};
