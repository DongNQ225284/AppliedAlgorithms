/*
LAB.02.01 - Đếm số nghiệm của một phương trình tuyến tính nguyên
Mô tả:
Cho một số nguyên dương n và n số nguyên dương a₁, a₂, ..., aₙ.
Hãy tính số nghiệm nguyên dương (tức là các ẩn số đều > 0) của phương trình sau:
a₁·X₁ + a₂·X₂ + ... + aₙ·Xₙ = M

Input:
Dòng 1: Hai số nguyên dương n và M
Dòng 2: n số nguyên dương a₁, a₂, ..., aₙ

Output:
In ra số nghiệm nguyên dương của phương trình

Ví dụ:
Input:
3 5
1 1 1
Output:
6

Giải thích:
Phương trình: X₁ + X₂ + X₃ = 5 với X₁, X₂, X₃ > 0.
Có 6 bộ nghiệm thỏa mãn:
(3,1,1), (1,3,1), (1,1,3)
(2,2,1), (2,1,2), (1,2,2)
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int M;
int sum = 0;
int Count = 0;
vector<int> a; //coeffi
vector<int> V; //applicant set
vector<int> x; //solution


void input() {
    cin >> n >> M;
    a.resize(n);
    for (int i = 0; i != n; i++) cin >> a[i];
    for (int i = 1; i <= M ; i++) V.push_back(i);
    x.resize(n, 0);
}

bool check(int v, int k) {
    return sum + a[k] * v <= M;
}

void update(int v, int k) {
    sum += v * a[k];
    x[k] = v;
}

void rollback(int v, int k) {
    sum -= v * a[k];
    x[k] = 0;
}

void solution() {
   if (sum == M) Count++;
}

void TRY(int k) {
    for (int v : V) {
        if (!check(v, k)) continue;
        update(v, k);
        if (k == n - 1) solution();
        else TRY(k + 1);    
        rollback(v, k);
    }
}

int main() {
    input();
    TRY(0);
    cout << Count << endl;
}