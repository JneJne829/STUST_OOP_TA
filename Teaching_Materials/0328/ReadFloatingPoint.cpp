#include <iostream>

using namespace std;

int main() {
    int integerPart;
    float decimalPart;

    cout << "請輸入一個浮點數：";
    cin >> integerPart;

    cin >> decimalPart;

    cout << "整數部分是：" << integerPart << endl;
    cout << "小數部分是：" << decimalPart << endl;

    return 0;
}
