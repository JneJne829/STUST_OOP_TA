import smtplib
from StudentGradeAnalyzer import StudentGradeAnalyzer
from email.mime.text import MIMEText


analyzer = StudentGradeAnalyzer('.')
analyzer.run_analysis()
latest_exam_results = analyzer.results.get(analyzer.latest_exam_file)

# SMTP 伺服器設置
smtp_server = "smtp.office365.com"  # Outlook的SMTP伺服器
smtp_port = 587  # Outlook使用的埠
email_user = "YourMail"
email_pass = "YourPassword"

# 建立SMTP連接
server = smtplib.SMTP(smtp_server, smtp_port)
server.starttls()  # 啟用安全傳輸
server.login(email_user, email_pass)

if latest_exam_results is not None:
    for index, row in latest_exam_results.iterrows():
        student_id = row['帳號']
        student_name = row['名稱']
        student_score = row['成績']
        
        # 產生電子郵件地址
        student_email = f"{student_id}@xxxx"
        count = analyzer.student_appearances[(student_id, student_name)]
        # 郵件內容
        subject = "關於您在最近測驗中的表現"
        body = f"親愛的同學 {student_id} {student_name}，\n\n我們注意到您在最近的物件導向程式設計實習測驗中的表現為全班的低 1/3 ，成績為 {student_score}，這是您本學期第 {count} 次成績為全班的低 1/3 。再次提醒!\n參加TA課輔可以為本學期的成績加分!"
        
        message = MIMEText(body)
        message['From'] = email_user
        message['To'] = student_email
        message['Subject'] = subject

        server.sendmail(email_user, [student_email], message.as_string())
        print(f"郵件內容: {body}")
        print(f"郵件已傳送至 {student_name} ({student_email})。\n發送信箱 {email_user} To {student_email}。\n\n")

# 斷開SMTP連接
server.quit()

print("郵件已發送給成績不好的學生。")