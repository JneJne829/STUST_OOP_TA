#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // 建構子
    Rectangle(double l = 0.0, double w = 0.0) : length(l), width(w) {}

    // 計算面積的函數
    double area() const {
        return length * width;
    }

    // 計算周長的函數
    double perimeter() const {
        return 2 * (length + width);
    }

    // 檢查矩形是否為正方形的函數
    bool isSquare() const {
        return length == width;
    }

    // 計算矩形對角線的函數
    double diagonal() const {
        return sqrt(length * length + width * width);
    }

    // 縮放矩形的函數
    void scale(double factor) {
        length *= factor;
        width *= factor;
    }

    // 重載輸出流插入運算子
    friend ostream& operator<<(ostream& os, const Rectangle& rect) {
        os << "Length: " << rect.length << ", Width: " << rect.width;
        return os;
    }

    // 重載輸入流提取運算子
    friend istream& operator>>(istream& is, Rectangle& rect) {
        cout << "輸入長度: ";
        is >> rect.length;
        cout << "輸入寬度: ";
        is >> rect.width;
        return is;
    }

    // 重載面積的比較運算子
    bool operator<(const Rectangle& other) const {
        return this->area() < other.area();
    }

    bool operator>(const Rectangle& other) const {
        return this->area() > other.area();
    }

    bool operator==(const Rectangle& other) const {
        return this->area() == other.area();
    }

    // 重載長度和寬度是否相等的比較運算子
    bool operator!=(const Rectangle& other) const {
        return this->length != other.length || this->width != other.width;
    }
};

int main() {
    Rectangle rect1, rect2;

    cout << "輸入第一個矩形:\n";
    cin >> rect1;
    cout << "輸入第二個矩形:\n";
    cin >> rect2;

    cout << "第一個矩形: " << rect1 << endl;
    cout << "第二個矩形: " << rect2 << endl;

    cout << "第一個矩形的面積: " << rect1.area() << endl;
    cout << "第一個矩形的周長: " << rect1.perimeter() << endl;
    cout << "第一個矩形的對角線: " << rect1.diagonal() << endl;
    
    cout << "第二個矩形的面積: " << rect2.area() << endl;
    cout << "第二個矩形的周長: " << rect2.perimeter() << endl;
    cout << "第二個矩形的對角線: " << rect2.diagonal() << endl;

    if (rect1 < rect2)
        cout << "第一個矩形的面積比第二個矩形小." << endl;
    else if (rect1 > rect2)
        cout << "第一個矩形的面積比第二個矩形大." << endl;
    else
        cout << "兩個矩形的面積相同." << endl;

    if (rect1.isSquare())
        cout << "第一個矩形是正方形." << endl;
    else
        cout << "第一個矩形不是正方形." << endl;

    if (rect2.isSquare())
        cout << "第二個矩形是正方形." << endl;
    else
        cout << "第二個矩形不是正方形." << endl;

    // 縮放第一個矩形
    cout << "將第一個矩形縮放2倍." << endl;
    rect1.scale(2);
    cout << "縮放後的第一個矩形: " << rect1 << endl;

    return 0;
}
