#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>  // For stream manipulators like setw(), setfill()
using namespace std;

// Terminal color codes for formatted output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Number Guess Game class derived from Game
class NumberGuess : public Game {
public:
    // Implements the gameplay loop for number guessing
    void play(Player &player) override {
        do {
            int maxNumber, attemptsAllowed;
            int choice;

            // Display game title
            cout << setfill(' ') << right << setw(69) << "Number Guess Game\n" << RESET;

            // Prompt for difficulty selection
            cout << "\nSelect Difficulty: 1. Easy  2. Hard\nChoice: ";
            while (!(cin >> choice) || (choice != 1 && choice != 2)) {
                cout << "Invalid choice. Try again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Set game parameters based on difficulty
            if (choice == 1) { maxNumber = 10; attemptsAllowed = 5; }
            else { maxNumber = 50; attemptsAllowed = 7; }

            // Generate secret number
            srand((unsigned)time(0));
            int secret = rand() % maxNumber + 1;
            int guess, attempts = 0;
            bool won = false;

            // Main guessing loop
            while (attempts < attemptsAllowed) {
                cout << "Guess the number (1-" << maxNumber << "): ";
                while (!(cin >> guess) || guess < 1 || guess > maxNumber) {
                    cout << "Invalid input. Enter between 1 and " << maxNumber << ": ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                attempts++;
                if (guess == secret) {
                    cout << GREEN << "You guessed it!\n" << RESET;
                    won = true;
                    break;
                }
                else if (guess < secret) cout << "Too low!\n";
                else cout << "Too high!\n";
            }

            // Update score or show loss message
            if (won) player.updateScore((attemptsAllowed - attempts + 1) * 10);
            else cout << RED << "You lose! Number was: " << secret << "\n" << RESET;

        } while (askRetry());  // Prompt to play again
    }
};