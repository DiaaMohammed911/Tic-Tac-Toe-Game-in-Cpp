#include<iostream>
#include"Board.h"
#include"Player.h"
using namespace std;

class Game :Board{
private:
    Board board;
    Player* player1;
    Player* player2;

public:
    Game() {
        srand((unsigned)time(NULL));
        char choice;
        cout << "Do you want to be X or O? ";
        cin >> choice;
        if (choice == 'X') {
            player1 = new Player('X', true);
            player2 = new Player('O', false);
        }
        else {
            player1 = new Player('O', true);
            player2 = new Player('X', false);
        }
    }

    void play() {
        board.Draw();
        Player* current = player1;
        while (true) {
            current->makeMove(board);
            system("cls");
            board.Draw();

            char winner = board.checkWinner();
            if (winner != ' ') {
                cout << (winner == player1->symbol ? "You win!" : "Computer wins!") << endl;
                break;
            }
            if (board.isFull()) {
                cout << "It's a draw!" << endl;
                break;
            }
            current = (current == player1) ? player2 : player1;
        }
    }
};
