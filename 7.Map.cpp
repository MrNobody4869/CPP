#include <iostream>  // Include header for input/output streams
#include <map>       // Include header for the map container
#include <string>    // Include header for string data type
using namespace std;

int main()
{
    // Declare a map to store state names as keys and their population as values
    map<string, int> states;

    // Insert state names and their populations into the map
    states.insert(pair<string, int>("Maharashtra", 7026357));   // Maharashtra population
    states.insert(pair<string, int>("Rajasthan", 6578936));     // Rajasthan population
    states.insert(pair<string, int>("Punjab", 5789032));        // Punjab population
    states.insert(pair<string, int>("West Bengal", 6676291));   // West Bengal population

    // Prompt the user to enter the name of the state whose population is to be found
    string userInput;
    cout << "Enter the state whose population is to be found: ";
    cin >> userInput;  // Read user input (state name)

    cout << endl;

    // Flag variable to track if the state is found in the map
    bool isPresent = false;

    // Iterate over the map to find the state entered by the user
    for (auto i : states)  // Iterate through each key-value pair in the map
    {
        if (i.first == userInput)  // Check if the current key matches the user input
        {
            isPresent = true;  // Set the flag to true if the state is found
            cout << "The population of state " << userInput << " is " << i.second;  // Print the population
            break;  // Exit the loop as we've found the state
        }
    }

    // If the state is not found, print a message indicating it's not in the database
    if (!isPresent)
    {
        cout << "The state not found in database.";
    }

    return 0;  // Exit the program successfully
}
