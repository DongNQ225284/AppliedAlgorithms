/*
LAB.04.03 - Kho hàng

Mô tả
Một chiếc xe tải được lên kế hoạch đến một số trạm trong số N trạm, được đánh số từ 1 đến N, nằm dọc theo một đường thẳng. Mỗi trạm i (với i = 1,…,N) có tọa độ là i và có các thông tin sau:
ai: số lượng hàng hóa có tại trạm i
ti: thời gian cần thiết để lấy hàng tại trạm i

Lộ trình của xe tải là một dãy các trạm: x₁ < x₂ < … < xk (với 1 ≤ xj ≤ N, j = 1,…,k). Do hạn chế kỹ thuật, xe tải chỉ được:
Di chuyển giữa hai trạm liên tiếp không quá D đơn vị khoảng cách (|x_(i+1) - xi| ≤ D)
Tổng thời gian lấy hàng tại các trạm không vượt quá T

Hãy tìm một lộ trình cho xe tải sao cho tổng số hàng hóa lấy được là lớn nhất có thể.

Input:
Dòng 1: Gồm 3 số nguyên N, T, D (1 ≤ N ≤ 1000, 1 ≤ T ≤ 100, 1 ≤ D ≤ 10)
Dòng 2: Gồm N số nguyên a1, ..., aN (1 ≤ ai ≤ 10): số lượng hàng tại mỗi trạm
Dòng 3: Gồm N số nguyên t1, ..., tN (1 ≤ ti ≤ 10): thời gian lấy hàng tại mỗi trạm

Output
In ra tổng lượng hàng hóa lớn nhất mà xe tải có thể lấy được theo một lộ trình hợp lệ.

Ví dụ
Input:
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2
Output:
24
*/