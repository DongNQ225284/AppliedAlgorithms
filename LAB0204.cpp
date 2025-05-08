/*
LAB.02.04 - Lộ trình giao hàng cho xe tải có dung tải hạn chế
Mô tả:
Có một đội xe tải gồm K xe tải giống nhau, mỗi xe có dung tải là Q. Các xe tải này cần được lên lịch để giao các gói pepsi từ một kho trung tâm (điểm 0) đến các khách hàng 1, 2, ..., n. Mỗi khách hàng i yêu cầu d[i] gói. 
Khoảng cách từ vị trí i đến vị trí j được cho bởi ma trận khoảng cách c[i, j], với 0 ≤ i, j ≤ n.
Một giải pháp giao hàng là một tập hợp các lộ trình: mỗi xe tải sẽ có một lộ trình bắt đầu từ kho, ghé thăm một số khách hàng và quay lại kho để giao các gói pepsi theo yêu cầu, sao cho:
Mỗi khách hàng được ghé thăm bởi đúng một lộ trình
Tổng số gói yêu cầu của các khách hàng mà mỗi xe tải phục vụ không vượt quá dung tải của nó

Mục tiêu:
Tìm giải pháp có tổng quãng đường di chuyển tối thiểu.

Lưu ý:
Có thể có trường hợp một xe tải không ghé thăm khách hàng nào (lộ trình rỗng).
Thứ tự các khách hàng trong một lộ trình là quan trọng, ví dụ: các lộ trình 0 -> 1 -> 2 -> 3 -> 0 và 0 -> 3 -> 2 -> 1 -> 0 là khác nhau.

Dữ liệu vào (Input):
Dòng 1: Ba số nguyên n, K, Q (2 ≤ n ≤ 12, 1 ≤ K ≤ 5, 1 ≤ Q ≤ 50)
Dòng 2: d[1], d[2], ..., d[n] (1 ≤ d[i] ≤ 10) — yêu cầu của mỗi khách hàng.
Dòng i+3 (i = 0,...,n): Dòng thứ i của ma trận khoảng cách c (1 ≤ c[i, j] ≤ 30)

Kết quả (Output):
In ra tổng quãng đường di chuyển tối thiểu.

Ví dụ:
Input:
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0
Output:
70
*/