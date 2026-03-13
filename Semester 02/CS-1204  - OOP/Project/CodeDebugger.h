#include <iostream>   // for input/output operations
#include <fstream>    // for file handling
#include <string>     // for using string data type
#include <cstdlib>    // for rand(), srand()
#include <ctime>      // for time()
#include <limits>     // for numeric_limits
#include <iomanip>    // for stream manipulators like setw(), setfill()
using namespace std;

//  COLORS FOR TERMINAL OUTPUT 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// CodeDebugger class inherits from Game and implements a debugging quiz
class CodeDebugger : public Game {
private:
    // Structure to hold each question's code snippet, options, and correct answer index
    struct Question { string code; string options[4]; int correct; };

    // Array of predefined questions for the debugging challenge
    Question questions[6] = {
        {"int x = 5\ncout << x;", {"Missing semicolon", "Wrong datatype", "Extra brackets", "No error"}, 0},
        {"for (int i=0; i<5; i--)\n  cout << i;", {"Infinite loop", "Syntax error", "Missing braces", "No error"}, 0},
        {"string s = 10;\ncout << s;", {"Correct code", "Type mismatch", "Missing quotes", "No error"}, 1},
        {"int arr[5];\narr[5] = 10;", {"Correct indexing", "Array out of bounds", "Missing semicolon", "No error"}, 1},
        {"#include <iostream>\nusing namespace std;\nint main(){cout<<Hello;}", {"Missing quotes around string", "Extra braces", "No return 0", "No error"}, 0},
        {"#include <iostream>\nint main(){\n cout<<\"Hi\"<<endl;\n return; }", {"Missing return value", "Missing semicolon", "Wrong header", "No error"}, 0}
    };

public:
    // Main gameplay loop for the CodeDebugger challenge
    void play(Player &player) override {
        do {
            srand((unsigned)time(0));  // Seed random number generator
            int score = 0;
            cout << BLUE << setfill(' ')<<right<<setw(65)<<"Code Debugger Challenge \n" << RESET;

            // Loop through 4 random questions
            for (int i = 0; i < 4; ++i) {
                int qIndex = rand() % 6;
                Question q = questions[qIndex];

                // Display question and options
                cout << "\nBuggy Code:\n" << q.code << "\n";
                for (int j = 0; j < 4; ++j) cout << j+1 << ". " << q.options[j] << "\n";

                // Input validation for answer
                int answer;
                cout << "Your choice (1-4): ";
                while (!(cin >> answer) || answer < 1 || answer > 4) {
                    cout << "Invalid input. Choose 1-4: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                // Check answer and update score
                if (answer - 1 == q.correct) {
                    cout << GREEN << "Correct!\n" << RESET;
                    score += 15;
                } else {
                    cout << RED << "Wrong! Correct: " << q.options[q.correct] << "\n" << RESET;
                }
            }

            // Display final score and update player profile
            cout << YELLOW << "\nYou scored " << score << " points.\n" << RESET;
            player.updateScore(score);
        } while (askRetry());  // Ask if player wants to retry
    }
};