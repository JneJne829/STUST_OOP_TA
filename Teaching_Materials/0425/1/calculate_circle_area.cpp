#include <iostream>

/**
 * 計算圓的面積。
 *
 * 描述:
 * 創建一個函數 calculate_circle_area，用來計算並返回圓的面積。
 *
 * 參數:
 * radius (double): 圓的半徑。
 *
 * 返回值:
 * double: 圓的面積，使用公式 π * radius^2 計算，其中 π 可以使用 3.14159。
 */
double calculate_circle_area(double radius) {
    const double pi = 3.14159;
    return pi * radius * radius;
}

int main() {
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "Area of the circle is: " << calculate_circle_area(radius) << std::endl;
    return 0;
}
