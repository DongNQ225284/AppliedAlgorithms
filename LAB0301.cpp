/*
LAB.03.01 - Disjoint Segment
Mô tả
Given a set of segments X = {(a1, b1), . . . , (an, bn)} in which ai < bi are coordinates of 
the segment i on a line, i = 1, …, n. Find a subset of X having largest cardinality in which no two segments of the subset intersect
Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line i+1 (i= 1,...,n): contains ai and bi (0 <= ai <= bi <= 1000000)
Output
Number of segments in the solution found.
Example
Input
6
0 10
3 7
6 14
9 11
12 15
17 19

Output
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