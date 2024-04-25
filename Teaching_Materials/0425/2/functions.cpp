#include "functions.h"

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
