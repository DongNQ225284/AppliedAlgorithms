/*
LAB.03.02 - Đảo ngược
Mô tả:Cho một dãy số nguyên 𝑎1,𝑎2,…,𝑎𝑛. Một cặp chỉ số (𝑖,𝑗) được gọi là một đảo ngược nếu 𝑖<𝑗 và 𝑎𝑖>𝑎𝑗. 
Tính số lượng 𝑄 của các đảo ngược trong dãy số.

Dữ liệu vào (Input):
Dòng 1: Chứa một số nguyên dương 𝑛 (1 ≤ 𝑛 ≤ 1000000) — chiều dài dãy số.
Dòng 2: Chứa dãy số 𝑎1,𝑎2,…,𝑎𝑛 (0 ≤ 𝑎𝑖 ≤ 1000000) — dãy số nguyên.

Kết quả (Output):
In ra số lượng đảo ngược 𝑄 trong dãy số, kết quả tính theo mô-đun 10^9 + 7.

Ví dụ:
Input:

6
3 2 4 5 6 1
Output:
6
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll c = 0;
vector<ll> a;

void input() {
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
}

void merge(vector<ll>&arr) {
    if (arr.size() <= 1) return;

    ll mid = arr.size() / 2;
    vector<ll> leftArr(arr.begin(), arr.begin() + mid);
    vector<ll> rightArr(arr.begin() + mid, arr.end());

    merge(leftArr);
    merge(rightArr);

    ll i = 0, j = 0;
    vector<ll> mergeArr;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            mergeArr.push_back(leftArr[i++]);
        } else {
            mergeArr.push_back(rightArr[j++]);
            c += (leftArr.size() - i);
        }
    }
    while (i < leftArr.size()) mergeArr.push_back(leftArr[i++]);
    while (j < rightArr.size()) mergeArr.push_back(rightArr[j++]);
    arr = mergeArr;
}

ll solve() {
    merge(a);
    return c % (ll)(1e9 + 7);
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}