#include<iostream>
using namespace std;

// Class representing a complex number
class complex {
    float real, imag;  // Declare two private data members for the real and imaginary parts of the complex number
public:
    // Constructor to initialize the complex number (default values are 0,0)
    complex(float r=0, float i=0) {
        real = r;
        imag = i;
    }

    // Overloaded '+' operator for adding two complex numbers
    complex operator+(complex &c1) {
        complex c3;  // Create a temporary complex number object to hold the result
        c3.real = real + c1.real;  // Add the real parts
        c3.imag = imag + c1.imag;  // Add the imaginary parts
        return c3;  // Return the result as a new complex number
    }

    // Overloaded '*' operator for multiplying two complex numbers
    complex operator*(complex &c1) {
        complex c3;  // Create a temporary complex number object to hold the result
        c3.real = real * c1.real - imag * c1.imag;  // Use the formula for multiplying complex numbers
        c3.imag = real * c1.imag + imag * c1.real;  // Continue with the formula for the imaginary part
        return c3;  // Return the result as a new complex number
    }

    // Friend function to overload the input operator (>>)
    friend istream & operator>>(istream &in, complex &c2) {
        // Prompt the user to enter the real and imaginary parts
        cout << "Enter the real part: ";
        in >> c2.real;
        cout << "Enter the imaginary part: ";
        in >> c2.imag;
        return in;  // Return the input stream to allow chaining
    }

    // Friend function to overload the output operator (<<)
    friend ostream & operator<<(ostream &out, complex &c2) {
        // Print the complex number in the form of "real+imaginary i"
        out << c2.real << "+" << c2.imag << "i";
        return out;  // Return the output stream to allow chaining
    }
};

int main() {
    complex c1, c2, c3;  // Declare three complex numbers (c1, c2, c3)

    // Ask for user input to initialize the first complex number
    cout << "Enter the first complex number:" << endl;
    cin >> c1;

    // Ask for user input to initialize the second complex number
    cout << "Enter the second complex number:" << endl;
    cin >> c2;

    // Perform the addition of the two complex numbers
    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;  // Display the sum of the two complex numbers

    // Perform the multiplication of the two complex numbers
    c3 = c1 * c2;
    cout << "Product: " << c3 << endl;  // Display the product of the two complex numbers

    return 0;  // End the program
}

// Explanation of the code:
// 1. **Class `complex`**: Represents a complex number with two private members: `real` and `imag`.
// 2. **Constructor**: Initializes a complex number with default values (0, 0) or with user-provided values.
// 3. **Operator Overloading**:
//    - `operator+`: Adds two complex numbers by adding their real and imaginary parts separately.
//    - `operator*`: Multiplies two complex numbers using the formula for complex number multiplication.
// 4. **Friend Functions**:
//    - `operator>>`: Overloads the input operator to read a complex number from the user (real and imaginary parts).
//    - `operator<<`: Overloads the output operator to display the complex number in the format "real+imaginary i".
// 5. **Main Function**: 
//    - Creates three complex numbers: `c1`, `c2`, and `c3`.
//    - Takes user input for the first two complex numbers (`c1` and `c2`).
//    - Computes the sum and product of `c1` and `c2` and displays the results (`c3`).
