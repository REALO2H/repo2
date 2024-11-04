#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char current_marker;
    int current_player;

public:
    TicTacToe() {
        resetBoard();
    }

    void resetBoard() {
        char initial = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = initial++;
            }
        }
    }

    void drawBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "--|---|--\n";
        }
        cout << "\n";
    }

    bool placeMarker(int slot) {
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = current_marker;
            return true;
        }
        return false;
    }

    int checkWin() {
        // Rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
        }
        // Diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

        return 0;
    }

    void swapPlayerAndMarker() {
        current_marker = (current_marker == 'X') ? 'O' : 'X';
        current_player = (current_player == 1) ? 2 : 1;
    }

    void startGame() {
        cout << "Player 1, choose your marker (X or O): ";
        cin >> current_marker;
        current_player = 1;

        int winner = 0;
        for (int i = 0; i < 9; i++) {
            drawBoard();
            cout << "Player " << current_player << ", enter your slot (1-9): ";
            int slot;
            cin >> slot;

            if (slot < 1 || slot > 9) {
                cout << "Invalid slot! Try again.\n";
                i--;
                continue;
            }

            if (!placeMarker(slot)) {
                cout << "Slot already occupied! Try again.\n";
                i--;
                continue;
            }

            winner = checkWin();
            if (winner != 0) break;

            swapPlayerAndMarker();
        }

        drawBoard();

        if (winner == 0) {
            cout << "It's a tie!\n";
        } else {
            cout << "Player " << winner << " wins!\n";
        }
    }
};

int main() {
    TicTacToe game;
    game.startGame();
    return 0;
}