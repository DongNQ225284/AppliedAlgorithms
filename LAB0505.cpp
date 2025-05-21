/*
LAB.05.05 - Lập lịch thi công tối ưu

Mô tả:
Một dự án gồm n công việc được đánh số từ 1 đến n. Công việc i cần thời gian d(i) để hoàn thành (với i = 1, ..., n).
Giữa các công việc có các ràng buộc thứ tự thực hiện, được biểu diễn bởi tập Q gồm các cặp (i, j): 
nghĩa là công việc j không thể bắt đầu cho đến khi công việc i hoàn thành.

Hãy tính thời điểm sớm nhất để dự án có thể hoàn thành.

Dữ liệu vào:
Dòng 1: Hai số nguyên n và m (1 <= n <= 10^4, 1 <= m <= 200000)
Dòng 2: n số nguyên d(1), ..., d(n) (1 <= d(i) <= 1000), biểu diễn thời gian thực hiện của từng công việc
m dòng tiếp theo, mỗi dòng gồm hai số nguyên i và j: công việc j không thể bắt đầu trước khi công việc i hoàn thành

Dữ liệu ra:
Ghi ra thời điểm sớm nhất mà toàn bộ dự án có thể hoàn thành

Ví dụ:
Dữ liệu vào:
9 13
5 3 1 2 6 4 3 1 4
1 3
1 5
1 6
2 1
2 3
3 5
4 1
4 2
4 6
5 8
7 9
9 5
9 8
Dữ liệu ra:
18
*/