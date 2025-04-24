/*
Problem: LAB.02.02 - CBUS
Description
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). 
There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, 
there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling 
distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers 
and coming back to point 0. 
Input
Line 1 contains n and k (1 ≤ n ≤ 11,1 ≤ k ≤ 10)
 Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
Unique line contains the length of the shortest route.
Example
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

#include <bits/stdc++.h>
using namespace std;

int n, cap;
vector<vector<int>> C;
vector<bool> mark;
vector<int> x;
vector<int> V;
int load, cost, best = 1e9, c_min = 1e9;

void input() {
    cin >> n >> cap;
    for (int i = 0; i != 2 * n + 1; i++) {
        vector<int> ele(2 * n + 1);
        for (int j = 0; j != 2 * n + 1; j++) {
            cin >> ele[j];
            if (i != j) c_min = min(c_min, ele[j]);
        }
        C.push_back(ele);
        V.push_back(i);
    }
    cost = load = 0;
    x.resize(2 * n + 1, 0);
    mark.resize(2 * n + 1, false);
}

bool check(int v, int k) {
    if (v == 0) return false;
    if (mark[v]) return false;
    if (v <= n && load >= cap) return false;
    if (v > n && !mark[v - n]) return false;
    if (best < cost + c_min * (2 * n + 1 - k)) return false;
    return true;
}

void update(int v, int k) {
    if (v <= n) load++;
    else load--;

    x[k] = v;
    cost += C[x[k - 1]][v];
    mark[v] = true;
}

void rollback(int v, int k) {
    if (v <= n) load--;
    else load++;

    x[k] = 0;
    cost -= C[x[k - 1]][v];
    mark[v] = false;
}

void solution() {
    best = min(cost + C[x[2 * n]][0], best);
}

void show(int v, int k) {
    cout << "curr_v: " << v << endl;
    cout << "path: "; for (int i = 0; i <= k; i++) cout << x[i] << " "; cout << endl;
    cout << "cost = " << cost << endl;
    cout << "best = " << best << endl; 
    char chr; cin >> chr;
}
void TRY(int k) {
    for (int v : V) {
        if (!check(v, k)) continue;
        update(v, k);
        // show(v, k);
        if (k == 2 * n) solution();
        else TRY(k + 1);    
        rollback(v, k);
    }
}

int main() {
    input();
    TRY(1);
    cout << best << endl;
}