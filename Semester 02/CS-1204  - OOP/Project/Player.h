/* 

   CLASS: Player
   PURPOSE: Store and manage player info 
            like name, score, coins, etc.

*/
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

// Player class handles profile data and score tracking
class Player {
private:
    string name;         // Player's name
    int highestScore;    // Highest score achieved
    int totalGames;      // Total games played
    int coins;           // Coins earned based on score

public:
    // Constructor initializes player and loads profile
    Player(string playerName = "Guest") {
        name = playerName;
        highestScore = 0;
        totalGames = 0;
        coins = 0;
        loadProfile();
    }

    // Updates score, coins, and game count
    void updateScore(int score) {
        totalGames++;
        coins += score / 10;
        if (score > highestScore) highestScore = score;
        saveProfile();
    }

    // Displays current player profile
    void displayProfile() const {
        cout << BLUE << "\nPlayer: " << name << RESET
             << "\nHighest Score: " << highestScore
             << "\nGames Played: " << totalGames
             << "\nCoins: " << coins << "\n";
    }

    // Returns highest score
    int getHighestScore() const { return highestScore; }

    // Loads profile data from scores.txt
    void loadProfile() {
        ifstream file("scores.txt", ios::in);
        if (!file) return;

        string pname;
        int score, games, c;
        while (file >> pname >> score >> games >> c) {
            if (pname == name) {
                highestScore = score;
                totalGames = games;
                coins = c;
                break;
            }
        }
        file.close();
    }

    // Saves or updates profile data in scores.txt
    void saveProfile() {
        fstream file("scores.txt", ios::in | ios::out);
        if (file) {
            string pname;
            int score, games, c;
            streampos lineStart;
            while (!file.eof()) {
                lineStart = file.tellg();
                file >> pname >> score >> games >> c;
                if (!file) break;
                if (pname == name) {
                    file.seekp(lineStart);
                    file << name << " " << highestScore << " "
                         << totalGames << " " << coins << "    \n";
                    file.close();
                    return;
                }
            }
            file.clear();
            file.seekp(0, ios::end);
            file << name << " " << highestScore << " "
                 << totalGames << " " << coins << "\n";
            file.close();
        } else {
            ofstream newFile("scores.txt");
            newFile << name << " " << highestScore << " "
                    << totalGames << " " << coins << "\n";
            newFile.close();
        }
    }
};