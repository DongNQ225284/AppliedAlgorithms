/*
LAB.04.05 - Truy tìm kho báu
Mô tả
Trong thế giới huyền bí của vương quốc An Lạc, huyền thoại kể về một lời nguyền cổ xưa mà chỉ những kẻ dũng cảm nhất mới có thể phá vỡ.
Vương quốc này có những kho báu bí ẩn, mỗi kho chứa một lượng vàng khổng lồ ci, được đặt tại các vị trí kỳ diệu có tọa độ (xi, yi).

Những người đi tìm kho báu chỉ có thể bắt đầu hành trình từ cổng thành cổ tại (0, 0) và theo một quy tắc đặc biệt:
Họ chỉ được phép di chuyển về phía mặt trời mọc — tức là theo hướng không giảm của cả hai tọa độ x và y — để tìm đến các kho báu.

Nói cách khác, từ kho báu tại tọa độ (xi, yi), người ta chỉ có thể tiếp tục hành trình đến kho báu (xj, yj) nếu:

xi ≤ xj và yi ≤ yj

Kẻ tìm kho báu cần phải sắp xếp một lộ trình khôn ngoan để thu thập được nhiều vàng nhất, nhưng luôn tuân thủ hướng đi "mặt trời mọc" như đã mô tả.

Dữ liệu vào
Dòng đầu tiên chứa số nguyên dương n — số lượng kho báu (1 ≤ n ≤ 10³)

n dòng tiếp theo, mỗi dòng chứa 3 số nguyên dương:
xi, yi, ci (1 ≤ xi, yi, ci ≤ 10⁹)
đại diện cho tọa độ và lượng vàng của kho báu thứ i

Kết quả
In ra một số nguyên duy nhất — là tổng lượng vàng lớn nhất có thể thu thập được theo quy tắc đã cho.

Ví dụ
Dữ liệu vào:

Sao chép
Chỉnh sửa
10
2 4 7
4 2 10
4 6 2
5 5 7
1 3 9
1 5 1
1 1 3
3 1 5
3 3 6
2 2 2
Kết quả:

Sao chép
Chỉnh sửa
26
Giải thích:
Lộ trình tối ưu đi qua các kho báu có tọa độ lần lượt là:
(1, 1) → (1, 3) → (2, 4) → (5, 5)
Tổng lượng vàng thu được là: 3 + 9 + 7 + 7 = 26
*/