#include <iostream>
#include "functions.h"

// g++ -o program main.cpp functions.cpp
int main() {
    double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "Average: " << calculate_average(numbers, size) << std::endl;

    double radius = 5.0;
    std::cout << "Circle Area: " << calculate_circle_area(radius) << std::endl;

    double celsius = 100.0;
    std::cout << "Fahrenheit: " << celsius_to_fahrenheit(celsius) << std::endl;

    int arr[] = {1, 2, 3, 2, 1};
    size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Is palindrome: " << (is_palindrome(arr, size) ? "Yes" : "No") << std::endl;

    std::string s = "hello";
    std::cout << "Reversed string: " << reverse_string(s) << std::endl;

    return 0;
}
