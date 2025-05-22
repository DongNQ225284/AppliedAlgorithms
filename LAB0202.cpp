/*
LAB.02.02 - CBUS
Mô tả:
Có n hành khách, đánh số từ 1 đến n. Mỗi hành khách i muốn di chuyển từ điểm i đến điểm i + n (i = 1, 2, ..., n).
Có một chiếc xe buýt đang ở điểm 0 và có k chỗ ngồi để vận chuyển hành khách (nghĩa là vào bất kỳ thời điểm nào, xe buýt chỉ có tối đa k hành khách). Bạn được cho ma trận khoảng cách c, trong đó c(i, j) là khoảng cách di chuyển từ điểm i đến điểm j (i, j = 0, 1, ..., 2n).
Hãy tính toán tuyến đường ngắn nhất cho xe buýt, phục vụ n hành khách và quay lại điểm 0.

Dữ liệu vào (Input):
Dòng 1: Hai số nguyên n và k (1 ≤ n ≤ 11, 1 ≤ k ≤ 10)
Dòng i+1 (i=1, 2, ..., 2n+1): Dòng thứ (i-1) của ma trận khoảng cách c (các dòng và cột được đánh số từ 0, 1, ..., 2n).

Kết quả (Output):
In ra độ dài của tuyến đường ngắn nhất.

Ví dụ:
Input:
3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
Output:
25

Cấu trúc lưu trữ:
best: Độ dài tuyến đường ngắn nhất
x[i]: Tại vị trí i sẽ di chuyển tới địa điểm x[i]
C[i][j]: Khoảng cách từ thành phố i đến j
M[i]: Nếu hành khách thứ i đã đón thì M[i] = 1, nếu chưa đón M[i] = 0
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX 30
using namespace std;

ll x[MAX], M[MAX], C[MAX][MAX];
ll n, K, load = 0, best = 1e10, dis = 0;
ll c_min = 1e10;

void input() {
    cin >> n >> K;
    for (ll i = 0; i <= 2*n; i++) {
        for (ll j = 0; j <= 2*n; j++) {
            cin >> C[i][j];
            if (i != j) c_min = min(c_min, C[i][j]);
        }
    }
}

bool check(ll v, ll k) {
    if (M[v]) return false;                                 //nếu đã thăm
    if (v <= n && load >= K) return false;                 //nếu đi đón mà số lượng đã đầy rồi
    if (v > n && !M[v - n]) return false;                   //nếu đi trả mà chưa đón
    if (dis + c_min * (2*n - k + 1) >= best) return false;  //cắt nhánh
    return true;
}
void TRY(ll k) {
    for (ll v = 1; v <= 2*n; v++) {
        if (check(v, k)) {
            //update
            if (v <= n) load++;
            else load--;
            x[k] = v;
            dis += C[x[k - 1]][v];
            M[v] = 1;

            if (k < 2*n) {
                TRY(k + 1);
            } else {
                //solution
                best = min(best, dis + C[x[2*n]][0]);
            }

            //rollback
            M[v] = 0;
            if (v <= n) load--;
            else load++;
            dis -= C[x[k - 1]][v];
        }
    }
}

int main() {
    input();
    TRY(1);
    cout << best << endl;
    return 0;
}