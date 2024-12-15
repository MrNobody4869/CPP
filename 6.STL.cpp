#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Structure to store personal record details
struct PersonalRecord
{
    string name;    // Name of the person
    string dob;     // Date of birth (DD/MM/YYYY)
    string phone;   // Phone number

    // Overloading < operator to compare PersonalRecord by name (for sorting)
    bool operator<(const PersonalRecord& other) const
    {
        return name < other.name;  // Compare by name
    }

    // Overloading == operator to check if two PersonalRecord objects are equal (by name)
    bool operator==(const PersonalRecord& other) const
    {
        return name == other.name;  // Check if names are equal
    }
};

// Vector to store the records
vector<PersonalRecord> records;

// Function to insert a new record into the vector
void insertRecord()
{
    PersonalRecord record;
    cout << "Enter Name: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, record.name);  // Get name input
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, record.dob);  // Get date of birth input
    cout << "Enter Telephone Number: ";
    getline(cin, record.phone);  // Get phone number input
    records.push_back(record);  // Add the record to the vector
}

// Function to display all records
void displayRecords()
{
    if (records.empty())  // Check if there are no records
    {
        cout << "\nNo records available.\n";
        return;
    }
    cout << "\n--- Personnel Records ---\n";
    // Loop through the records vector and display each record
    for (const auto& record : records)
    {
        cout << "Name: " << record.name << "\n";
        cout << "Date of Birth: " << record.dob << "\n";
        cout << "Telephone Number: " << record.phone << "\n";
        cout << "----------------------------\n";
    }
}

// Function to search a record by name
void searchRecord()
{
    string name;
    cout << "\nEnter Name to Search: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, name);  // Get the name to search

    // Find the record by name using find_if and lambda function
    auto it = find_if(records.begin(), records.end(), [&name](const PersonalRecord& record)
    {
        return record.name == name;  // Compare the name
    });

    // Check if the record was found and display the result
    if (it != records.end())
    {
        cout << "\nRecord Found!\n";
        cout << "Name: " << it->name << "\n";
        cout << "Date of Birth: " << it->dob << "\n";
        cout << "Telephone Number: " << it->phone << "\n";
    }
    else
    {
        cout << "\nRecord not found!\n";
    }
}

// Function to sort records by name
void sortRecords()
{
    sort(records.begin(), records.end());  // Sort the vector using overloaded < operator
    cout << "\nRecords have been sorted by name.\n";
}

// Function to delete a record by name
void deleteRecord()
{
    string name;
    cout << "\nEnter Name to Delete: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, name);  // Get the name of the record to delete

    // Find and remove the record using remove_if and lambda function
    auto it = remove_if(records.begin(), records.end(), [&name](const PersonalRecord& record)
    {
        return record.name == name;  // Compare the name to find the record to delete
    });

    // If the record was found, erase it from the vector
    if (it != records.end())
    {
        records.erase(it, records.end());  // Remove the element from the vector
        cout << "\nRecord deleted successfully.\n";
    }
    else
    {
        cout << "\nRecord not found!\n";
    }
}

int main()
{
    int choice;  // To store the user's menu choice
    do
    {
        // Display menu for user interaction
        cout << "\n***** Menu *****";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;  // Get the user's choice

        switch (choice)
        {
        case 1:
            insertRecord();  // Call function to insert a new record
            break;
        case 2:
            displayRecords();  // Call function to display all records
            break;
        case 3:
            searchRecord();  // Call function to search a record by name
            break;
        case 4:
            sortRecords();  // Call function to sort records by name
            break;
        case 5:
            deleteRecord();  // Call function to delete a record by name
            break;
        case 6:
            cout << "Exiting...\n";  // Exit the program
            break;
        default:
            cout << "Invalid choice! Please try again.\n";  // Invalid choice handler
        }
    }
    while (choice != 6);  // Continue the menu loop until the user chooses to exit

    return 0;  // Exit the program successfully
}
