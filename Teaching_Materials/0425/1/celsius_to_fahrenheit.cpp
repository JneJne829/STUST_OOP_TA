#include <iostream>

/**
 * 將攝氏溫度轉換為華氏溫度。
 *
 * 描述:
 * 創建一個函數 celsius_to_fahrenheit，將攝氏溫度轉換為華氏溫度並返回。
 *
 * 參數:
 * celsius (double): 攝氏溫度。
 *
 * 返回值:
 * double: 華氏溫度，計算公式為 (攝氏度 * 9/5) + 32。
 */
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;
    std::cout << "Temperature in Fahrenheit: " << celsius_to_fahrenheit(celsius) << std::endl;
    return 0;
}
