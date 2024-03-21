#include <iostream>
using namespace std;

int main() {
    int T; // 測資數量
    cin >> T;
    int results[T]; // 儲存每個測資的結果

    for(int testCase = 0; testCase < T; testCase++) {
        int x, r, n; // 本金金額，年利率，年數
        char comma; // 用於跳過輸入中的逗號
        
        cin >> x >> comma >> r >> comma >> n;
        
        double rate = r / 100.0; // 將百分比轉換為小數
        double futureValue = x; // 從本金開始
        for(int year = 1; year <= n; year++) {
            futureValue *= (1 + rate); // 每年乘以(1 + rate)來累加利息
        }
        
        // 將結果儲存至陣列，自動捨去小數部分
        results[testCase] = futureValue;
    }

    // 離開 for 迴圈後輸出結果
    for(int i = 0; i < T; i++) {
        cout << results[i] << endl;
    }

    return 0;
}
