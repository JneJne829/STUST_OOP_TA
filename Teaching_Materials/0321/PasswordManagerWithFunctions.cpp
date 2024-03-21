#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void setPassword() {
    string password;
    cout << "請輸入4個字的密碼: ";
    cin >> password;

    ofstream outfile("pass.dat");
    if(outfile.is_open()) {
        outfile << password;
        outfile.close();
        cout << "密碼已設定。\n";
    } else {
        cerr << "無法開啟檔案來寫入。\n";
    }
}

void checkPassword() {
    string storedPassword, inputPassword;
    ifstream infile("pass.dat");
    if(infile.is_open()) {
        infile >> storedPassword;
        infile.close();

        cout << "請輸入4個字的密碼: ";
        cin >> inputPassword;
        if(inputPassword == storedPassword) {
            cout << "Keyin password correct\n";
        } else {
            cout << "Keyin password incorrect\n";
        }
    } else {
        cerr << "無法開啟檔案來讀取。\n";
    }
}

int main() {
    int choice;

    cout << "1. 設定密碼\n2. 測試密碼\n請選擇[1,2]: ";
    cin >> choice;

    switch(choice) {
        case 1:
            setPassword();
            break;
        case 2:
            checkPassword();
            break;
        default:
            cout << "無效的選擇。\n";
    }

    return 0;
}