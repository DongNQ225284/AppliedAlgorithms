/*
LAB.05.01 - Tính số thành phần liên thông mạnh của đồ thị có hướng

Mô tả:
Cho một đồ thị có hướng G = (V, E), trong đó V = {1, ..., N} là tập các đỉnh và E là tập gồm M cung (cạnh có hướng). 
Hãy tính số lượng thành phần liên thông mạnh trong đồ thị G.

Dữ liệu vào:
Dòng 1: Hai số nguyên dương N và M (1 <= N <= 10^5, 1 <= M <= 10^6)
M dòng tiếp theo, mỗi dòng gồm hai số nguyên u và v, biểu diễn cung có hướng từ đỉnh u đến đỉnh v

Dữ liệu ra:
Ghi ra số lượng thành phần liên thông mạnh của đồ thị G

Ví dụ:
Dữ liệu vào:
8 13
1 2
1 8
2 3
2 6
3 6
4 3
4 6
5 4
6 5
7 1
7 2
7 6
8 7
Dữ liệu ra:
3
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX = 100005;
vector<ll> G[MAX], g[MAX];
vector<ll> S;

ll V1[MAX], V2[MAX]; // Mảng đánh dấu visited
ll N, M, Count = 0;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v); // Đồ thị gốc
        g[v].push_back(u); // Đồ thị chuyển vị
    }
}

void dfs1(ll v) {
    V1[v] = true;
    for (ll u : G[v]) {
        if (!V1[u]) dfs1(u);
    }
    S.push_back(v);
}

void dfs2(ll v) {
    V2[v] = true;
    for (ll u : g[v]) {
        if (!V2[u]) dfs2(u);
    }
}

int main() {
    input();
    for (ll i = 1; i <= N; i++) {
        if (!V1[i]) dfs1(i);
    }
    for (ll i = S.size() - 1; i >= 0; i--) {
        if (!V2[S[i]]) {
            dfs2(S[i]);
            Count++;
        }
    }
    cout << Count << endl;
    return 0;
}