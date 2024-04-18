#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::string filename = "input.txt";  // 設定文件名
    std::ifstream file(filename);        // 打開文件

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    int sum = 0;
    while (std::getline(file, line)) {   // 讀取每一行
        std::stringstream ss(line);
        int num;
        std::cout<<line<<std::endl;
        if ((ss >> num) && (ss.eof())) { // 確保整行只有一個數字
            sum += num;                  // 如果是數字，加到總和中
        }
    }

    file.close();                        // 關閉文件
    std::cout << "Sum is: " << sum << std::endl;  // 輸出總和

    return 0;
}
