/*
LAB.05.01 - Tính số thành phần liên thông mạnh của đồ thị có hướng

Mô tả:
Cho một đồ thị có hướng G = (V, E), trong đó V = {1, ..., N} là tập các đỉnh và E là tập gồm M cung (cạnh có hướng). 
Hãy tính số lượng thành phần liên thông mạnh trong đồ thị G.

Dữ liệu vào:
Dòng 1: Hai số nguyên dương N và M (1 <= N <= 10^5, 1 <= M <= 10^6)
M dòng tiếp theo, mỗi dòng gồm hai số nguyên u và v, biểu diễn cung có hướng từ đỉnh u đến đỉnh v

Dữ liệu ra:
Ghi ra số lượng thành phần liên thông mạnh của đồ thị G

Ví dụ:
Dữ liệu vào:
8 13
1 2
1 8
2 3
2 6
3 6
4 3
4 6
5 4
6 5
7 1
7 2
7 6
8 7
Dữ liệu ra:
3
*/