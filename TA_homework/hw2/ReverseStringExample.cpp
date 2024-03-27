#include <iostream>
#include <algorithm>
#include <cstring> // 包含對 strlen 函數的定義

int main() {
    char str[] = "hello";
    // 使用 str 作為開始指針，str + strlen(str) - 1 作為結束指針（排除 null 終止符）
    std::reverse(str, str + strlen(str));
    std::cout << str << std::endl; // 輸出: olleh
    return 0;
}
