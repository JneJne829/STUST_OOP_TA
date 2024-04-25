#include <iostream>

/**
 * 檢查一個數字陣列是否為回文。
 *
 * 描述:
 * 創建一個函數 is_palindrome，檢查一個數字陣列是否為回文。
 *
 * 參數:
 * arr (int[]): 數字陣列。
 * size (int): 數字陣列中元素的數量。
 *
 * 返回值:
 * bool: 布爾值，表示陣列是否為回文。
 */
bool is_palindrome(int arr[], int size) {
    
}

int main() {
    int numbers[] = {1, 2, 3, 2, 1};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "The array is " << (is_palindrome(numbers, size) ? "" : "not ") << "a palindrome." << std::endl;
    return 0;
}
