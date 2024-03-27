#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 函數原型宣告
bool isInteger(const string& str);
bool isFloat(const string& str);
bool isChar(const string& str);
void processInput(const string& input, int& intCount, int& floatCount, int& charCount);

int main() {
    string input;
    cout << "請輸入一串字符：" << endl;
    getline(cin, input);
    int intCount = 0, floatCount = 0, charCount = 0;
    processInput(input, intCount, floatCount, charCount);

    cout << "整數出現的次數：" << intCount << endl;
    cout << "浮點數出現的次數：" << floatCount << endl;
    cout << "字符出現的次數：" << charCount << endl;
    return 0;
}

bool isInteger(const string& str) {
    for (char const &c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool isFloat(const string& str) {
    bool pointSeen = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (pointSeen || i == 0 || i == str.length() - 1) return false;
            pointSeen = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return pointSeen;
}

bool isChar(const string& str) {
    return str.length() == 1 && !isdigit(str[0]);
}

void processInput(const string& input, int& intCount, int& floatCount, int& charCount) {
    string temp = "";
    for (int i = 0; i <= input.length(); i++) {
        if (i < input.length() && input[i] != ' ') {
            temp += input[i];
        } else {
            if (!temp.empty()) {
                if (isInteger(temp)) {
                    intCount++;
                } else if (isFloat(temp)) {
                    floatCount++;
                } else if (isChar(temp)) {
                    charCount++;
                }
                temp.clear();
            }
        }
    }
}
