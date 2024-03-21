#include <iostream>

using namespace std;

int main() {
    int month, day, totalDays = 0;
    cout << "請輸入月份：";
    cin >> month;
    cout << "請輸入日期：";
    cin >> day;

    // 使用switch語句計算到當月1日前的總天數
    for(int i = 1; i < month; i++) {
        switch(i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                totalDays += 31;
                break;
            case 4: case 6: case 9: case 11:
                totalDays += 30;
                break;
            case 2: // 閏年的二月
                totalDays += 29;
                break;
        }
    }

    totalDays += day; // 加上當月的日數

    // 計算星期幾
    int weekDay = (totalDays + 6) % 7; // 以星期一為一週的開始（2024年1月1日是星期一）
    cout << "總共有" << totalDays << "天 ";

    // 根據結果輸出星期幾
    switch (weekDay) {
        case 0: cout << "星期日"; break;
        case 1: cout << "星期一"; break;
        case 2: cout << "星期二"; break;
        case 3: cout << "星期三"; break;
        case 4: cout << "星期四"; break;
        case 5: cout << "星期五"; break;
        case 6: cout << "星期六"; break;
    }

    cout << endl;
    return 0;
}
