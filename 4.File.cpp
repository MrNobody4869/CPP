#include <iostream>
#include <fstream>  // Required for file input/output operations
#include <string>   // Required for string manipulation

using namespace std;

int main() {
    // Create and open an output file for writing
    ofstream outFile("example.txt");  // Open file for output

    // Check if the file was successfully opened
    if (!outFile) {
        cerr << "Error opening the file for writing." << endl;
        return 1;  // Return error code 1 if file can't be opened
    }

    // Write some information to the output file
    outFile << "Hello, this is a test message." << endl;
    outFile << "This is the second line." << endl;
    outFile << "This file demonstrates file I/O in C++." << endl;

    // Close the output file after writing
    outFile.close();

    // Create and open the input file for reading
    ifstream inFile("example.txt");  // Open file for input

    // Check if the file was successfully opened
    if (!inFile) {
        cerr << "Error opening the file for reading." << endl;
        return 1;  // Return error code 1 if file can't be opened
    }

    string line;
    
    // Read the contents of the file line by line
    cout << "Contents of the file:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;  // Print each line of the file to the console
    }

    // Close the input file after reading
    inFile.close();

    return 0;  // End of the program
}
