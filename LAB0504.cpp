/*
LAB.05.04 - Gán công việc tối đa trên đồ thị hai phía

Mô tả:
Có n công việc được đánh số từ 1 đến n và m nhân viên được đánh số từ 1 đến m.
T(i) là tập các nhân viên có thể thực hiện công việc i (với i = 1, ..., n).
Hãy tìm một cách gán nhân viên cho các công việc sao cho:
Mỗi công việc được gán cho không quá một nhân viên
Mỗi nhân viên không được gán quá một công việc
Số lượng công việc được gán là lớn nhất có thể

Dữ liệu vào:
Dòng 1: Hai số nguyên dương n và m (1 <= n, m <= 10000)
n dòng tiếp theo: Dòng thứ i+1 chứa một số nguyên k, theo sau là k số nguyên là chỉ số của các nhân viên trong T(i)

Dữ liệu ra:
Ghi ra số lượng công việc được gán là lớn nhất

Ví dụ:
Dữ liệu vào:
3 4
2 1 4
2 1 3
1 2
Dữ liệu ra:
3
*/