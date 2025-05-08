/*
LAB.03.01 - Đoạn phân biệt
Mô tả:
Cho một tập hợp các đoạn thẳng 𝑋={(𝑎1,𝑏1), …, (𝑎𝑛,𝑏𝑛)} trong đó 𝑎𝑖 < 𝑏𝑖 là tọa độ của đoạn thứ 𝑖 trên một đường thẳng, với 𝑖=1,…,𝑛. 
Tìm một tập con của 𝑋 có độ lớn lớn nhất mà trong đó không có hai đoạn nào trong tập con đó giao nhau.

Dữ liệu vào (Input):
Dòng 1: Chứa một số nguyên dương 𝑛 (1 ≤ 𝑛 ≤ 100000) — số lượng đoạn thẳng.
Dòng i+1 (i = 1,...,n): Chứa hai số nguyên 𝑎𝑖 và 𝑏𝑖  (0 ≤ 𝑎𝑖  ≤ 𝑏𝑖 ≤ 1000000) — tọa độ của các đoạn thẳng.

Kết quả (Output):
In ra số lượng các đoạn thẳng trong tập con tìm được, trong đó không có hai đoạn nào giao nhau.

Ví dụ:
Input:
6
0 10
3 7
6 14
9 11
12 15
17 19
Output:
4
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
vector<pair<ll,ll>> X;

void input() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll ai, bi; cin >> ai >> bi;
        X.push_back({ai, bi});
    }
}

ll solve() {
    sort(X.begin(), X.end(), [&] (pair<ll, ll> i, pair<ll, ll> j) {
        return i.second < j.second;
    });
    ll count = 1;
    ll curr = 0;
    for (ll i = 1; i < n; i++) {
        if (X[i].first <= X[curr].second) continue;
        count++;
        curr = i; 
    } 
    return count;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}