/*
LAB.04.02 - Y tá

Mô tả
Giám đốc của một bệnh viện muốn lập kế hoạch làm việc cho một y tá trong khoảng thời gian N ngày liên tiếp, được đánh số từ 1 đến N. Theo quy định của bệnh viện, mỗi y tá không được làm việc tất cả các ngày từ 1 đến N. Thay vào đó, phải có những ngày nghỉ để y tá được nghỉ ngơi.
Một kế hoạch làm việc là một chuỗi các giai đoạn làm việc không giao nhau.
Một giai đoạn làm việc của y tá được định nghĩa là một chuỗi các ngày liên tiếp mà y tá phải làm việc. Độ dài của giai đoạn làm việc là số ngày liên tiếp đó.

Bệnh viện đặt ra hai ràng buộc như sau:
Mỗi y tá chỉ được nghỉ tối đa một ngày giữa hai giai đoạn làm việc liên tiếp. Điều này có nghĩa là nếu hôm nay nghỉ thì ngày mai phải đi làm.
Độ dài của mỗi giai đoạn làm việc phải lớn hơn hoặc bằng K₁ và nhỏ hơn hoặc bằng K₂.
Giám đốc muốn biết có bao nhiêu kế hoạch làm việc hợp lệ thỏa mãn hai ràng buộc trên?

Input
Dòng duy nhất chứa 3 số nguyên dương N, K₁, K₂ với ràng buộc:
2 ≤ N ≤ 1000, K₁ < K₂ ≤ 400

Output
In ra một số nguyên duy nhất M, là số kế hoạch làm việc hợp lệ, lấy modulo 10⁹ + 7.

Ví dụ

Input:
6 2 3
Output:

Sao chép
4
*/