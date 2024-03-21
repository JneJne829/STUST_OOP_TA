#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string diaryEntry;
    string diaryFilename;
    // 使用ctime獲取當前日期和時間
    time_t now = time(0);
    char* dt = ctime(&now);

    // 構建文件名，例如：2024-03.txt
    diaryFilename = "Memorandum_" + to_string(1900 + localtime(&now)->tm_year) + "-" + to_string(1 + localtime(&now)->tm_mon) + ".txt";

    ofstream diaryFile(diaryFilename, ios::app); // 打開檔案進行追加
    if (!diaryFile) {
        cerr << "Unable to open file";
        return 1; // 結束程序
    }
    




    cout << "Enter your memo (type 'exit' to finish):" << endl;

    while (getline(cin, diaryEntry)) {
        if (diaryEntry == "exit") break;
        diaryFile << dt << diaryEntry << endl; // 寫入日記和時間戳
    }

    diaryFile.close(); // 關閉檔案
    return 0;
}
