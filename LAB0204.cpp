/*
LAB.02.04 - Lộ trình giao hàng cho xe tải có dung tải hạn chế
Mô tả:
Có một đội xe tải gồm K xe tải giống nhau, mỗi xe có dung tải là Q. Các xe tải này cần được lên lịch để giao 
các gói pepsi từ một kho trung tâm (điểm 0) đến các khách hàng 1, 2, ..., n. Mỗi khách hàng i yêu cầu d[i] gói. 
Khoảng cách từ vị trí i đến vị trí j được cho bởi ma trận khoảng cách c[i, j], với 0 ≤ i, j ≤ n.
Một giải pháp giao hàng là một tập hợp các lộ trình: mỗi xe tải sẽ có một lộ trình bắt đầu từ kho, 
ghé thăm một số khách hàng và quay lại kho để giao các gói pepsi theo yêu cầu, sao cho:
Mỗi khách hàng được ghé thăm bởi đúng một lộ trình
Tổng số gói yêu cầu của các khách hàng mà mỗi xe tải phục vụ không vượt quá dung tải của nó

Mục tiêu:
Tìm giải pháp có tổng quãng đường di chuyển tối thiểu.

Lưu ý:
Có thể có trường hợp một xe tải không ghé thăm khách hàng nào (lộ trình rỗng).
Thứ tự các khách hàng trong một lộ trình là quan trọng, 
ví dụ: các lộ trình 0 -> 1 -> 2 -> 3 -> 0 và 0 -> 3 -> 2 -> 1 -> 0 là khác nhau.

Dữ liệu vào (Input):
Dòng 1: Ba số nguyên n, K, Q (2 ≤ n ≤ 12, 1 ≤ K ≤ 5, 1 ≤ Q ≤ 50)
Dòng 2: d[1], d[2], ..., d[n] (1 ≤ d[i] ≤ 10) — yêu cầu của mỗi khách hàng.
Dòng i+3 (i = 0,...,n): Dòng thứ i của ma trận khoảng cách c (1 ≤ c[i, j] ≤ 30)

Kết quả (Output):
In ra tổng quãng đường di chuyển tối thiểu.

Ví dụ:
Input:
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0
Output:
70

Cấu trúc lưu trữ: 
x[i] lộ trình của K xe tải: 
    + Lộ trình của một xe tải được đánh dấu là 0, kết thúc là 0 => Có K + 1 số 0 trong chuỗi và K - 1 số 0 ở giữa
    + Độ dài của chuỗi là n + K + 1
M[i] mảng đánh dấu những khách hàng đã giao
c[i][j] chi phí đi từ thành phố i đến j
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX 50

using namespace std;

ll n, K, Q;
ll d[MAX], M[MAX];
ll x[MAX];
ll c[MAX][MAX];
ll c_min = 1e9;
ll best = 1e9;
ll weight = 0;
ll total_cost = 0;
ll Count_zero = 0;
ll total_d = 0;
ll served = 0;
void input() {
    cin >> n >> K >> Q;
    for (ll i = 1; i <= n; i++) {
        cin >> d[i];
        total_d += d[i];
    }
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j) c_min = min(c_min, c[i][j]);
        }
    }
}

bool check(ll v, ll k) {
    if (v == 0 && Count_zero >= K - 1) return false;                         //nếu đã đủ xe
    if (v == 0 && (total_d - served)/(K - Count_zero - 1) > Q) return false; //nếu còn quá ít xe để hoàn thành nhiệm vụ
    if (v != 0) {
        if (M[v]) return false;                                              //nếu đã giao
        if ((total_d - served - d[v]) / (K - Count_zero) > Q) return false;  //nếu trọng tải quá bé
        if (weight + d[v] > Q) return false;                                 //nếu vượt quá tải
        if (total_cost + c_min * (n + K + 1 - k) >= best) return false;      //cắt nhánh
    }
    return true;
}

void TRY(ll k) {
    for (ll v = 0; v <= n; v++) {
        if (check(v, k)) {
            ll curr_weight = weight;
            ll curr_served = served;
            //update
            if (v == 0) {
                weight = 0;
                Count_zero++;
            } else {
                M[v] = 1;
                weight += d[v]; 
                served += d[v];
            }
            x[k] = v;
            total_cost += c[x[k - 1]][v]; 

            if (k < n + K - 1) { //không cần xét phần tử cuối vì nó bằng 0
                TRY(k + 1);
            } else {
                //solution
                best = min(total_cost + c[x[n + K - 1]][0], best);
            }

            //rollback
            weight = curr_weight;
            served = curr_served;
            if (v == 0) Count_zero--;
            M[v] = 0;
            total_cost -= c[x[k - 1]][v]; 
        }

    }
}

ll cal_cost(ll arr[]) {
    ll cost = 0;
    for (ll i = 1; i <= n + K; i++) {
        cost += c[arr[i-1]][arr[i]];
    }
    return cost;
}

int main() {
    input();
    TRY(1);
    cout << best << endl;
    return 0;
}
