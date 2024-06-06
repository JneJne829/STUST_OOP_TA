#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Addition of two complex numbers
    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction of two complex numbers
    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication of two complex numbers
    Complex operator * (const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Division of two complex numbers
    Complex operator / (const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw runtime_error("Division by zero error");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Magnitude of the complex number
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Phase angle (in radians) of the complex number
    double phase() const {
        return atan2(imag, real);
    }

    // Overload the stream insertion operator
    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imag >= 0)
            os << c.real << " + " << c.imag << "i";
        else
            os << c.real << " - " << -c.imag << "i";
        return os;
    }

    // Overload the stream extraction operator
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    try {
        // Test case 1: Default complex numbers
        Complex c1(5, 5);
        Complex c2(3, 3);
        cout << "Test case 1:" << endl;
        cout << "c1: " << c1 << endl;
        cout << "c2: " << c2 << endl;
        cout << "c1 + c2: " << c1 + c2 << endl;
        cout << "c1 - c2: " << c1 - c2 << endl;
        cout << "c1 * c2: " << c1 * c2 << endl;
        cout << "c1 / c2: " << c1 / c2 << endl;

        // Test case 2: One complex number with zero
        Complex c3(0, 0);
        cout << "\nTest case 2:" << endl;
        cout << "c3: " << c3 << endl;
        cout << "c1 + c3: " << c1 + c3 << endl;
        cout << "c1 - c3: " << c1 - c3 << endl;
        cout << "c1 * c3: " << c1 * c3 << endl;
        try {
            cout << "c1 / c3: " << c1 / c3 << endl;
        } catch (const runtime_error& e) {
            cout << "c1 / c3: " << e.what() << endl;
        }

        // Test case 3: Negative complex numbers
        Complex c4(-3, -3);
        cout << "\nTest case 3:" << endl;
        cout << "c4: " << c4 << endl;
        cout << "c1 + c4: " << c1 + c4 << endl;
        cout << "c1 - c4: " << c1 - c4 << endl;
        cout << "c1 * c4: " << c1 * c4 << endl;
        cout << "c1 / c4: " << c1 / c4 << endl;

        // Test case 4: Mixed positive and negative complex numbers
        Complex c5(3, -3);
        Complex c6(-5, 2);
        cout << "\nTest case 4:" << endl;
        cout << "c5: " << c5 << endl;
        cout << "c6: " << c6 << endl;
        cout << "c5 + c6: " << c5 + c6 << endl;
        cout << "c5 - c6: " << c5 - c6 << endl;
        cout << "c5 * c6: " << c5 * c6 << endl;
        cout << "c5 / c6: " << c5 / c6 << endl;

    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}
