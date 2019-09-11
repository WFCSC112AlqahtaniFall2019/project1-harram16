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

    //while loop runs until you hit the battleship
    while (hit == false) {
        //user enters guess location
        cout << "What is your row  guess, then column guess?";
        cin >> guessR;
        cin >> guessC;

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

    }
    return 0;
}