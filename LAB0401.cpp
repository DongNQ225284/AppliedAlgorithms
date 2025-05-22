/*
LAB.04.01 - Dãy con chẵn có tổng lớn nhất
Mô tả
Cho một dãy gồm n số nguyên a = a₁, a₂, ..., aₙ. Một dãy con (subsequence) là một đoạn liên tiếp các phần tử trong dãy ban đầu (ví dụ: aᵢ, aᵢ₊₁, ..., aⱼ).
Trọng số của một dãy con là tổng các phần tử trong dãy con đó.
Một dãy con được gọi là dãy con chẵn (even-subsequence) nếu trọng số của nó là một số chẵn.
Yêu cầu: Hãy tìm dãy con chẵn có trọng số lớn nhất.
Input
Dòng 1: Gồm một số nguyên dương n (1 ≤ n ≤ 10⁶) — số phần tử của dãy.
Dòng 2: Gồm n số nguyên a₁, ..., aₙ (−10⁶ ≤ aᵢ ≤ 10⁶)

Output
In ra trọng số lớn nhất của một dãy con chẵn tìm được.
Nếu không có dãy con nào thỏa mãn điều kiện, in ra: NOT_FOUND

Ví dụ
Input
4  
1 2 -3 4
Output
4
Giải thích:
Các dãy con liên tiếp có thể là: [1], [1,2], [1,2,-3], [2,-3,4], [4], ...
Dãy con [4] có tổng = 4, là số chẵn và là tổng lớn nhất trong các dãy con chẵn → in ra 4.
*/
