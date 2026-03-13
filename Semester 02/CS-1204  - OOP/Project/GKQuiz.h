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

/* General Knowledge Quiz */
class GKQuiz : public Game {
private:
    struct Question { string text; string options[4]; int correct; };
    Question questions[3] = {
        {"In which year was the University of Azad Jammu and Kashmir established?", {"1974", "1980", "1985", "1990"}, 1},
        {"Where is the main campus of the University of Azad Jammu and Kashmir located?", {"Kotli", "Mirpur", "Muzaffarabad", "Neelum"}, 2},
        {"Who is considered the father of modern physics?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 1}
    };
public:
    void play(Player &player) override {
        do {
            srand((unsigned)time(0));
            int score = 0;
            cout << BLUE << setfill(' ')<<right<<setw(65)<<"General Knowledge Quiz \n" << RESET;
            for (int i = 0; i < 3; ++i) {
                Question q = questions[i];
                cout << "\nQ" << (i+1) << ": " << q.text << "\n";
                for (int j = 0; j < 4; ++j) cout << j+1 << ". " << q.options[j] << "\n";
                int answer;
                cout << "Your choice (1-4): ";
                while (!(cin >> answer) || answer < 1 || answer > 4) {
                    cout << "Invalid input. Choose 1-4: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (answer - 1 == q.correct) { cout << GREEN << "Correct!\n" << RESET; score += 10; }
                else { cout << RED << "Wrong! Correct: " << q.options[q.correct] << "\n" << RESET; }
            }
            cout << YELLOW << "\nYou scored " << score << " points.\n" << RESET;
            player.updateScore(score);
        } while (askRetry());
    }
};

