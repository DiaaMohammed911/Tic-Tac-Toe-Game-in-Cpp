#pragma once
#include<iostream>
using namespace std;
class Board
{
	char board[3][3];
public:
	Board() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				board[i][j] = ' ';
			}
		}
	}
	void Draw() {
        for (int i = 0; i < 7; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < 4; j++) cout << "---";
            }
            else {
                for (int j = 0; j < 4; j++) {
                    if (j < 3) cout << "| " << board[i / 2][j] << " ";
                    else cout << "|   ";
                }
            }
            cout << endl;
        }
    }
    bool placeMark(int i, int j, char mark) {
        if (board[i][j] == ' ') {
            board[i][j] = mark;
            return true;
        }
        return false;
    }
    char checkWinner() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' &&
                board[i][0] == board[i][1] &&
                board[i][1] == board[i][2])
                return board[i][0];
        }

        for (int i = 0; i < 3; i++) {
            if (board[0][i] != ' ' &&
                board[0][i] == board[1][i] &&
                board[1][i] == board[2][i])
                return board[0][i];
        }

        if (board[0][0] != ' ' &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
            return board[0][0];

        if (board[0][2] != ' ' &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
            return board[0][2];

        return ' ';
    }
    bool isFull() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ') return false;
        return true;
    }
};