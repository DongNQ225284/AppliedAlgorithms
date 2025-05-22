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
Khởi tạo một struct để đóng gói thông tin về cách đặt, (x, y) là tọa độ góc trái, rotated là có xoay 90 không
Lời giải của bài toán là Place x[i] cho biết cách đặt của tấm kim loại thứ i
Không gian lời giải của bài toán là các điểm đặt trong tấm kim loại và hướng xoay

Sử dụng M[i][j] để đánh dấu những ô đã cắt
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX 50
#define INF 1e9

using namespace std;

struct Place{
    ll x, y;
    bool rotated;
    Place() {
        this->x = this->y = 0;
        this->rotated = 0;
    }
    Place(ll x, ll y, ll rotated) {
        this->x = x;
        this->y = y;
        this->rotated = rotated;
    }
};

ll H, W;
ll n;
ll h[MAX], w[MAX];
ll M[MAX][MAX];
Place x[MAX];
bool ans;

void input() {
    cin >> H >> W;
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> h[i] >> w[i];
}

bool check(Place v, ll k) {
    ll height = v.rotated ? w[k] : h[k];
    ll width  = v.rotated ? h[k] : w[k];
    if (v.y + height > H) return false;             //vượt biên
    if (v.x + width  > W) return false;             //vượt biên
    for (ll i = v.y; i < v.y + height; i++) {
        for (ll j = v.x; j < v.x + width; j++) {
            if (M[i][j]) return false;              //nếu đã đánh dấu
        }
    }
    return true;
}

void update(Place v, ll k, ll val = 1) {
    ll height = v.rotated ? w[k] : h[k];
    ll width  = v.rotated ? h[k] : w[k];
    for (ll i = v.y; i < v.y + height; i++) {
        for (ll j = v.x; j < v.x + width; j++) {
            M[i][j] = val;
        }
    }
}

void rollback(Place v, ll k) {
    update(v, k, 0);
}

bool TRY(ll k) {
    for (ll r = 0; r <= 1; r++) {
        for (ll i = 0; i < H; i++) {
            for (ll j = 0; j < W; j++) {
                Place v(j, i, r);
                if (check(v, k)) {
                    update(v, k);
                    if (k < n) {
                        if (TRY(k + 1)) return true;
                    } else {
                        ans = true;
                        return true;
                    }
                    rollback(v, k);
                }
            }
        }
    }
    return false;
}

int main() {
    input();
    TRY(1);
    cout << ans << endl;
    return 0;
}