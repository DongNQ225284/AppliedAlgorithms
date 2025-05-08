/*
Problem: LAB.01.04 - Largest black subrectangle
Description
A Rectangle of size n x mis divided into unit-square 1 x 1 with two colors black and white. 
The rectangle is represented by a matrix A(nx m) in which A(i, j) = 1 means that the unit-square at row i, 
column j is black and A(i, j) = 0 means that the unit-square at row icolumn jis white.
Find the sub-rectangle of the given rectangle containing only black unit-squares such that the area is maximal.
Input
•Line 1: contains 2 positive integers nand m(1 <= n, m<= 1000)
•Line i+1 (i= 1,…, n): contains the ith of the matrix A
Output
Write the area of the sub-rectangle found.

Example 
Input
4 4
0 1 1 1
1 1 1 0
1 1 0 0
1 1 1 0
Output
6
---------------------------
Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. 
Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, 
cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
Dữ liệu
· Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 1000)
· Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
Kết quả
· Ghi ra diện tích của hình chữ nhật lớn nhất tìm được
Ví dụ
Dữ liệu
4 4
0 1 1 1
1 1 1 0
1 1 0 0
1 1 1 0
Kết quả
6
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX 1005
using namespace std;

ll n, m;
vector<vector<ll>> A;

void input() {
    cin >> n >> m;
    A.resize(n, vector<ll>(m));      
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) cin >> A[i][j]; 
    }
}

ll solve_sub(vector<ll> h) {
    vector<ll> L(h.size());
    vector<ll> R(h.size());
    stack<ll> S;
    S.push(0);
    for (ll i = 1; i < h.size(); i++) {
        if (h[i] > h[S.top()]) S.push(i);
        else S.pop();
        L[i] = S.top();
    }
    last = h.size() - 1;
    R[last] = last;
    for (ll i = h.size() - 2; i >= 0; i--) {
        if (h[i] <= h[last]) R[i] = last;
        else {
            last = i;
            R[i] = i;
        }
    }
    cout << "L: "; for (auto val : L) cout << val << " "; cout << endl;
    cout << "R: "; for (auto val : R) cout << val << " "; cout << endl; 
 
    ll bestArea = 0;
    for (ll i = 0; i < h.size(); i++) {
        bestArea = max(bestArea, h[i] * (R[i] - L[i] + 1));
    }
    return bestArea;
}


ll solve() {

}
int main() {
    //input();
    vector<ll> h = {1, 2, 3, 2, 5};
    cout << solve_sub(h);
    return 0;
}