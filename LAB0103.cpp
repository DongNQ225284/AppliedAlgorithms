/*
Problem: LAB.01.03 - Range Minimum Query
Description:
Given a sequence of n integers a0,. . .,an-1. 
We denote rmq(i,j) the minimum element of the sequence ai, ai+1, . . .,aj. 
Given m pairs (i1, j1),. . .,(im, jm), compute the sum Q = rmq(i1,j1) + . . . + rmq(im, jm)
Input:
Line 1: n (1 <=  n <= 10^6)
Line 2: a0, . . . ,an-1 (1 <= ai <= 10^6)
line 3: m (1 <= m <= 10^6)
Line k+3 (k=1, . . ., m): ik, jk (0 <= ik < jk < n)
Output:
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6
*/
#include <bits/stdc++.h>
#define ll long long
#define MAX = 4e6
using namespace std;

ll n;
ll a[MAX], T[MAX];

void build(ll node, ll start, ll end) {
    if (start == end) {
        T[node] = a[start];
        return;
    } 
    ll mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    T[node] = min(a[2 * node], a[2 * node + 1]);
}

void input() {
    cin >> n;
    for (ll i = 0; i != n; i++) cin >> a[i];
    build(1, 0, n - 1);
}

ll rmq(ll node, ll start, ll end, ll left, ll right) {
    if (left > right) return INT_MAX;
    if (left == right) return a[left];
    if (right < start || left > end) return INT_MAX;
    if (start <= left && rihgt >= end) return T[node];
    if ()
    if ()
}
int main() {
    input();
    build(1, 0, n - 1);

}