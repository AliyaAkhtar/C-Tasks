#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
bool tie = false;
string player1 = "";
string player2 = "";

void initializeGame() {
    // Reset the game state
    token = 'X';
    tie = false;

    // Reset the game board to its initial values
    char initialSpace[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            space[i][j] = initialSpace[i][j];
        }
    }
}

void gamearea() {
    system("cls");
    cout << "X -> " << player1 << endl;
    cout << "O -> " << player2 << endl;
    cout << "    |     |    " << endl;
    cout << "  " << space[0][0] << " |   " << space[0][1] << " |   " << space[0][2] << "  " << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << "  " << space[1][0] << " |   " << space[1][1] << " |   " << space[1][2] << "  " << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << "  " << space[2][0] << " |   " << space[2][1] << " |   " << space[2][2] << "  " << endl;
}

void playgame() {
    int digit;

    if (token == 'X') {
        cout << player1 << "'s Turn!";
        cin >> digit;
    } else if (token == 'O') {
        cout << player2 << "'s Turn!";
        cin >> digit;
    }

    if (digit == 1) {
        row = 0;
        column = 0;
    } else if (digit == 2) {
        row = 0;
        column = 1;
    } else if (digit == 3) {
        row = 0;
        column = 2;
    } else if (digit == 4) {
        row = 1;
        column = 0;
    } else if (digit == 5) {
        row = 1;
        column = 1;
    } else if (digit == 6) {
        row = 1;
        column = 2;
    } else if (digit == 7) {
        row = 2;
        column = 0;
    } else if (digit == 8) {
        row = 2;
        column = 1;
    } else if (digit == 9) {
        row = 2;
        column = 2;
    } else {
        cout << "Invalid Choice!" << endl;
        return;
    }

    if(token == 'X' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'X';
        token = 'O';
    }else if(token == 'O' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'O';
        token = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!n Please choose another!!nn";
        playgame();
    }
    /* Ends */
    gamearea();
}

bool gamecheck() {
    // checking whether the game is won horizontally or vertically
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
            return true;
        }
    }
    // check whether the game is won diagonally
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }
    // check whether the game is still ongoing
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }
    // game is a draw
    tie = true;
    return true;
}

int main() {
    char playAgain;

    do {
        cout << "Enter the name for the first player: ";
        cin >> player1;
        cout << "Enter the name for the second player: ";
        cin >> player2;

        while (!gamecheck()) {
            gamearea();
            playgame();
            if (gamecheck()) {
                break; // Break the loop if the game is over
            }
        }

        if (token == 'X' && tie == false) {
            cout << player2 << " Wins!" << endl;
        } else if (token == 'O' && tie == false) {
            cout << player1 << " Wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            initializeGame(); // Reset the game state
        } else {
            cout << "Goodbye!" << endl;
            break; // Exit the loop and end the program
        }
    } while (true);

    return 0;
}
