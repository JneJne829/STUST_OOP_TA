#include <iostream>
using namespace std;

void modifyPointer(int *x) {
    *x = 10;
}

int main() {
    int c = 5;
    modifyPointer(&c);
    cout << "c after modifyPointer: " << c << endl; // c 的值被修改為 10
    return 0;
}
