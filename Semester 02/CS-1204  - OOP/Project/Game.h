#include <iostream>   // for input/output operations
#include <fstream>    // for file handling
#include <string>     // for using string data type
#include <cstdlib>    // for rand(), srand()
#include <ctime>      // for time()
#include <limits>     // for numeric_limits
#include <iomanip>    // for stream manipulators like setw(), setfill()
using namespace std;

// Terminal color codes for formatted output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Abstract base class for all games
class Game {
public:
    // Pure virtual function to define gameplay logic
    virtual void play(Player &player) = 0;

    // Virtual destructor for safe polymorphic cleanup
    virtual ~Game() {}

protected:
    // Prompts user to retry the game
    bool askRetry() {
        char choice;
        cout << YELLOW << "Play again? (y/n): " << RESET;
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }
};
