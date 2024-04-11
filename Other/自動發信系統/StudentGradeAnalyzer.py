import pandas as pd
import math
import glob
from collections import Counter
import re

class StudentGradeAnalyzer:
    def __init__(self, directory_path):
        """初始化分析器並設定目錄路徑。"""
        self.directory_path = directory_path
        self.results = {}
        self.student_appearances = Counter()
        self.latest_exam_file = ''  # 存儲最新考試文件的文件名

    def find_lowest_third_students(self, file_paths):
        """
        讀取給定的多個xlsx文件，分別找出每個文件中成績最低的三分之一的學生。
        """
        for file_path in file_paths:
            data = pd.read_excel(file_path, header=1)
            data['成績'] = data['成績'].astype(float)
            
            total_students = len(data)
            students_to_find = math.ceil(total_students / 3)
            
            lowest_students = data.nsmallest(students_to_find, '成績')
            file_name = file_path.split('/')[-1]  # 從路徑中提取文件名
            self.results[file_name] = lowest_students[['帳號', '名稱', '成績']]

    def find_latest_exam_file(self):
        """
        根據self.results中的文件名，找出最新的考試文件的鍵。
        """
        latest_exam_number = -1
        for file_key in self.results.keys():
            match = re.search(r'exam(\d+)\.xlsx', file_key)
            if match:
                exam_number = int(match.group(1))
                if exam_number > latest_exam_number:
                    latest_exam_number = exam_number
                    self.latest_exam_file = file_key

    def count_student_appearances(self):
        """
        統計每位學生被記為成績最低1/3的次數。
        """
        for df in self.results.values():
            student_info = zip(df['帳號'].tolist(), df['名稱'].tolist())
            self.student_appearances.update(student_info)
    
    def find_xlsx_files(self):
        """
        在給定目錄下查找所有的.xlsx文件。
        """
        xlsx_files = glob.glob(f"{self.directory_path}/**/*.xlsx", recursive=True)
        return xlsx_files

    def display_latest_exam_results(self):
        """顯示最新考試文件的結果。"""
        if self.latest_exam_file:
            print(f"最新的考試文件為: {self.latest_exam_file}")
            latest_results = self.results.get(self.latest_exam_file, None)
            if latest_results is not None:
                print("最新考試的學生資料如下：")
                print(latest_results)
            else:
                print("未找到最新考試的學生資料。")
        else:
            print("未找到最新的考試文件。")

    def run_analysis(self):
        """執行分析流程。"""
        file_paths = self.find_xlsx_files()
        print("找到的.xlsx文件:", file_paths)
        self.find_lowest_third_students(file_paths)
        self.find_latest_exam_file()
        print("最新的考試文件:", self.latest_exam_file)
        self.count_student_appearances()

        # 打印每個文件的分析結果
        for file_key, df in self.results.items():
            print(f"文件 {file_key} 的結果:")
            print(df, '\n')
        
        # 按出現次數從高到低排序並打印
        for (student_id, student_name), count in self.student_appearances.most_common():
            spaces_needed = 8 - sum([2 if '\u4e00' <= c <= '\u9fff' else 1 for c in student_name])
            formatted_name = student_name + ' ' * spaces_needed
            print(f"學號: {student_id}, 姓名: {formatted_name}, 重複次數: {count}")

# 使用示例
analyzer = StudentGradeAnalyzer('.')
analyzer.run_analysis()
analyzer.display_latest_exam_results()
