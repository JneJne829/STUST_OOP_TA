#include <iostream>

using namespace std;

const int MAX_BUFFER_SIZE = 10; // 定義緩衝區最大容量

int main() {
    char buffer[MAX_BUFFER_SIZE]; // 定義一個字符型陣列作為緩衝區
    int count = 0; // 用於記錄緩衝區中字符的數量
    char input; // 存儲用戶輸入的單個字符

    cout << "請輸入字符，'#'結束輸入：" << endl;

    // 循環接收字符直到緩衝區滿或遇到'#'
    while (count < MAX_BUFFER_SIZE) {
        cin >> input;
        if (input == '#') { // 如果用戶輸入'#'，結束輸入
            break;
        }
        buffer[count++] = input; // 將字符存儲到緩衝區中並增加計數
    }

    // 檢查緩衝區是否已滿
    if (count == MAX_BUFFER_SIZE) {
        cout << "緩衝區已滿。" << endl;
    }

    // 輸出緩衝區內容
    cout << "緩衝區內容：" << endl;
    for (int i = 0; i < count; i++) {
        cout << buffer[i];
    }
    cout << endl;

    return 0;
}