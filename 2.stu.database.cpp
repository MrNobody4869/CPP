#include <iostream>
#include <string>
using namespace std;

class Student;  // Forward declaration of class Student

class FRIEND {
public:
    void printStudent(const Student& s);  // Function to print a Student's details
};

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string address;
    string telephoneNumber;
    string drivingLicenseNo;
    static int StudentCount;  // Static variable to keep track of total number of students

public:
    // Default constructor
    Student() {
        name = "";
        rollNumber = 0;
        className = "";
        division = ' ';
        dob = "";
        bloodGroup = "";
        address = "";
        telephoneNumber = "";
        drivingLicenseNo = "";
        StudentCount++;  // Increment student count when a new student is created
    }

    // Parameterized constructor to initialize a student with given values
    Student(string n, int roll, string c, char div, string dob, string bg, string addr, string tel, string dl) {
        this->name = n;
        this->rollNumber = roll;
        this->className = c;
        this->division = div;
        this->dob = dob;
        this->bloodGroup = bg;
        this->address = addr;
        this->telephoneNumber = tel;
        this->drivingLicenseNo = dl;
        StudentCount++;  // Increment student count when a new student is created
    }

    // Copy constructor
    Student(const Student & s) {
        this->name = s.name;
        this->rollNumber = s.rollNumber;
        this->className = s.className;
        this->division = s.division;
        this->dob = s.dob;
        this->bloodGroup = s.bloodGroup;
        this->address = s.address;
        this->telephoneNumber = s.telephoneNumber;
        this->drivingLicenseNo = s.drivingLicenseNo;
        StudentCount++;  // Increment student count when a student is copied
    }

    // Destructor
    ~Student() {
        StudentCount--;  // Decrement student count when a student object is destroyed
    }

    // Static function to get the current student count
    static int getStudentCount() {
        return StudentCount;
    }

    //Input
    void setValues() {
        cout << "Enter Name: ";
        cin.ignore();  
        getline(cin, name);  
        cout << "Enter Roll Number: ";
        cin >> rollNumber; 
        cin.ignore(); 
        cout << "Enter Class: ";
        getline(cin, className);  
        cout << "Enter Division: ";
        cin >> division;  
        cin.ignore(); 
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin, dob); 
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);  
        cout << "Enter Address: ";
        getline(cin, address);  
        cout << "Enter Telephone Number: ";
        getline(cin, telephoneNumber);  
        cout << "Enter Driving License No: ";
        getline(cin, drivingLicenseNo);  
    }

    // Function to display student details
    inline void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }

    // Declaring FRIEND class as a friend so it can access private members of Student
    friend class FRIEND;
};

// Initialize static variable StudentCount to 0
int Student::StudentCount = 0;

// Friend class function to print the details of a student
void FRIEND::printStudent(const Student& s) {
    cout << "\nFriend Class Accessing Student Details: " << endl;
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNumber << endl;
}

int main() {
    int no;
    cout << "Enter the number of Students: ";
    cin >> no;

    // Dynamically allocate an array of students
    Student* Students = new Student[no];

    // Loop to input details for each student
    for (int i = 0; i < no; i++) {
        cout << "Entering details for Student " << (i + 1) << ":\n";
        Students[i].setValues();  // Input student details
    }

    // Display details of all students
    cout << "\nStudent Details:\n";
    for (int i = 0; i < no; i++) {
        cout << "\nStudent " << (i + 1) << " Details:\n";
        Students[i].display();  // Display student details
    }

    // Display the total number of students
    cout << "\nTotal Number of Students: " << Student::getStudentCount() << endl;

    // Create an instance of FRIEND class and access private members of Student class
    FRIEND h;
    h.printStudent(Students[0]);  // Print details of the first student using FRIEND class

    // Deallocate memory for the dynamically allocated array of students
    delete[] Students;

    return 0;
}









// Explanation:
// 1. **Student Class:**
//    - The `Student` class represents a student and contains various attributes like `name`, `rollNumber`, `className`, etc.
//    - It has constructors, a copy constructor, a destructor, and member functions to set and display the student details.
//    - The `StudentCount` is a static variable used to keep track of the number of `Student` objects created.
//    - A static function `getStudentCount()` is provided to access the `StudentCount` value.

// 2. **Constructors:**
//    - The **default constructor** initializes all the attributes to default values and increments the `StudentCount`.
//    - The **parameterized constructor** initializes the student attributes with provided values and also increments the `StudentCount`.
//    - The **copy constructor** is used to create a new student as a copy of an existing one and also increments the `StudentCount`.
//    - The **destructor** decreases the `StudentCount` when a `Student` object is destroyed.

// 3. **Member Functions:**
//    - `setValues()`: This function takes user input for all student details and stores them in the corresponding attributes.
//    - `display()`: This function outputs the details of the student on the console.
//    - `getStudentCount()`: A static function to return the total number of `Student` objects created.

// 4. **FRIEND Class:**
//    - The `FRIEND` class is a friend of the `Student` class, allowing it to access private members of `Student` objects.
//    - The function `printStudent()` in `FRIEND` class is used to print details of a student, even though those details are private.

// 5. **Main Function:**
//    - The user is prompted to enter the number of students they wish to input.
//    - A dynamic array of `Student` objects is created, and user inputs are used to populate each student using `setValues()`.
//    - After all students' data is entered, the `display()` function is used to print each student's details.
//    - The total number of students is displayed using the `getStudentCount()` function.
//    - The `printStudent()` function of the `FRIEND` class is used to print the details of the first student as a demonstration of friend class access.
//    - Finally, memory allocated for the array is deallocated using `delete[]`.

