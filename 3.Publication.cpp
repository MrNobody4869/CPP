#include <iostream>
#include <string>
using namespace std;

// Base class representing a general publication
class Publication
{
protected:
    string title;   // Title of the publication
    float price;    // Price of the publication

public:
    // Constructor initializing title and price to default values
    Publication() : title(""), price(0.0) {}

    // Method to set the data for title and price from user input
    void setData()
    {
        cout << "Enter title: ";   // Ask user for the title of the publication
        getline(cin, title);      // Read the full line (including spaces)
        cout << "Enter price: ";   // Ask user for the price of the publication
        cin >> price;             // Read the price
        cin.ignore();             // Clear the input buffer to avoid issues with next getline
    }

    // Method to display the data of title and price
    void display()
    {
        cout << "Title: " << title << endl;   // Display the title
        cout << "Price: " << price << endl;   // Display the price
    }
};

// Derived class representing a Book, which is a type of Publication
class Book : public Publication
{
private:
    int pageCount;  // Number of pages in the book

public:
    // Constructor initializing pageCount to 0
    Book() : pageCount(0) {}

    // Method to set the data for the book (title, price, and page count)
    void setData()
    {
        Publication::setData();   // Call the base class method to set title and price
        cout << "Enter page count: ";   // Ask user for the page count of the book
        cin >> pageCount;          // Read the number of pages
        cin.ignore();              // Clear the input buffer
    }

    // Method to display the details of the book (title, price, and page count)
    void display()
    {
        Publication::display();  // Call the base class method to display title and price
        cout << "Page Count: " << pageCount << endl;   // Display the page count
    }
};

// Derived class representing a Tape, which is a type of Publication
class Tape : public Publication
{
private:
    float playingTime;  // Playing time of the tape in minutes

public:
    // Constructor initializing playingTime to 0.0
    Tape() : playingTime(0.0) {}

    // Method to set the data for the tape (title, price, and playing time)
    void setData()
    {
        Publication::setData();   // Call the base class method to set title and price
        cout << "Enter playing time (in minutes): ";  // Ask user for the playing time
        cin >> playingTime;           // Read the playing time
        cin.ignore();                 // Clear the input buffer
    }

    // Method to display the details of the tape (title, price, and playing time)
    void display()
    {
        Publication::display();  // Call the base class method to display title and price
        cout << "Playing Time: " << playingTime << " minutes" << endl;  // Display the playing time
    }
};

int main()
{
    Book book;  // Create an instance of the Book class
    Tape tape;  // Create an instance of the Tape class

    // Ask for and set the details of the Book
    cout << "Enter details for Book:" << endl;
    book.setData();

    // Ask for and set the details of the Tape
    cout << "\nEnter details for Tape:" << endl;
    tape.setData();

    // Display the details of the Book
    cout << "\nDetails of Book:" << endl;
    book.display();

    // Display the details of the Tape
    cout << "\nDetails of Tape:" << endl;
    tape.display();

    return 0;  // End of the program
}
