/* Class: TicTacToe
 * Author: Raniery Mendes
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    // create object to operate the TicTacToe class
    TicTacToe game;

    //seed time to secure random numbers
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

    //Check if input is valid. It must be 1 or 2.
    while (!intro) {
        // if input is invalid, ask for a new one
        if(numPlayers != 1 && numPlayers != 2) {
            cout << "Number inserted is invalid. Please, either enter 1 to play alone or 2 to play with another person." << endl;
            cin >> numPlayers;
        }
        //if input is valid evaluate intro to true and end while loop
        else {
            intro = true;
        }
    }

    //Game interaction for 2 players
    if (numPlayers == 2) {
        //initial instructions
        cout << "Game set for 2 players. Player 1 = X and Player 2 = O" << endl;
        cout << "Board's columns and rows ranges from 1 to 3." << endl;

        //initialize and print board.
        game.initializeBoard();
        game.printBoard();

        /* while loop for playability while game is not over
         game is not over when there iss no winner and the board is not full */
        while (game.checkForWin() == false && game.isBoardFull() == false) {

            //inform which player has the current turn
            cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
            cout << "Enter the row and column you would like to mark on the board" << endl << endl;

            //get input for location to be marked on the board
            cin >> row ;
            cin >> column;

            //check if the inputs (row and column) fit the board's range
            // if not ask for new input until a valid one be entered
            while (row > 3 ||row <= 0 || column > 3 || column <= 0) {
                cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                cin >> row >> column;
            }

            //decrement input to fit within the array's range (0-2).
            row--;
            column--;

            //code to mark player choice

            bool check = true; //bool to be used to secure location selected is free on the board

            //if function placeMark returns false, location selected is already marked on the board
            //just assign check to false iuf location is free on the board
                if (game.placeMark(row, column) == false) {
                    check = false;
                }
            //check = false will prompt a loop to ask for new input for (free) location on the board

            //while location selected is not free on the board iterate to get new valid location
            //this  loop will secure that the computer will mark an available location on the board
            while (!check) {
                //Inform use the location is already taken and ask for a new one
                cout << "Location is already marked. Please, select a new location: " << endl;
                //get new input for location (row and column)
                cin >> row;
                cin >> column;

                //check if the inputs (row and column) fit the board's range
                // if not ask for new input until a valid one be entered
                while (row > 3 ||row <= 0 || column > 3 || column <= 0) {
                    cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                    cin >> row >> column;
                }

                //decrement input to fit within the array's range (0-2).
                row--;
                column--;

                //check if new location is already marked in the
                if (game.placeMark(row, column) == false) {
                    // do nothing because check is already assigned to false so while loop will continue and ask for new input
                }

                //game.placeMark returns true so mark on location on the board and end while loop
                else {
                    game.placeMark(row, column); // mark location selected on the board
                    check = true; //assign check to true in order to end while loop

                }

            }

            //print the board with the choice made
            game.printBoard();

            //  check if game is over and if there is a winner.
            if (game.checkForWin() == true) {
                cout << "Game Over. Player " << game.getCurrentPlayerNumber() << " won.";
            }
            //check if game is over because board full and it is draw.
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
        //initial instructions
        cout << "Game set for 1 player. Player 1 - X and Player 2 (Computer) - O" << endl;
        cout << "Board's columns and rows ranges from  1 - 3." << endl;

        // select random player to initiate the game
        int playerSelection;
        playerSelection = rand()% 2 + 1;

        if (playerSelection == 1) {
            // do nothing --> keep Player 1 as the current player
        }

        else{
            //playerSelection = 2 --> switch the current player to Player 2
            game.changePlayer();
        }

        //Inform the user who starts the game
        cout << endl << "Player " << playerSelection << " starts the game!" << endl;

        //initialize and print the board to the user
        game.initializeBoard();
        game.printBoard();

        //interaction with player(s) during the "match"

        /* while loop for playability while game is not over
          game is not over when there iss no winner and the board is not full */
        while (game.checkForWin() == false && game.isBoardFull() == false) {
            //check if it is player 1's turn and ask for location
            if (game.getCurrentPlayerNumber() == 1) {
                //inform player1 that he has the current turn
                cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;
                //ask for location to mark on the board
                cout << "Enter the row and column you would like to mark on the board: ";
                cin >> row >> column;

                //check if the inputs (row and column) fit the board's range
                // if not ask for new input until a valid one be entered
                while (row > 3 || row <= 0 ||  column > 3 || column <= 0) {
                    cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                    cin >> row >> column;
                }

                //decrement input to fit within the array's range (0-2).
                row--;
                column--;

                //mark player's choice
                bool check = true;//bool to be used to secure location selected is free on the board

                //if function placeMark returns false, location selected is already marked on the board
                //so assign check to false
                if (game.placeMark(row, column) == false) {
                    check = false;
                }
                //check = false will prompt a loop to ask for new input for (free) location on the board

                //while location selected is not free on the board iterate to get new valid location
                //this  loop will secure that the computer will mark an available location on the board
                while (!check) {
                    //inform user location is already marked and ask for a new one
                    cout << "Location is already marked. Please, select a new location: " << endl;
                    //get input for new location
                    cin >> row;
                    cin >> column;

                    //check if the inputs (row and column) fit the board's range
                    // if not ask for new input until a valid one be entered
                    while (row > 3 ||row <= 0 || column > 3 || column <= 0) {
                        cout << "Please enter valid value for row and column. They range from 1 to 3." << endl;
                        cin >> row >> column;
                    }

                    //decrement input to fit within the array's range (0-2).
                    row--;
                    column--;

                    if (game.placeMark(row, column) == false) {
                        // do nothing because check is already assigned to false so while loop will continue and ask for new input
                    }

                    //game.placeMark returns true so mark on location on the board and end while loop
                    else {
                        game.placeMark(row, column); // mark location selected on the board
                        check = true; //assign check to true in order to end while loop
                    }

                }

                //print the board with the choice made
                game.printBoard();

                // check if game is over and if there is a winner.
                if (game.checkForWin() == true) {
                    cout << "Game Over. Player " << game.getCurrentPlayerNumber() << " won.";
                }
                //check if game is over because board full and it is draw.
                if (game.isBoardFull() == true && game.checkForWin() == false) {
                    cout << "Game over. Game is draw!";
                }

                //Game is not over, go to next player's turn
                else {
                game.changePlayer();
                }
            }

            //else block that will execute if it is Player2's turn, in this case the computer's turn
            else {
                //inform the user that it is the computer's turn
                cout << "It is player " << game.getCurrentPlayerNumber() << "'s turn." << endl;

                // get random values for row and column.
                // It will already provide values that fit within the array's range (0-2)
                row = rand() % 3;
                column = rand() % 3;

                //mark computer's choice

                bool check = true; //bool to be used to secure location selected is free on the board

                /*if function placeMark returns false, location selected is already
                 * marked on the board, so assign check to false*/
                if (game.placeMark(row, column) == false) {
                    check = false;
                }
                //check = false will prompt a loop to ask for new input for (free) location on the board

                //while location selected is not free on the board iterate to get new valid location
                //this  loop will secure that the computer will mark an available location on the board
                while (!check) {

                    //get new values for row and column --> set a new location to be marked
                    row = rand() % 3;
                    column = rand() % 3;

                    //check if the new random values for row and column mark a free location on the board
                    //returns false if they do not.
                    if (game.placeMark(row, column) == false) {
                        // do nothing because check is already assigned to false so while loop will continue and ask for new input
                    }

                    //game.placeMark returns true so mark on location on the board and end while loop
                    else {
                        game.placeMark(row, column); // mark location selected on the board
                        check = true;  //assign check to true in order to end while loop

                    }

                }


                //print the board with the choice made
                game.printBoard();

                // check if game is over and if there is a winner.
                if (game.checkForWin() == true) {
                    cout << "Game Over.Player " << game.getCurrentPlayerNumber() << " won.";
                }
                //check if game is over because board full and it is draw.
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

    //finish game
    return 0;
}