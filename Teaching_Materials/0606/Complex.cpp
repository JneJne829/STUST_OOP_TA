#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // 建構子
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 複數的加法
    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 複數的減法
    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // 複數的乘法
    Complex operator * (const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // 複數的除法
    Complex operator / (const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw runtime_error("除以零錯誤");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // 複數的幅度
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // 複數的相角（以弧度為單位）
    double phase() const {
        return atan2(imag, real);
    }

    // 重載輸出流插入運算子
    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imag >= 0)
            os << c.real << " + " << c.imag << "i";
        else
            os << c.real << " - " << -c.imag << "i";
        return os;
    }

    // 重載輸入流提取運算子
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "輸入實部: ";
        is >> c.real;
        cout << "輸入虛部: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    try {
        // 測試案例 1: 預設複數
        Complex c1(5, 5);
        Complex c2(3, 3);
        cout << "測試案例 1:" << endl;
        cout << "c1: " << c1 << endl;
        cout << "c2: " << c2 << endl;
        cout << "c1 + c2: " << c1 + c2 << endl;
        cout << "c1 - c2: " << c1 - c2 << endl;
        cout << "c1 * c2: " << c1 * c2 << endl;
        cout << "c1 / c2: " << c1 / c2 << endl;

        // 測試案例 2: 一個複數為零
        Complex c3(0, 0);
        cout << "\n測試案例 2:" << endl;
        cout << "c3: " << c3 << endl;
        cout << "c1 + c3: " << c1 + c3 << endl;
        cout << "c1 - c3: " << c1 - c3 << endl;
        cout << "c1 * c3: " << c1 * c3 << endl;
        try {
            cout << "c1 / c3: " << c1 / c3 << endl;
        } catch (const runtime_error& e) {
            cout << "c1 / c3: " << e.what() << endl;
        }

        // 測試案例 3: 負數複數
        Complex c4(-3, -3);
        cout << "\n測試案例 3:" << endl;
        cout << "c4: " << c4 << endl;
        cout << "c1 + c4: " << c1 + c4 << endl;
        cout << "c1 - c4: " << c1 - c4 << endl;
        cout << "c1 * c4: " << c1 * c4 << endl;
        cout << "c1 / c4: " << c1 / c4 << endl;

        // 測試案例 4: 混合正數和負數的複數
        Complex c5(3, -3);
        Complex c6(-5, 2);
        cout << "\n測試案例 4:" << endl;
        cout << "c5: " << c5 << endl;
        cout << "c6: " << c6 << endl;
        cout << "c5 + c6: " << c5 + c6 << endl;
        cout << "c5 - c6: " << c5 - c6 << endl;
        cout << "c5 * c6: " << c5 * c6 << endl;
        cout << "c5 / c6: " << c5 / c6 << endl;

    } catch (const exception& e) {
        cout << "發生錯誤: " << e.what() << endl;
    }

    return 0;
}
