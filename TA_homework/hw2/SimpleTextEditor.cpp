#include <iostream>
#include <string>
#include <algorithm> // 用於std::reverse

using namespace std;

const int MAX_BUFFER_SIZE = 100; // 定義緩衝區最大容量
char buffer[MAX_BUFFER_SIZE]; // 定義一個字符型陣列作為緩衝區
int bufferCount = 0; // 用於記錄緩衝區中字符的數量

// 函數原型
void addText();
void deleteLastCharacter();
void displayBuffer();
void reverseBuffer();
void showMenu();

int main() {
    char option;
    do {
        showMenu();
        cin >> option;
        cin.ignore(); // 忽略輸入後的換行符

        switch (option) {
        case '1':
            addText();
            break;
        case '2':
            deleteLastCharacter();
            break;
        case '3':
            displayBuffer();
            break;
        case '4':
            reverseBuffer();
            break;
        case '5':
            cout << "退出程序。\n";
            break;
        default:
            cout << "無效選項。\n";
        }
    } while (option != '5');

    return 0;
}

void addText() {
    cout << "請輸入文字（'#'結束輸入）：";
    char input;
    while (cin >> noskipws >> input) { // noskipws 保留空白字符
        if (input == '#') break;
        if (bufferCount < MAX_BUFFER_SIZE) {
            buffer[bufferCount++] = input;
        } else {
            cout << "緩衝區已滿。\n";
            break;
        }
    }
    cin.ignore(); // 清除輸入緩衝
}

void deleteLastCharacter() {
    if (bufferCount > 0) {
        bufferCount--;
        cout << "最後一個字符已刪除。\n";
    } else {
        cout << "緩衝區已空。\n";
    }
}

void displayBuffer() {
    cout << "緩衝區內容：\n----------------\n";
    for (int i = 0; i < bufferCount; i++) {
        cout << buffer[i];
    }
    cout << "\n----------------" <<endl;
}

void reverseBuffer() {
    reverse(buffer, buffer + bufferCount); // 反轉緩衝區內容
    cout << "緩衝區內容已反轉。\n";
    displayBuffer(); // 顯示反轉後的內容
}

void showMenu() {
    cout << "\n簡易文本編輯器\n";
    cout << "1. 添加文字\n";
    cout << "2. 刪除最後一個字符\n";
    cout << "3. 顯示緩衝區內容\n";
    cout << "4. 反轉緩衝區內容\n";
    cout << "5. 退出程序\n";
    cout << "請選擇一個選項：";
}