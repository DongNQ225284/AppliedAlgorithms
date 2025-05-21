/*
LAB.04.01 - Dãy con chẵn có tổng lớn nhất
Mô tả
Cho một dãy gồm n số nguyên a = a₁, a₂, ..., aₙ. Một dãy con (subsequence) là một đoạn liên tiếp các phần tử trong dãy ban đầu (ví dụ: aᵢ, aᵢ₊₁, ..., aⱼ).
Trọng số của một dãy con là tổng các phần tử trong dãy con đó.
Một dãy con được gọi là dãy con chẵn (even-subsequence) nếu trọng số của nó là một số chẵn.
Yêu cầu: Hãy tìm dãy con chẵn có trọng số lớn nhất.
Input
Dòng 1: Gồm một số nguyên dương n (1 ≤ n ≤ 10⁶) — số phần tử của dãy.
Dòng 2: Gồm n số nguyên a₁, ..., aₙ (−10⁶ ≤ aᵢ ≤ 10⁶)

Output
In ra trọng số lớn nhất của một dãy con chẵn tìm được.
Nếu không có dãy con nào thỏa mãn điều kiện, in ra: NOT_FOUND

Ví dụ
Input
4  
1 2 -3 4
Output
4
Giải thích:
Các dãy con liên tiếp có thể là: [1], [1,2], [1,2,-3], [2,-3,4], [4], ...
Dãy con [4] có tổng = 4, là số chẵn và là tổng lớn nhất trong các dãy con chẵn → in ra 4.
*/
#include <bits/stdc++.h>
#define ll long long
#define NOT_FOUND -1e10
using namespace std;

ll n;
ll res;
vector<ll> a;
vector<ll> S; //mảng cộng dồn

void input() {
    cin >> n;
    a.resize(n);
    S.resize(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
}

void solve() {
    S[0] = a[0];
    for (ll i = 1; i < n; i++) S[i] = S[i - 1] + a[i];
    ll Min;

    ll best_even = NOT_FOUND;
    Min = 0;
    for (ll i = 0; i < n; i++) {
        if (S[i] % 2) continue;
        best_even = max(best_even, S[i] - Min);
        Min = min(Min, S[i]);
    }
 
    Min = NOT_FOUND;
    for (ll i = 0; i < n; i++) {
        if (S[i] % 2) {
            Min = S[i];
            break;
        }
    }
    if (Min != NOT_FOUND)
    ll best_odd = NOT_FOUND;
    for (ll i = 0; i < n; i++) {
        if (S[i] % 2 == 0) continue;
        best_odd = max(best_odd, S[i] - Min);
        Min = Min % 2 ? min(Min, S[i]) : S[i];
    }
    res = max(best_even, best_odd);
    if (res == NOT_FOUND) cout << "NOT_FOUND" << endl;
    else cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}