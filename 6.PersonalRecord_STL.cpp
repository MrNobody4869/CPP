#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Structure to store personal record details
struct PersonalRecord
{
    string name;
    string dob;
    string phone;

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
    cin.ignore();  // Clear the input buffer to avoid issues with getline
    getline(cin, record.name);  
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, record.dob);  
    cout << "Enter Telephone Number: ";
    getline(cin, record.phone);  
    records.push_back(record);  
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

    // Find the record and remove it using remove_if and lambda function
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
            insertRecord();  
            break;
        case 2:
            displayRecords();  
            break;
        case 3:
            searchRecord();  
            break;
        case 4:
            sortRecords();  
            break;
        case 5:
            deleteRecord();  
            break;
        case 6:
            cout << "Exiting...\n";  
            break;
        default:
            cout << "Invalid choice! Please try again.\n";  
        }
    }
    while (choice != 6);  

    return 0;  
}



/*
### STL (Standard Template Library): STL (Standard Template Library) is a collection of template classes 
and functions in C++ that provides common data structures and algorithms

1. **STL Components**:
   - **Algorithms**: Functions designed for operations on container elements (e.g., sorting, searching).
   - **Containers**: Data structures for storing objects and data.
   - **Functions**: Functors that allow customizing function behavior.
   - **Iterators**: Objects that provide access to container elements.

2. **STL Algorithm Types**:
   - **Sorting**: Organizes data in ascending or descending order.
   - **Searching**: Searches for elements in sorted containers.
   - **Numeric Operations**: Performs numeric tasks like summing or finding the minimum.
   - **Partition Operations**: Divides data into groups based on a condition.

3. **Containers**:
   - **Sequence Containers**: Accessed sequentially (e.g., `vector`, `list`, `deque`, `array`).
   - **Container Adaptors**: Specialized interfaces (e.g., `queue`, `stack`, `priority_queue`).
   - **Associative Containers**: Sorted data structures for quick search (`set`, `map`).
   - **Unordered Associative Containers**: Unordered data structures for fast search (`unordered_set`, `unordered_map`).

4. **Functors (Function Objects)**:
   - Classes that overload the function call operator, allowing functions to be customized with parameters.

5. **Iterators**:
   - Used to traverse and operate on containers, providing flexibility and generality to STL algorithms.

6. **Utility Library**:
   - Provides utilities like `pair` for storing two related values.

7. **Sorting with `sort()`**:
   - Sorts elements in ascending or descending order using a hybrid of QuickSort, HeapSort, and InsertionSort.
   - `sort(startAddress, endAddress)` sorts elements between the given addresses.

8. **Searching**:
   - Efficient searching algorithms (e.g., binary search) that work on sorted data by dividing the data in half.

STL simplifies C++ programming by providing ready-to-use, efficient data structures and algorithms.

*/
