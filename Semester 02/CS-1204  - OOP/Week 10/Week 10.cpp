	//                                                             WEEK # 11- FILE HANDLING 
	//                                                               DATED: 15-8-2025
	//                                                  TASK NUMBER 1(WRITING,READING AND APPENDING)


#include <iostream>
#include <fstream>   // for file handling
#include <string>
using namespace std;

int main() {
    fstream file;
    
    // 1. Create and Write into file
    file.open("notes.txt", ios::out);  // ios::out creates a new file or overwrites if already exists
    if (!file) {
        cout << "Error creating file!" << endl;
        return 1;
    }
    file << "Hello.\n";
    file << "Day: Friday.\n";
    file << "Date: 15-8-2025.\n";
    file.close();
    cout << "File created and written successfully.\n\n";

    // 2. Read file contents
    file.open("notes.txt", ios::in);  // ios::in = read mode
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }
    cout << "Reading file contents:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    cout << endl;

    // 3. Append name and roll number
    file.open("notes.txt", ios::app);  // ios::app = append mode (does not overwrite)
    if (!file) {
        cout << "Error opening file for appending!" << endl;
        return 1;
    }
    file << "Name: Haseeb Sheikh\nRoll Number: 2024-SE-31\n";  
    file.close();
    cout << "Name and roll number appended successfully.\n";

    return 0;
}


//                                                           TASK NUMBER 2(COUNTING THE NUMBER OF LINES IN A FILE)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("notes.txt");  // open file in read mode
    if (!file) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        count++;   // count each line
    }

    file.close();

    cout << "Total number of lines in the file: " << count << endl;

    return 0;
}




//                                                           TASK NUMBER 3(COPYING DATA FROM ONE FILE TO ANOTHER)

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("notes.txt");      // source file
    ofstream outfile("copy_notes.txt"); // destination file

    if (!infile) {
        cout << "Error: Could not open notes.txt!" << endl;
        return 1;
    }
    if (!outfile) {
        cout << "Error: Could not create copy_notes.txt!" << endl;
        return 1;
    }

    char ch;
    while (infile.get(ch)) {   // read character by character
        outfile.put(ch);       // write into destination
    }

    infile.close();
    outfile.close();

    cout << "File copied successfully to copy_notes.txt" << endl;
    return 0;
}




//                                                     TASK NUMBER 4(ORGANIZING STUDENT'S DATA IN A FILE)
    // TASK 4: Write Student Details and Then Read Them

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1. Write student details into the file
    ofstream outfile("students.txt");  // open in write mode
    if (!outfile) {
        cout << "Error: Could not create students.txt!" << endl;
        return 1;
    }

    outfile << "Name\t\tRoll Number" << endl;
    outfile << "Ali\t\t1609" << endl;
    outfile << "Adam\t\t1644" << endl;
    outfile << "Wahaj\t\t1687" << endl;

    outfile.close();
    cout << "Student details written successfully to students.txt\n" << endl;

    // 2. Read student details from the file
    ifstream infile("students.txt");   // open in read mode
    if (!infile) {
        cout << "Error: Could not open students.txt for reading!" << endl;
        return 1;
    }

    cout << "Reading student details from file:\n" << endl;

    string line;
    while (getline(infile, line)) {
        cout << line << endl;   // print each line
    }

    infile.close();
    return 0;
}



