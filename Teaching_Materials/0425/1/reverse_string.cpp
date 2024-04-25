#include <iostream>
#include <string>

/**
 * 接收一個字符串並返回它的反轉字符串。
 *
 * 描述:
 * 創建一個函數 reverse_string，接收一個字符串並返回其反轉的字符串。
 *
 * 參數:
 * s (string): 要反轉的字符串。
 *
 * 返回值:
 * string: 反轉後的字符串。
 */
std::string reverse_string(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

int main() {
    std::string input;
    std::cout << "Enter a string to reverse: ";
    std::getline(std::cin, input);
    std::cout << "Reversed string: " << reverse_string(input) << std::endl;
    return 0;
}
