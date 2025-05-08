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

*/

#include <bits/stdc++.h>
using namespace std;

int n, cap;
vector<vector<int>> C;
vector<bool> mark;
vector<int> x;
vector<int> V;
int load, cost, best = 1e9, c_min = 1e9;

void input() {
    cin >> n >> cap;
    for (int i = 0; i != 2 * n + 1; i++) {
        vector<int> ele(2 * n + 1);
        for (int j = 0; j != 2 * n + 1; j++) {
            cin >> ele[j];
            if (i != j) c_min = min(c_min, ele[j]);
        }
        C.push_back(ele);
        V.push_back(i);
    }
    cost = load = 0;
    x.resize(2 * n + 1, 0);
    mark.resize(2 * n + 1, false);
}

bool check(int v, int k) {
    if (v == 0) return false;
    if (mark[v]) return false;
    if (v <= n && load >= cap) return false;
    if (v > n && !mark[v - n]) return false;
    if (best < cost + c_min * (2 * n + 1 - k)) return false;
    return true;
}

void update(int v, int k) {
    if (v <= n) load++;
    else load--;
    x[k] = v;
    cost += C[x[k - 1]][v];
    mark[v] = true;
}

void rollback(int v, int k) {
    if (v <= n) load--;
    else load++;

    x[k] = 0;
    cost -= C[x[k - 1]][v];
    mark[v] = false;
}

void solution() {
    best = min(cost + C[x[2 * n]][0], best);
}

void TRY(int k) {
    for (int v : V) {
        if (!check(v, k)) continue;
        update(v, k);
        if (k == 2 * n) solution();
        else TRY(k + 1);    
        rollback(v, k);
    }
}

int main() {
    input();
    TRY(1);
    cout << best << endl;
}