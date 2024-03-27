#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>

using namespace std;

int main() {
    ifstream myFile("111.txt");
    ofstream myFile2("222.txt");

    string line;
    int i; // 追踪迴圈的索引

    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            bool isNumeric = true; // 判斷整行是否為數字
            int num[10], index = 0;;
            for (i = 0; i < line.length(); i++) {
                if (!isdigit(line[i]) && line[i] != ' ') { // 檢查每個字符是否為數字或空格
                    isNumeric = false;
                    break;
                }
            }
            if (isNumeric){
                string temp;
                for (stringstream ss(line); ss >> temp; ) {
                    // 将字符串转换为int，并存储在数组中
                    num[index] = stoi(temp) + 11;
                    index++;
                }
            }
            if (isNumeric) {
                string newLine = "";
                for(i = 0; i < index; i++) {
                    newLine += to_string(num[i]) + " ";
                }
                line = newLine;
            }

            
            myFile2 << line << endl; // 將處理後的行寫入新文件
        }

        myFile.close();
        myFile2.close();
    } else {
        cout << "Unable to open file";
    }

    return 0;
}