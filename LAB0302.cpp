/*
LAB.03.02 - Inversion
Mô tả
Given a sequence of integers a1, a2, ..., an. A pair (i, j) is call an inversion if i < j and ai > aj. Compute the number Q of inversions
Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a1, a2, ..., an (0 <= ai<= 10^6)
Output
Write the value Q modulo 10^9+7

Example
Input
6
3 2 4 5 6 1
Output
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