/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    TicTacToe game;
    int numPlayers;
    int row;
    int column;
    srand(time(0));
    cout << "Welcome to Tic Tac Toe game! Enter 1 to play alone or 2 to play with another person" << endl;
    cin >> numPlayers;

    if (numPlayers == 2) {
        cout << "Game set for 2 players. Player 1 - X and Player 2 - O" << endl;


        cout << "Board's columns and rows ranges from 0 -2." << endl;

        game.initializeBoard();
        game.printBoard();

        while (game.checkForWin() == false && game.isBoardFull() == false) {
            cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
            cout << "Enter the row and column you would like to mark on the board" << endl;
            cin >> row >> column;
            while (row > 2 || column > 2) {
                cout << "Please enter valid value for row and column. They range from 0 to 2." << endl;
                cin >> row >> column;
            }
            game.placeMark(row, column);
            game.printBoard();
            if (game.checkForWin() == true) {
                cout << "Game Over.Player " << game.getCurrentPlayerNumber() << " won.";
            }
            if (game.isBoardFull() == true && game.checkForWin() == false) {
                cout << "Game over. Game is draw!";
            }
            game.changePlayer();
        }
    }
    else {
        cout << "Game set for 1 player. Player 1 - X and Computer - O" << endl;

        cout << "Board's columns and rows ranges from 0 -2." << endl;

        game.initializeBoard();
        game.printBoard();

        while (game.checkForWin() == false && game.isBoardFull() == false) {
            if (game.getCurrentPlayerNumber() == 1) {
                cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
                cout << "Enter the row and column you would like to mark on the board" << endl;
                cin >> row >> column;
                while (row > 2 || column > 2) {
                    cout << "Please enter valid value for row and column. They range from 0 to 2." << endl;
                    cin >> row >> column;
                }
                game.placeMark(row, column);
                game.printBoard();
                if (game.checkForWin() == true) {
                    cout << "Game Over.Player " << game.getCurrentPlayerNumber() << " won.";
                }
                if (game.isBoardFull() == true && game.checkForWin() == false) {
                    cout << "Game over. Game is draw!";
                }
                game.changePlayer();
            } else {
                cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
                row = rand() % 3;
                column = rand() % 3;
                if (row )
                game.placeMark(row, column);
                game.printBoard();
                if (game.checkForWin() == true) {
                    cout << "Game Over.Player " << game.getCurrentPlayerNumber() << " won.";
                }
                if (game.isBoardFull() == true && game.checkForWin() == false) {
                    cout << "Game over. Game is draw!";
                }
                game.changePlayer();
            }

        }

    }









    // FINISH ME

    return 0;
}