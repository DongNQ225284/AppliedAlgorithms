/*
LAB.03.03 - Max-Distance Sub-Sequence
Mô tả
Given N elements (2≤ N ≤100,000) on a straight line at positions x1,…, xN (0≤ xi ≤1000000000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.
Input
The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases. 
Subsequent lines are T test cases with the following format:
Line 1: Two space-separated integers: N and C
Lines 2: contains  x1, x2, . . . , xN

Output
For each test case output one integer: the distance of the subset found.

Example
input
1
5 3
1 2 8 4 9
output
3

Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
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