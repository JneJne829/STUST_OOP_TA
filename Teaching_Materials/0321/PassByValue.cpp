#include <iostream>
using namespace std;

void modifyValue(int x) {
    x = 10;
}

int main() {
    int a = 5;
    modifyValue(a);
    cout << "a after modifyValue: " << a << endl; // a 的值不會改變，輸出 5
    return 0;
}
