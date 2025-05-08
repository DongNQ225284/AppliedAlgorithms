/*
LAB.02.03 - Phân công khóa học cân bằng
Mô tả:
Vào đầu học kỳ, trưởng khoa của một khoa khoa học máy tính phải phân công các khóa học cho các giảng viên một cách cân bằng. Khoa D có m giảng viên T = {1, 2, ..., m} và n khóa học C = {1, 2, ..., n}.
Mỗi giảng viên t ∈ T có một danh sách ưu tiên là các khóa học mà giảng viên đó có thể giảng dạy, tùy thuộc vào chuyên môn của họ.
Chúng ta cũng biết một danh sách các cặp khóa học mâu thuẫn không thể giao cho cùng một giảng viên, vì những khóa học này đã được lên lịch trong cùng một thời gian biểu.
Tải của một giảng viên là số lượng khóa học được giao cho giảng viên đó.
Câu hỏi là làm thế nào để phân công n khóa học cho m giảng viên sao cho mỗi khóa học được giao cho một giảng viên thuộc danh sách ưu tiên của giảng viên đó, không có hai khóa học mâu thuẫn được giao cho cùng một giảng viên, và tải cao nhất của giảng viên là nhỏ nhất.

Dữ liệu vào (Input):
Dòng 1: Hai số nguyên m và n (1 ≤ m ≤ 10, 1 ≤ n ≤ 30)
Dòng i+1 (i=1, 2, ..., m): Mỗi dòng chứa một số nguyên dương k và k số nguyên dương chỉ các khóa học mà giảng viên i có thể giảng dạy (∀i = 1, ..., m)
Dòng m+2: Một số nguyên dương k (là số cặp khóa học mâu thuẫn)
Dòng i+m+k: Mỗi dòng chứa hai số nguyên i và j chỉ hai khóa học mâu thuẫn (∀i = 1, ..., k)

Kết quả (Output):
In ra một số duy nhất là tải cao nhất của giảng viên trong giải pháp tìm được. Nếu không thể tìm được giải pháp, in ra -1.

Ví dụ:
Input:
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12
Output:
3
*/
#include <bits/stdc++.h>
using namespace std;

int m, n;
