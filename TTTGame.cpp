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
    bool intro = false;
    cout << "Welcome to Tic Tac Toe game! Enter 1 to play alone or 2 to play with another person" << endl;
    cin >> numPlayers;
    //Check if input is valid. It must be 1 or 2
    while (!intro) {
        if(numPlayers != 1 && numPlayers != 2) {
            cout << "Number inserted is invalid. Please, either enter 1 to play alone or 2 to play with another person." << endl;
            cin >> numPlayers;
        }
        else
        intro = true;
    }

    if (numPlayers == 2) {
        cout << "Game set for 2 players. Player 1 = X and Player 2 = O" << endl;


        cout << "Board's columns and rows ranges from 1 to 3." << endl;

        game.initializeBoard();
        game.printBoard();

        //while loop for playability
        while (game.checkForWin() == false && game.isBoardFull() == false) {
            cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
            cout << "Enter the row and column you would like to mark on the board" << endl;
            cin >> row >> column;
            while (row > 3 || column > 3) {
                cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                cin >> row >> column;
            }
            //decrement input to fill within the array's range (0-2).
            row--;
            column--;
            //mark player choice
            game.placeMark(row, column);
            //print the board with the choice made
            game.printBoard();

            // if statements to check if game is over and if there is a winner
            if (game.checkForWin() == true) {
                cout << "Game Over.Player " << game.getCurrentPlayerNumber() << " won.";
            }
            if (game.isBoardFull() == true && game.checkForWin() == false) {
                cout << "Game over. Game is draw!";
            }
            game.changePlayer();
        }
    }

    //
    else {
        cout << "Game set for 1 player. Player 1 - X and Computer - O" << endl;

        cout << "Board's columns and rows ranges from 0 -2." << endl;

        game.initializeBoard();
        game.printBoard();

        while (game.checkForWin() == false && game.isBoardFull() == false) {
            if (game.getCurrentPlayerNumber() == 1) {
                cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
                cout << "Enter the row and column you would like to mark on the board: ";
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

    TicTacToe();







    // FINISH ME

    return 0;
}