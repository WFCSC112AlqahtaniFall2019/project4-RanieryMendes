/* Class: TicTacToe
 * Author: Raniery Mendes
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    TicTacToe game;
    srand(time(0));
    // int to get from the user the number of players
    int numPlayers;

    // variables used to mark player's choice on the board
    int row;
    int column;

    //Introduce and begin the Game
    cout << "Welcome to Tic Tac Toe game! Enter 1 to play alone or 2 to play with another person" << endl;
    cin >> numPlayers;

    bool intro = false; // bool to secure a valid input

    //Check if input is valid. It must be 1 or 2
    while (!intro) {
        // if input is invalid, ask for a new one
        if(numPlayers != 1 && numPlayers != 2) {
            cout << "Number inserted is invalid. Please, either enter 1 to play alone or 2 to play with another person." << endl;
            cin >> numPlayers;
        }
        else {
            intro = true;
        }
    }

    //Game interaction for 2 players
    if (numPlayers == 2) {
        cout << "Game set for 2 players. Player 1 = X and Player 2 = O" << endl;

        cout << "Board's columns and rows ranges from 1 to 3." << endl;

        //initialize and print board.
        game.initializeBoard();
        game.printBoard();

        //while loop for playability while game is not over
        while (game.checkForWin() == false && game.isBoardFull() == false) {
            cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
            cout << "Enter the row and column you would like to mark on the board" << endl;
            cout << endl;
            cin >> row ;
            cin >> column;
            while (row > 3 ||row <= 0 || column > 3 || column <= 0) {
                cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                cin >> row >> column;
            }

            //decrement input to fit within the array's range (0-2).
            row--;
            column--;

            //mark player choice
            bool check = true;

                if (game.placeMark(row, column) == false) {
                    check = false;
                }
            while (!check) {

                cout << "Location is already marked. Please, select a new location: " << endl;
                cin >> row;
                cin >> column;

                while (row > 3 ||row <= 0 || column > 3 || column <= 0) {
                    cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                    cin >> row >> column;
                }

                row--;
                column--;

                if (game.placeMark(row, column) == false) {
                    // do nothing
                }

                else {
                    game.placeMark(row, column);
                    check = true;

                }

            }

            //print the board with the choice made
            game.printBoard();

            // if statements to check if game is over and if there is a winner.
            if (game.checkForWin() == true) {
                cout << "Game Over. Player " << game.getCurrentPlayerNumber() << " won.";
            }
            if (game.isBoardFull() == true && game.checkForWin() == false) {
                cout << "Game over. Game is draw!";
            }

            //Game is not over, go to next player's turn
            else {
                game.changePlayer();
            }
        }
    }


    //Game interaction for just 1 player
    else {
        cout << "Game set for 1 player. Player 1 - X and Player 2 (Computer) - O" << endl;

        cout << "Board's columns and rows ranges from 0 -2." << endl;


        game.initializeBoard();
        game.printBoard();

        //interaction with player(s) during the "match"

        while (game.checkForWin() == false && game.isBoardFull() == false) {
            if (game.getCurrentPlayerNumber() == 1) {
                cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
                cout << "Enter the row and column you would like to mark on the board: ";
                cin >> row >> column;

                while (row > 3 || row <= 0 ||  column > 3 || column <= 0) {
                    cout << "Please enter valid value for row and column. They range from 0 to 2." << endl;
                    cin >> row >> column;
                }

                //decrement input to fit within the array's range (0-2).
                row--;
                column--;

                //mark player's choice
                bool check = true;

                if (game.placeMark(row, column) == false) {
                    check = false;
                }
                while (!check) {

                    cout << "Location is already marked. Please, select a new location: " << endl;
                    cin >> row;
                    cin >> column;

                    while (row > 3 ||row <= 0 || column > 3 || column <= 0) {
                        cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                        cin >> row >> column;
                    }

                    row--;
                    column--;

                    if (game.placeMark(row, column) == false) {
                        // do nothing
                    }

                    else {
                        game.placeMark(row, column);
                        check = true;

                    }

                }

                //print the board with the choice made
                game.printBoard();

                // if statements to check if game is over and if there is a winner.
                if (game.checkForWin() == true) {
                    cout << "Game Over. Player " << game.getCurrentPlayerNumber() << " won.";
                }
                if (game.isBoardFull() == true && game.checkForWin() == false) {
                    cout << "Game over. Game is draw!";
                }

                //Game is not over, go to next player's turn
                else {
                game.changePlayer();}
            }

            else {
                cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;

                // get values for row and column. It will already provide values that fit within the array's range (0-2)
                row = rand() % 3;
                column = rand() % 3;

                //mark computer's choice

                bool check = true;

                if (game.placeMark(row, column) == false) {
                    check = false;
                }
                while (!check) {

                    row = rand() % 3;
                    column = rand() % 3;


                    if (game.placeMark(row, column) == false) {
                        // do nothing
                    }

                    else {
                        game.placeMark(row, column);
                        check = true;

                    }

                }


                //print the board with the choice made
                game.printBoard();

                // if statements to check if game is over and if there is a winner.
                if (game.checkForWin() == true) {
                    cout << "Game Over.Player " << game.getCurrentPlayerNumber() << " won.";
                }
                if (game.isBoardFull() == true && game.checkForWin() == false) {
                    cout << "Game over. Game is draw!";
                }

                //Game is not over, go to next player's turn
                else {
                    game.changePlayer();
                }
            }

        }

    }

    //destroy TicTacToe's object called "game"
    TicTacToe ();


    return 0;
}