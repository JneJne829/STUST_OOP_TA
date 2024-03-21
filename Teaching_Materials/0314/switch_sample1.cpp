#include <iostream>
using namespace std;

int main() {
    int month, day, count = 0;
    cout << "請輸入月份 : ";
    cin >> month;
    cout << "請輸入日期 : ";
    cin >> day;

    for (int i = 1; i < month; i++) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                count += 31;
                break;
            case 4: case 6: case 9: case 11:
                count += 30;
                break;
            case 2:
                count += 29;
                break;
        }
    }

    count += day;

    cout << "總天數" << count << "天" << endl;

    return 0;
}