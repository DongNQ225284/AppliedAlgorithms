/*
LAB.01.03 - Truy vấn giá trị nhỏ nhất trong đoạn
Mô tả:
Cho một dãy gồm n số nguyên: a₀, a₁, ..., aₙ₋₁.
Gọi rmq(i, j) là giá trị nhỏ nhất trong đoạn con aᵢ, aᵢ₊₁, ..., aⱼ.

Bạn được cung cấp m cặp chỉ số (i₁, j₁), ..., (iₘ, jₘ), yêu cầu tính tổng:
Q = rmq(i₁, j₁) + rmq(i₂, j₂) + ... + rmq(iₘ, jₘ)

Input:
Dòng 1: Một số nguyên n (1 ≤ n ≤ 10⁶)
Dòng 2: n số nguyên a₀, a₁, ..., aₙ₋₁ (1 ≤ aᵢ ≤ 10⁶)
Dòng 3: Một số nguyên m (1 ≤ m ≤ 10⁶)

Tiếp theo m dòng: Mỗi dòng gồm hai số nguyên iₖ và jₖ (0 ≤ iₖ < jₖ < n), tương ứng với mỗi truy vấn

Output:
In ra tổng giá trị Q tính được.

Ví dụ
Input:
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10
Output:
6
*/
#include <bits/stdc++.h>
#define ll long long
#define MAX 4e6
using namespace std;

ll n, m;
vector<ll> a, T; //T là cây lưu trữ, tổ chức dưới dạng mảng

void input() {
    cin >> n;
    a.resize(n);
    T.resize(4 * n);
    for (ll i = 0; i != n; i++) cin >> a[i];
}

//xây dựng Segment Tree
void build(ll id, ll l, ll r) //id: vị trí của node hiện tại, <l, r> đoạn mà node id quản lý 
{
    if (l == r) //Nếu là node lá thực hiện lưu 
    {
        T[id] = a[l];
        return;
    } 
    //Nếu chưa phải node lá
    ll mid = (l + r) / 2;
    build(2 * id, l, mid); //Xây dựng nhánh bên trái, đoạn <l, mid> do node có vị trí 2*id quản lý
    build(2 * id + 1, mid + 1, r); //Xây dựng nhánh bên trái, đoạn <mid + 1, r> do node có vị trí 2*id+1 quản lý
    //Xây dựng xong nhánh trái và phải
    T[id] = min(T[2 * id], T[2 * id + 1]); //Cập nhật giá trị ở node hiện tại 
}

/*
Ví dụ: 
Node [id|l r|value]: Node có giá trị value, vị trí id, quản lý đoạn [l, r]
Mảng a: [2 1 4 3]
                       [1|0 3|1]
                    /             \
       [2|0 1|1]                    [3|2 3|3]
         /    \                      /     \
[4|0 0|2]     [5|1 1|1]     [6|2 2]|4]     [7|3 3]|3]
*/

//Truy vấn trên cây
ll query(ll id, ll l, ll r, ll u, ll v) //id: Vị trí node, <l, r> đoạn mà node quản lý, <u, v> đoạn truy vấn
{
    if (l > v || r < u) return MAX;  //<l, r> không giao với <u, v> trả về MAX
    if (l >= u && r <= v) return T[id]; //<l, r> nằm bên trong <u, v> trả về giá trị node id quản lý đoạn <l, r>
    //<l, r> giao một phần với <u, v>
    ll mid = (l + r) / 2;
    ll lval = query(2 * id, l, mid, u, v); //giá trị nhánh trái
    ll rval = query(2 * id + 1, mid + 1, r, u, v); //giá tị nhánh phải
    return min(lval, rval); 
}

//cập nhật giá trị
void update(ll id, ll l, ll r, ll i, ll val) //id: vị trí node trong cây, <l, r> đoạn node id quản lý, i: vị trí của phần tử cần cập nhật trong mảng, val: giá trị cập nhật
{
    if (i < l || i > r) return; //i không thuộc <l, r>
    if (l == r) //nếu là node lá --> cần update 
    {
        T[l] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (i <= mid) //nếu i thuộc nhánh trái 
        update(2 * id, l, mid, i, val); //cập nhật nhánh trái
    else //nếu i thuộc nhánh phải
        update(2 * id + 1, mid + 1, r, i, val); //cập nhật nhánh phải 
    T[id] = min(T[2 * id], T[2 * id + 1]); //cập nhật node id
}

void solve() {
    build(1, 0, n - 1);
    cin >> m;
    ll sum = 0;
    while(m--) {
        ll i, j; cin >> i >> j;
        sum += query(1, 0, n - 1, i, j);
    }
    cout << sum << endl;
}
int main() {
    input();
    solve();
    return 0;
}