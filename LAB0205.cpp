/*
LAB.02.05 - Cắt vật liệu
Mô tả:
Cho một tấm vật liệu có hình chữ nhật với chiều cao H và chiều rộng W. 
Chúng ta cần cắt tấm vật liệu này thành n tấm nhỏ hơn có kích thước lần lượt là (h1, w1), (h2, w2), ..., (hn, wn). 
Viết chương trình kiểm tra xem có thể thực hiện việc cắt này hay không.

Dữ liệu vào (Input):
Dòng 1: Hai số nguyên dương H và W (1 ≤ H, W ≤ 10) — chiều cao và chiều rộng của tấm vật liệu ban đầu.
Dòng 2: Một số nguyên dương n (1 ≤ n ≤ 10) — số lượng tấm nhỏ cần cắt ra.
Dòng i+2 (i = 1,...,n): Mỗi dòng chứa hai số nguyên dương hi và wi (1 ≤ hi, wi ≤ 10) — chiều cao và chiều rộng của từng tấm nhỏ cần cắt.

Kết quả (Output):
In ra 1 nếu có thể thực hiện việc cắt và in ra 0 nếu không thể.

Ví dụ:
Input:
7 5
4
1 5
6 2
2 2
4 3
Output:
1

Cấu trúc lưu trữ: 

*/

#include <bits/stdc++.h>
#define ll long long
#define MAX 50
#define INF 1e9
using namespace std;

ll H, W;
ll n;
ll h[MAX], w[MAX];

void input() {
    cin >> H >> W;
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> h[i] >> w[i];
}


int main() {

}