//
// Created by Addie Harrison on 9/11/19.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    //battleships location
    srand(time(NULL));
    int randomNumR = rand() % 3 + 1;
    int randomNumC = rand() % 3 + 1;
    int guessR;
    int guessC;

    vector<string> battleship(9, " ");

    bool hit = false;
    int index = 0;
    int trackGuesses = 0;
    bool outOfBounds = false;

    //while loop runs until you hit the battleship
    while (hit == false) {
        //user enters guess location
        cout << "What is your row  guess, then column guess?";
        cin >> guessR;
        cin >> guessC;

        //error message if out of row bounds and exits the while loop(ending the game)
        if (guessR != 1 && guessR != 2 && guessR != 3) {
            cout << "ERROR you have entered out of bounds. Game Over.";
            outOfBounds = true;
            break;
        }
        //error message if out of column bounds and exits the while loop(ending the game)
        if (guessC != 1 && guessC != 2 && guessC != 3) {
            cout << "ERROR you have entered out of bounds. Game Over.";
            outOfBounds = true;
            break;
        }

        //setting index for the location on the battleship
        if (guessR == 1) {
            if (guessC == 1) {
                index = 0;
            } else if (guessC == 2) {
                index = 1;
            } else {
                index = 2;
            }
        } else if (guessR == 2) {
            if (guessC == 1) {
                index = 3;
            } else if (guessC == 2) {
                index = 4;
            } else {
                index = 5;
            }
        } else {
            if (guessC == 1) {
                index = 6;
            } else if (guessC == 2) {
                index = 7;
            } else {
                index = 8;
            }
        }


        //checking if you hit the battle ship
        if (guessR == randomNumR && guessC == randomNumC) {
            battleship.at(index) = "X";
            hit = true;
        } else {
            battleship.at(index) = "O";
        }

        //printing battleship board
        cout << battleship.at(0) << "!" << battleship.at(1) << "!" << battleship.at(2) << endl;
        cout << "~~~~~" << endl;
        cout << battleship.at(3) << "!" << battleship.at(4) << "!" << battleship.at(5) << endl;
        cout << "~~~~~" << endl;
        cout << battleship.at(6) << "!" << battleship.at(7) << "!" << battleship.at(8) << endl;
        ++trackGuesses;
    }
    //use if for correct guess so it does not print if you enter out of bounds
    if (outOfBounds == false) {
        cout << "You have guessed correctly!" << endl;
        cout << "It took you " << trackGuesses << " to hit the battleship!";
    }

    return 0;
}