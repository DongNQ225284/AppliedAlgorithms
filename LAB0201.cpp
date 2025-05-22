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

Cấu trúc lưu trữ:
ll x[i] nghiệm của phương trình
ll a[i] hệ số của các x[i]

*/

#include <bits/stdc++.h>
#define ll long long
#define MAX 10005
using namespace std;

ll x[MAX], a[MAX];
ll n, M;
ll sum = 0;
ll Count = 0;

void input() {
    cin >> n >> M;
    for (ll i = 1; i <= n; i++) cin >> a[i];
}
void TRY(ll k) {
    for (ll v = 1; v <= M / a[k]; v++) {
        //update
        x[k] = v;
        sum += v * a[k];
        
        if (k < n) {
            TRY(k + 1);
        } else {
            //solution
            if (sum == M) Count++;
        }
        //rollback
        sum -= v * a[k];
    }
}

int main() {
    input();
    TRY(1);
    cout << Count << endl;
    return 0;
}