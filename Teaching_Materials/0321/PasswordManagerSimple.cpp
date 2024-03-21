#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;
    string password, input;
    ofstream outfile;
    ifstream infile;

    cout << "1. 設定密碼\n2. 測試密碼\n請選擇[1,2]: ";
    cin >> choice;

    if(choice == 1) {
        cout << "請輸入4個字的密碼: ";
        cin >> password;

        // 將密碼寫入檔案
        outfile.open("pass.dat");
        if(outfile.is_open()) {
            outfile << password;
            outfile.close();
        } else {
            cerr << "無法開啟檔案來寫入。\n";
        }

    } else if(choice == 2) {
        cout << "請輸入4個字的密碼: ";
        cin >> input;

        // 從檔案讀取密碼並比較
        infile.open("pass.dat");
        if(infile.is_open()) {
            infile >> password;
            infile.close();

            if(input == password) {
                cout << "Keyin password correct\n";
            } else {
                cout << "Keyin password incorrect\n";
            }
        } else {
            cerr << "無法開啟檔案來讀取。\n";
        }
    }

    return 0;
}
