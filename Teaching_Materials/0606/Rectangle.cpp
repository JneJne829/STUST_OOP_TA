#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l = 0.0, double w = 0.0) : length(l), width(w) {}

    // Function to calculate area
    double area() const {
        return length * width;
    }

    // Function to calculate perimeter
    double perimeter() const {
        return 2 * (length + width);
    }

    // Function to check if the rectangle is a square
    bool isSquare() const {
        return length == width;
    }

    // Function to calculate the diagonal of the rectangle
    double diagonal() const {
        return sqrt(length * length + width * width);
    }

    // Function to scale the rectangle
    void scale(double factor) {
        length *= factor;
        width *= factor;
    }

    // Overload the stream insertion operator
    friend ostream& operator<<(ostream& os, const Rectangle& rect) {
        os << "Length: " << rect.length << ", Width: " << rect.width;
        return os;
    }

    // Overload the stream extraction operator
    friend istream& operator>>(istream& is, Rectangle& rect) {
        cout << "Enter length: ";
        is >> rect.length;
        cout << "Enter width: ";
        is >> rect.width;
        return is;
    }

    // Overload the comparison operator for area
    bool operator<(const Rectangle& other) const {
        return this->area() < other.area();
    }

    bool operator>(const Rectangle& other) const {
        return this->area() > other.area();
    }

    bool operator==(const Rectangle& other) const {
        return this->area() == other.area();
    }

    // Overload the comparison operator for length and width equality
    bool operator!=(const Rectangle& other) const {
        return this->length != other.length || this->width != other.width;
    }
};

int main() {
    Rectangle rect1, rect2;

    cout << "Enter first rectangle:\n";
    cin >> rect1;
    cout << "Enter second rectangle:\n";
    cin >> rect2;

    cout << "First Rectangle: " << rect1 << endl;
    cout << "Second Rectangle: " << rect2 << endl;

    cout << "Area of first rectangle: " << rect1.area() << endl;
    cout << "Perimeter of first rectangle: " << rect1.perimeter() << endl;
    cout << "Diagonal of first rectangle: " << rect1.diagonal() << endl;
    
    cout << "Area of second rectangle: " << rect2.area() << endl;
    cout << "Perimeter of second rectangle: " << rect2.perimeter() << endl;
    cout << "Diagonal of second rectangle: " << rect2.diagonal() << endl;

    if (rect1 < rect2)
        cout << "First rectangle is smaller than the second rectangle in area." << endl;
    else if (rect1 > rect2)
        cout << "First rectangle is larger than the second rectangle in area." << endl;
    else
        cout << "Both rectangles have the same area." << endl;

    if (rect1.isSquare())
        cout << "First rectangle is a square." << endl;
    else
        cout << "First rectangle is not a square." << endl;

    if (rect2.isSquare())
        cout << "Second rectangle is a square." << endl;
    else
        cout << "Second rectangle is not a square." << endl;

    // Scaling the first rectangle
    cout << "Scaling the first rectangle by a factor of 2." << endl;
    rect1.scale(2);
    cout << "First Rectangle after scaling: " << rect1 << endl;

    return 0;
}
