#include <iostream>

/**
 * 計算數字陣列的平均值。
 *
 * 描述:
 * 創建一個函數 calculate_average，計算數字陣列的平均值並返回。
 *
 * 參數:
 * numbers (double[]): 數字陣列。
 * size (int): 數字陣列中元素的數量。
 *
 * 返回值:
 * double: 陣列中所有數字的總和除以數字的數量得到的平均值。
 */
double calculate_average(double numbers[], int size) {
    
}

int main() {
    double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "Average of the numbers is: " << calculate_average(numbers, size) << std::endl;
    return 0;
}
