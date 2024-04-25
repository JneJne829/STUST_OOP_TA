#include <iostream>
#include <string>

// 函數原型宣告
double calculate_average(double numbers[], int size);
double calculate_circle_area(double radius);
double celsius_to_fahrenheit(double celsius);
bool is_palindrome(int arr[], int size);
std::string reverse_string(const std::string& s);

int main() {
    // 測試 calculate_average
    double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "Average: " << calculate_average(numbers, size) << std::endl;

    // 測試 calculate_circle_area
    double radius = 5.0;
    std::cout << "Circle Area: " << calculate_circle_area(radius) << std::endl;

    // 測試 celsius_to_fahrenheit
    double celsius = 100.0;
    std::cout << "Fahrenheit: " << celsius_to_fahrenheit(celsius) << std::endl;

    // 測試 is_palindrome
    int arr[] = {1, 2, 3, 2, 1};
    size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Is palindrome: " << (is_palindrome(arr, size) ? "Yes" : "No") << std::endl;

    // 測試 reverse_string
    std::string s = "hello";
    std::cout << "Reversed string: " << reverse_string(s) << std::endl;

    return 0;
}

double calculate_average(double numbers[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return size == 0 ? 0 : sum / size;
}

double calculate_circle_area(double radius) {
    const double pi = 3.14159;
    return pi * radius * radius;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

bool is_palindrome(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

std::string reverse_string(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}
