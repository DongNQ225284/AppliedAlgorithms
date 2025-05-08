/*
LAB.03.03 - Dãy con có khoảng cách lớn nhất
Mô tả:
Cho N phần tử (2 ≤ N ≤ 100,000) trên một đường thẳng tại các vị trí 𝑥1,𝑥2,…,𝑥𝑁  (0 ≤ 𝑥𝑖​ ≤ 1,000,000,000).
Khoảng cách của một dãy con bao gồm N phần tử được định nghĩa là khoảng cách nhỏ nhất giữa hai phần tử trong dãy con đó.
Tìm một dãy con chứa chính xác C phần tử từ N phần tử cho trước sao cho khoảng cách này là lớn nhất.

Dữ liệu vào (Input):
Dòng 1: Một số nguyên dương T (1 ≤ T ≤ 20) là số lượng test case.
Dòng 2 đến Dòng T+1: Mỗi test case có định dạng:
Dòng 1: Hai số nguyên cách nhau bởi dấu cách: N và C.
Dòng 2: Chứa dãy số 𝑥1,𝑥2,…,𝑥𝑁 — các vị trí của các phần tử.

Kết quả (Output):
Với mỗi test case, in ra một số nguyên duy nhất: khoảng cách của dãy con tìm được.

Ví dụ:
Input:
1
5 3
1 2 8 4 9
Output:
3
Giải thích:
Jonh có thể đặt 3 con bò của mình vào các chuồng có vị trí lần lượt là 1, 4 và 8, tạo ra một khoảng cách tối thiểu giữa các con bò là 3.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, N, C;
vector<ll> x;

void input() {
    cin >> N >> C;
    x.resize(N);
    for (ll i = 0; i < N; i++) cin >> x[i];
}

bool check(ll d) {
    ll Count = 1;
    ll last = 0;
    for (ll i = 1; i < N; i++) {
        if (x[i] - x[last] >= d) {
            last = i;
            Count++;
        } 
    }
    return Count >= C;
}

ll solve() {
    sort(x.begin(), x.end());
    ll U = (x[N - 1] - x[0]) / (C - 1);
    ll L = 0;
    ll d;
    while(true) {
        d = (U + L)/2;
        if (check(d)) L = d; 
        else U = d;
        if (U == L + 1) {
            if (check(U)) return U;
            else return L;
        }
    } 
}

int main() {
    cin >> T;
    while(T--) {
        input();
        cout << solve() << endl;
    }
    
    return 0;
}