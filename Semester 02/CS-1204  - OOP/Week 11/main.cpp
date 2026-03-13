//                                                              LAB # 11- FILE POINTERS
//                                                                   DATED: 23-8-2025
//                                               Task number 1: using tellp() to get the write pointer position

#include<iostream>
#include<fstream> // Required for fstream
using namespace std;

int main() {
    // Open 'greet.txt' for writing.
    fstream out("greet.txt", ios::out);

    // Check if the file was opened successfully
    if (!out.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Get the initial position of the write pointer. It will be 0.
    cout << "Position of write pointer before writing: " << out.tellp() << endl;

    // Write a single character 'A'
    out << "A";

    // Get the new position of the write pointer. It will be 1 (after writing one character).
    cout << "Position of write pointer after writing a single character: " << out.tellp() << endl;

    // Close the file
    out.close();

    return 0;
}


//                                           Task number 2 : using tellg() to get the read pointer position

#include<iostream>
#include<fstream> // Required for fstream
using namespace std;

int main() {
    // Open 'greet.txt' for reading. The file should exist and have content.
    fstream in("greet.txt", ios::in);

    // Check if the file was opened successfully
    if (!in.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Get the initial position of the read pointer. It will be 0.
    cout << "Position of read pointer before reading: " << in.tellg() << endl;

    // Read a single character from the file
    char ch;
    in.get(ch);

    // Get the new position of the read pointer. It will be 1.
    cout << "Position of read pointer after reading a single character: " << in.tellg() << endl;

    // Close the file
    in.close();

    return 0;
}


//                                                       Task number 3: using seekp() to move the write pointer

#include<iostream>
#include<fstream> // Required for fstream
using namespace std;

int main() {
    // Open the file in read, write, and truncate mode.
    // Truncate mode clears the file's previous content.
    fstream file("student.txt", ios::in | ios::out | ios::trunc);

    // Check if the file was opened successfully
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Write initial student records to the file
    file << "01,Awais,3.5 ";
    file << "02,Kashif,3.8 ";
    file << "03,Zahid,2.5 ";
    file << "04,Ahmed,4.0 ";

    // The write pointer is now at position 53, ready to write the next character.
    cout << "Position of write pointer after writing: " << file.tellp() << endl;
    
    // One record (e.g., "04,Ahmed,4.0 ") takes 13 characters.
    // We move the pointer back by 13 characters from the current position to overwrite the last line.
    file.seekp(-13, ios::cur); // Relative with reference to current position

    // Overwrite the last record with new data
    file << "05,Nadir,2.78";

    // Close the file
    file.close();

    return 0;
}

//                                            Task number 4: using seekg() to move the read pointer
#include<iostream>
#include<fstream> // Required for fstream
using namespace std;

int main() {
    // Open the file in read and write mode.
    fstream file("student.txt", ios::in | ios::out);

    // Check if the file was opened successfully
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Get the initial position of the read pointer. It should be 0.
    cout << "Position of pointer before reading: " << file.tellg() << endl;

    // Move the read pointer to position 13, which is the start of the second student record.
    cout << "Move the read pointer position to 13" << endl;
    file.seekg(13);

    char ch;
    // Read and print characters from the new position to the end of the file.
    while (file.get(ch)) {
        cout << "Character Read: " << ch << " Position of pointer after reading: " << file.tellg() << endl;
    }

    // Close the file
    file.close();

    return 0;
}