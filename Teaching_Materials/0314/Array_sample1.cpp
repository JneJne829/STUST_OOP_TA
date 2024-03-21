#include <iostream>
using namespace std;

int main() {
    // 宣告一個整數陣列
    int numbers[5];

    // 初始化陣列元素
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    // 存取並列印陣列元素
    for(int i = 0; i < 5; i++) {
        cout << "位於索引 " << i << " 的元素: " << numbers[i] << endl;
    }

    return 0;
}
