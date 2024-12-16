#include <iostream>
using namespace std;

// Template function to sort and display the array using selection sort algorithm
template<class T>
void search_sort(T A[], int n) {
    T temp;  // Temporary variable for swapping elements

    // Outer loop to traverse the array and find the smallest element
    for (int i = 0; i < n - 1; i++) {
        int min = i;  // Assume the current index as the minimum

        // Inner loop to find the minimum element in the unsorted portion of the array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;  // Update minimum index if a smaller element is found
            }
        }

        // Swap the found minimum element with the element at the current index
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";  // Print each element of the sorted array
    }
    cout << endl;
}

int main() {
    int n;  // Size of the array
    int choice;  // Variable to store the user's choice for the array type

    // Infinite loop to continuously show the menu and allow the user to choose options
    while (true) {
        // Display menu options for selecting the array type
        cout << "Select the array type:" << endl;
        cout << "1. Integer" << endl;
        cout << "2. Float" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;  // Take user input for the array type
        cout << "Selected Option no: " << choice << endl;

        // Exit the program if the user selects option 3
        if (choice == 3)
            break;

        // Ask the user to input the size of the array
        cout << "Enter the size of the array:" << endl;
        cin >> n;  // Take user input for the array size

        // Handle the case for an integer array
        if (choice == 1) {
            int* A = new int[n];  // Dynamically allocate memory for an integer array

            // Prompt user to input the elements of the array
            cout << "Enter the array elements:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> A[i];  // Take input for each element
            }

            // Display the entered array
            cout << "Entered array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << A[i] << " ";  // Print each element of the entered array
            }
            cout << endl;

            // Call the search_sort function to sort and display the sorted array
            search_sort(A, n);

            // Free the dynamically allocated memory
            delete[] A;

        }
        // Handle the case for a float array
        else if (choice == 2) {
            float* B = new float[n];  // Dynamically allocate memory for a float array

            // Prompt user to input the elements of the array
            cout << "Enter the array elements:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> B[i];  // Take input for each element
            }

            // Display the entered array
            cout << "Entered array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << B[i] << " ";  // Print each element of the entered array
            }
            cout << endl;

            // Call the search_sort function to sort and display the sorted array
            search_sort(B, n);

            // Free the dynamically allocated memory
            delete[] B;
        }
        // If the user selects an invalid choice, show an error message
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;  
}





/*
Templates are the foundation of generic programming, which involves
writing code in a way thatis independent of any particular type.
A template is a blueprint or formula for creating a generic class or a function. Thelibrary containers like iterators
and algorithms are examples of generic programming
and have been developed using template concept. There is a single definition of each
container, such as vector, but we can define many different kinds of vectorsforexample, vector <int> or vector <string>.
You can use templates to define functions as well as classes, let us see howdotheywork:Function Template:
The general form of a template function definition is shown here:
template <class type> ret-type func-name(parameter list)
{
// body of function
}
Here, type is a placeholder name for a data type used by the function. This
name can be used within the function definition.

Class Template:
Just as we can define functionb templates, we can also define class templates. Thegeneral
form of a generic classdeclaration is shown here:
template <class type> class class-name
Selection Sort:
Selection sort is a sorting algorithm, specifically an in-place comparison sort. It has O(n2)timecomplexity, makingit inefficient on large lists, and
generally performs worse than the similar insertion sort. 
Selection sort is noted for its simplicity, and it has performance advantages over more complicated algorithms in certain situations,
particularly where auxiliarymemory is limited

*/
