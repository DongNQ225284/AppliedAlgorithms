/*
Problem: LAB.01.02 - Maze
Description
Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM.
Trong đó A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. 
Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống. 
Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.

Input
Dòng 1: ghi 4 số nguyên dương n, m, r, c.
Trong đó n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A

Output
Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.


Cấu trúc lưu trữ: 
Tạo một struct để đóng gói dữ liệu tọa độ (x, y) và số bước di chuyển tính từ thời gian ban đầu
Khi di chuyển tới một ô mới, tọa độ (x, y) thay đổi và số bước cộng thêm 1

A[i][j] thể hiện ma trận, đồng thời thể hiện những vị trí đã di chuyển
Sử dụng queue Q để thực hiện BFS
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

//cấu trúc lưu trữ của trạng thái hiện tại
struct Data {
    ll x, y, c;
    Data(ll x, ll y, ll c = 0) {
        this->x = x; //tọa độ x
        this->y = y; //tọa độ y
        this->c = c; //số bước đi tính từ vị trí ban đầu
    }
};

//khi di chuyển tới một hướng dir
Data operator+ (Data pos, pair<ll, ll> dir) {
    ll x = pos.x + dir.first; 
    ll y = pos.y + dir.second;
    ll c = pos.c + 1;
    return Data(x, y, c);
}

int n, m, r, c;
ll A[1000][1000]; //mảng đánh dấu những ô đã đi qua

//hướng di chuyển: Trái, Lên, Phải, Xuống
pair<ll,ll> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
queue<Data> Q;

void input() {
    cin >> n >> m >> r >> c;
    for (ll i = 0; i != n; i++) {
        for (ll j = 0; j != m; j++) {
            cin >> A[i][j];
        }
    }
}

//Sử dụng BFS để tìm đường đi
ll solve() {
    Data pos(r - 1, c - 1, 1);
    Q.push(pos);
    while (!Q.empty()) {
        Data p = Q.front();
        for (auto v : dir) {
            Data next = p + v;
            if (A[next.x][next.y] == 1) continue;
            A[next.x][next.y] = 1;
            Q.push(next);
            if (next.x == 0 || next.x == n - 1 || next.y == 0 || next.y == m - 1) return next.c;
        }
        Q.pop();
    }
    return -1;
}
int main() {
    input();
    cout << solve() << endl;
    return 0;
}