/*
LAB.05.02 - Cầu và đỉnh khớp trong đồ thị

Mô tả:
Cho một đồ thị vô hướng gồm N đỉnh và M cạnh.
Hãy tìm tất cả các đỉnh khớp (articulation points) và cầu (bridges) trong đồ thị.
Đỉnh khớp là đỉnh mà nếu loại bỏ nó (và các cạnh kề), số thành phần liên thông của đồ thị tăng lên.
Cầu là cạnh mà nếu loại bỏ nó, số thành phần liên thông của đồ thị tăng lên.

Dữ liệu vào:
Dòng 1: Hai số nguyên N và M — số đỉnh và số cạnh của đồ thị
M dòng tiếp theo: mỗi dòng gồm hai số nguyên X và Y — biểu diễn một cạnh nối giữa đỉnh X và đỉnh Y (1 <= X, Y <= N)

Dữ liệu ra:
Một dòng chứa hai số nguyên:
Số lượng đỉnh khớp
Số lượng cầu

Ví dụ:
Dữ liệu vào:
10 12
1 10
10 2
10 3
2 4
4 5
5 2
3 6
6 7
7 3
7 8
8 9
9 7
Dữ liệu ra:
4 3
*/