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

// Time Travel Quiz 
class TimeTravelQuiz : public Game {
private:
    struct Event { string year; string question; string options[4]; int correct; };
    Event events[3] = {
        {"1947", "What major event happened in 1947?", {"Pakistan Independence", "World War II ended", "Apollo 11 landed", "Internet invented"}, 0},
        {"1969", "What happened in 1969?", {"Fall of Berlin Wall", "Moon Landing", "Partition of India", "WWI ended"}, 1},
        {"2001", "Which event shook the world in 2001?", {"COVID-19 Pandemic", "9/11 Attacks", "Y2K Bug", "WWII ended"}, 1}
    };
public:
    void play(Player &player) override {
        do {
            srand((unsigned)time(0));
            int score = 0;
            cout << BLUE << setfill(' ')<<right<<setw(65)<< "Time Travel Quiz \n" << RESET;
            for (int i = 0; i < 3; i++) {
                Event e = events[i];
                cout << "\nYear: " << e.year << "\n" << e.question << "\n";
                for (int j = 0; j < 4; j++) cout << j+1 << ". " << e.options[j] << "\n";
                int answer;
                cout << "Your choice (1-4): ";
                while (!(cin >> answer) || answer < 1 || answer > 4) {
                    cout << "Invalid input. Choose 1-4: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (answer - 1 == e.correct) { cout << GREEN << "Correct!\n" << RESET; score += 10; }
                else { cout << RED << "Wrong! Correct: " << e.options[e.correct] << "\n" << RESET; }
            }
            cout << YELLOW << "\nYou scored " << score << " points.\n" << RESET;
            player.updateScore(score);
        } while (askRetry());
    }
};
