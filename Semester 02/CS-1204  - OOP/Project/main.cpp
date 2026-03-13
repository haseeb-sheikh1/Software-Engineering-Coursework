// including libraries
#include <iostream>   // for input/output operations
#include <fstream>    // for file handling
#include <string>     // for using string data type
#include <cstdlib>    // for rand(), srand()
#include <ctime>      // for time()
#include <limits>     // for numeric_limits
#include <iomanip>    // for stream manipulators like setw(), setfill()
// including header files 
#include"Player.h"         // Player class definition
#include"Game.h"           // Game base class
#include"NumberGuess.h"    // Number Guess game
#include"TicTacToe.h"      // Tic Tac Toe game
#include"CodeDebugger.h"   // Code Debugger Challenge
#include"TimeTravelQuiz.h" // Time Travel Quiz game
#include"GKQuiz.h"         // General Knowledge Quiz
using namespace std;

//  COLORS FOR TERMINAL OUTPUT 
#define RESET   "\033[0m"   // Reset color
#define RED     "\033[31m"  // Red color
#define GREEN   "\033[32m"  // Green color
#define YELLOW  "\033[33m"  // Yellow color
#define BLUE    "\033[34m"  // Blue color

// passphrase authentication - sets default if file is missing
bool checkPassphrase() {
    string stored, entered;
    ifstream file("passphrase.txt");

    if (file) {
        getline(file, stored);
        file.close();
        if (stored.empty()) {
            cerr << "Error: passphrase.txt is empty." << endl;
            return false;
        }
    } else {
        // File doesn't exist, create it with default passphrase
        stored = "default";
        ofstream outfile("passphrase.txt");
        outfile << stored;
        outfile.close();
        cout << "passphrase.txt not found, default passphrase set" << endl;
    }

    // Allow up to 3 attempts for user to enter correct passphrase
    for (int attempts = 1; attempts <= 3; ++attempts) {
        cout << "Enter passphrase: ";
        cin >> entered;

        if (entered == stored) {
            cout << GREEN << "Access Granted!\n" << RESET;
            return true;
        } else {
            cout << RED << "Incorrect passphrase.!\n" << RESET;
            if (attempts < 3)
                cout << "Try again." << endl;
            else
                cout << RED << "Access Denied!\n" << RESET;
        }
    }

    return false;
}

// Main Function
int main() {
    const int GK_UNLOCK_THRESHOLD = 20;       // Score needed to unlock GK Quiz
    const int DEBUG_UNLOCK_THRESHOLD = 15;    // Score needed to unlock Code Debugger

    if (!checkPassphrase()) {
        cout << RED << "Access Denied!\n" << RESET;
        return 0;
    }

    string name;
    cout << "Enter your name: ";
    cin >> name;
    Player player(name);  // Create player object

    // Instantiate game objects
    NumberGuess ng;
    TicTacToe ttt;
    CodeDebugger dbg;
    TimeTravelQuiz ttq;
    GKQuiz gk;

    bool gkUnlocked = false;     // GK Quiz lock status
    bool dbgUnlocked = false;    // Code Debugger lock status

    int choice;
    do {
        // Display main menu
        cout << YELLOW << setfill(' ') << right <<setw(65) << " Main Menu \n" << RESET;
        cout << "1. Number Guess               " << GREEN << "[Available]\n" << RESET;
        cout << "2. Tic Tac Toe                " << GREEN << "[Available]\n" << RESET;
        cout << "3. Code Debugger Challenge    "
             << (dbgUnlocked ? (string(GREEN) + "[Available]\n" + RESET)
                             : (string(RED) + "[Locked: Score " + to_string(DEBUG_UNLOCK_THRESHOLD) + "+]\n" + RESET));
        cout << "4. Time Travel Quiz           " << GREEN << "[Available]\n" << RESET;
        cout << "5. General Knowledge Quiz     "
             << (gkUnlocked ? (string(GREEN) + "[Available]\n" + RESET)
                            : (string(RED) + "[Locked: Score " + to_string(GK_UNLOCK_THRESHOLD) + "+]\n" + RESET));
        cout << "6. Profile\n";
        cout << "7. Exit\nChoice: ";

        // Input validation for menu choice
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            cout << "Invalid choice. Try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Handle menu selection
        switch (choice) {
            case 1: ng.play(player); break;
            case 2: ttt.play(player); break;
            case 3:
                if (dbgUnlocked) dbg.play(player);
                else cout << RED << "Game Locked! Score " << DEBUG_UNLOCK_THRESHOLD << "+ to unlock.\n" << RESET;
                break;
            case 4: ttq.play(player); break;
            case 5:
                if (gkUnlocked) gk.play(player);
                else cout << RED << "Game Locked! Score " << GK_UNLOCK_THRESHOLD << "+ to unlock.\n" << RESET;
                break;
            case 6: player.displayProfile(); break;
            case 7:
                // Display session summary before exit
                cout << YELLOW << setfill(' ')<<right<<setw(65)<< "Session Summary\n" << RESET;
                player.displayProfile();
                cout << GREEN << "Goodbye!\n" << RESET;
                break;
        }

        // Unlock games based on score
        if (!dbgUnlocked && player.getHighestScore() >= DEBUG_UNLOCK_THRESHOLD) {
            dbgUnlocked = true;
            cout << GREEN << "\nCongratulations! You unlocked the Code Debugger Challenge!\n" << RESET;
        }
        if (!gkUnlocked && player.getHighestScore() >= GK_UNLOCK_THRESHOLD) {
            gkUnlocked = true;
            cout << GREEN << "\nCongratulations! You unlocked the General Knowledge Quiz!\n" << RESET;
        }

    } while (choice != 7);  // Loop until user chooses to exit

    return 0;
}