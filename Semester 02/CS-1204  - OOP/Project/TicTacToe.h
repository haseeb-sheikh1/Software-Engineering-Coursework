#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>  // to use stream manipulators like setw(), setfill()
using namespace std;

//  COLORS FOR TERMINAL OUTPUT 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// tic tac toe game
class Board {
private:
    char boardArr[3][3];
public:
    Board() { resetBoard(); }
    void resetBoard() {
        char ch = '1';
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                boardArr[i][j] = ch++;
    }
    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " ";
            for (int j = 0; j < 3; ++j) {
                cout << boardArr[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }
    bool updateBoard(int position, char symbol) {
        if (position < 1 || position > 9) return false;
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        if (boardArr[row][col] == 'X' || boardArr[row][col] == 'O') return false;
        boardArr[row][col] = symbol;
        return true;
    }
    char checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (boardArr[i][0] == boardArr[i][1] && boardArr[i][1] == boardArr[i][2]) return boardArr[i][0];
            if (boardArr[0][i] == boardArr[1][i] && boardArr[1][i] == boardArr[2][i]) return boardArr[0][i];
        }
        if (boardArr[0][0] == boardArr[1][1] && boardArr[1][1] == boardArr[2][2]) return boardArr[0][0];
        if (boardArr[0][2] == boardArr[1][1] && boardArr[1][1] == boardArr[2][0]) return boardArr[0][2];
        return ' ';
    }
    bool isFull() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (boardArr[i][j] != 'X' && boardArr[i][j] != 'O') return false;
        return true;
    }
};

class TicTacToe : public Game {
private:
    Board board;
    char currentPlayer;
    void switchPlayer() { currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; }
public:
    TicTacToe() { currentPlayer = 'X'; }
    void play(Player &player) override {
        do {
            board.resetBoard();
            currentPlayer = 'X';
            cout << BLUE << setfill(' ')<<right<<setw(65)<<"Tic Tac Toe \n" << RESET;
            board.displayBoard();
            while (true) {
                int position;
                cout << "Player " << currentPlayer << ", enter position (1-9): ";
                while (!(cin >> position)) {
                    cout << "Invalid input! Enter 1-9: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (!board.updateBoard(position, currentPlayer)) {
                    cout << RED << "? Invalid move! Try again.\n" << RESET;
                    continue;
                }
                board.displayBoard();
                char winner = board.checkWin();
                if (winner == 'X' || winner == 'O') {
                    cout << GREEN << "?? Player " << winner << " wins!\n" << RESET;
                    player.updateScore(20);
                    break;
                } else if (board.isFull()) {
                    cout << YELLOW << "? It's a draw!\n" << RESET;
                    player.updateScore(10);
                    break;
                }
                switchPlayer();
            }
        } while (askRetry());
    }
};