/*
Problem: LAB.02.01 - Count solutions to an integer linear equation
Description
Given a positive integer n and n positive integers a1, a2, ..., an. 
Compute the number of positive integer solutions to the equation:
        a1X1 + a2X2 + . . . + anXn = M

Input
Dòng 1: n và M
Dòng 2: a1, a2, ..., an
Output
   Số nghiệm nguyên dương
Ví dụ
Input
3 5
1 1 1
Output
6

a + b + c = 5
V = [1, 2, 3, 4, 5]
a = [1, 1, 1]
x = [       ]

TRY(k):
   for v in [x,y]: 
     if check(v,k): 
        X[k] = v 
        update f[k] 
        if solution: 
           solution() 
        else: 
           TRY(k + 1)
        update back f[k]
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int M;
int sum = 0;
int Count = 0;
vector<int> a; //coeffi
vector<int> V; //applicant set
vector<int> x; //solution


void input() {
    cin >> n >> M;
    a.resize(n);
    for (int i = 0; i != n; i++) cin >> a[i];
    for (int i = 1; i <= M ; i++) V.push_back(i);
    x.resize(n, 0);
}

bool check(int v, int k) {
    return sum + a[k] * v <= M;
}

void update(int v, int k) {
    sum += v * a[k];
    x[k] = v;
}

void rollback(int v, int k) {
    sum -= v * a[k];
    x[k] = 0;
}

void solution() {
   if (sum == M) Count++;
}

void show(int v, int k) {
    cout << "Count = " << Count << endl;
    cout << "Sum = " << sum << endl;
    cout << "v = " << v << endl;
    cout << "a: "; 
    for (int i = 0; i != a.size(); i++) {
        if (i == k) cout << "[";
        cout << a[i];
        if (i == k) cout << "]";
        cout << "\t"; 
    }    
    cout << endl;
    cout << "x: "; 
    for (int i = 0; i != x.size(); i++) {
        if (i == k) cout << "[";
        cout << x[i];
        if (i == k) cout << "]";
        cout << "\t";
    }
    cout << endl;
    char chr; cin >> chr;
}

void TRY(int k) {
    for (int v : V) {
        if (!check(v, k)) continue;
        update(v, k);
        // show(v, k);
        if (k == n - 1) solution();
        else TRY(k + 1);    
        rollback(v, k);
    }
}

int main() {
    input();
    TRY(0);
    cout << Count << endl;
}