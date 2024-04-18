#include <iostream>
#include <ctime>

int countWeekdays(int month, int day, int weekday) {
    struct tm start_date = {0};  // 使用 tm 結構初始化起始日期
    start_date.tm_year = 2024 - 1900;  // 設定年份
    start_date.tm_mon = 0;  // 1月
    start_date.tm_mday = 1;  // 1日

    time_t start_time = mktime(&start_date);  // 將 tm 結構轉為 time_t
    struct tm* start_ptr = localtime(&start_time);  // 轉換為本地時間

    int count = 0;
    while (start_ptr->tm_year + 1900 == 2024 && (start_ptr->tm_mon + 1 < month || (start_ptr->tm_mon + 1 == month && start_ptr->tm_mday <= day))) {
        if (start_ptr->tm_wday == weekday % 7) {  // 檢查是否為指定的星期幾
            count++;
        }
        start_time += 86400;  // 增加一天
        start_ptr = localtime(&start_time);  // 更新日期
    }

    return count;
}

int main() {
    int month, day, weekday;
    std::cout << "Enter the target date (Month Day Weekday): ";
    std::cin >> month >> day >> weekday;

    int result = countWeekdays(month, day, weekday - 1);  // 調整星期幾的輸入以適應 tm_wday
    std::cout << "From January 1, 2024 to " << month << "/" << day << "/2024, there have been " << result << " occurrences of weekday " << weekday << std::endl;

    return 0;
}
