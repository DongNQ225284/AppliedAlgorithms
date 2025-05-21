/*
LAB.05.03 - Buýt liên thành phố

Mô tả:
Có n thành phố được đánh số từ 1 đến n. Giữa hai thành phố i và j có thể có một con đường hai chiều kết nối chúng.
Mỗi thành phố i có một tuyến buýt riêng. Tuyến buýt này có:
C[i]: giá vé mỗi lần lên xe tại thành phố i
D[i]: số lượng thành phố tối đa mà buýt i có thể đi qua (kể cả thành phố khởi hành) trong một hành trình, sử dụng các con đường kết nối
Yêu cầu: Hãy tìm cách đi từ thành phố 1 đến thành phố n sao cho chi phí ít nhất (tổng tiền vé buýt phải trả).

Dữ liệu vào:

Dòng 1: Hai số nguyên n và m — số thành phố và số con đường (1 <= n <= 5000, 1 <= m <= 10000)
n dòng tiếp theo: Dòng thứ i+1 chứa hai số nguyên C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
m dòng tiếp theo: mỗi dòng gồm hai số nguyên i và j — có con đường kết nối giữa thành phố i và j

Dữ liệu ra:
Ghi ra chi phí tối thiểu cần bỏ ra để đi từ thành phố 1 đến thành phố n bằng buýt

Ví dụ:
Dữ liệu vào:
6 6
10 2
30 1
50 1
20 3
30 1
20 1
1 2
1 3
1 5
2 4
2 5
4 6
Dữ liệu ra:
30

Giải thích:
Lên buýt tại thành phố 1, đi đến thành phố 4 (vì buýt 1 có thể đi tối đa 2 thành phố), mất 10 đồng
Lên buýt tại thành phố 4, đi đến thành phố 6, mất 20 đồng
→ Tổng cộng: 10 + 20 = 30 đồng
*/