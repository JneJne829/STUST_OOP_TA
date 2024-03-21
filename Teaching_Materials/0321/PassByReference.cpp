#include <iostream>
using namespace std;

void modifyReference(int &x) {
    x = 10;
}

int main() {
    int b = 5;
    modifyReference(b);
    cout << "b after modifyReference: " << b << endl; // b 的值被修改為 10
    return 0;
}
