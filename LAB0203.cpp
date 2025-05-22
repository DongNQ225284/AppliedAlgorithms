/*
LAB.02.03 - Phân công khóa học cân bằng
Mô tả:
Vào đầu học kỳ, trưởng khoa của một khoa khoa học máy tính phải phân công các khóa học cho các giảng viên một cách cân bằng. 
Khoa D có m giảng viên T = {1, 2, ..., m} và n khóa học C = {1, 2, ..., n}.
Mỗi giảng viên t ∈ T có một danh sách ưu tiên là các khóa học mà giảng viên đó có thể giảng dạy, 
tùy thuộc vào chuyên môn của họ.
Chúng ta cũng biết một danh sách các cặp khóa học mâu thuẫn không thể giao cho cùng một giảng viên, 
vì những khóa học này đã được lên lịch trong cùng một thời gian biểu.
Tải của một giảng viên là số lượng khóa học được giao cho giảng viên đó.

Câu hỏi là làm thế nào để phân công n khóa học cho m giảng viên sao cho mỗi khóa học được giao cho:
+ Một giảng viên thuộc danh sách ưu tiên của giảng viên đó, 
+ Không có hai khóa học mâu thuẫn được giao cho cùng một giảng viên, 
+ Tải cao nhất của giảng viên là nhỏ nhất.

Dữ liệu vào (Input):
Dòng 1: Hai số nguyên m và n (1 ≤ m ≤ 10, 1 ≤ n ≤ 30)
Dòng i+1 (i=1, 2, ..., m): Mỗi dòng chứa một số nguyên dương k và k số nguyên dương chỉ các khóa học mà 
giảng viên i có thể giảng dạy (∀i = 1, ..., m)
Dòng m+2: Một số nguyên dương k (là số cặp khóa học mâu thuẫn)
Dòng i+m+k: Mỗi dòng chứa hai số nguyên i và j chỉ hai khóa học mâu thuẫn (∀i = 1, ..., k)

Kết quả (Output):
In ra một số duy nhất là tải cao nhất của giảng viên trong giải pháp tìm được. Nếu không thể tìm được giải pháp, in ra -1.

Ví dụ:
Input:
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12
Output:
3


Cấu trúc lưu trữ:
ll res: Kết quả của bài toán
ll x[i]: Khóa học i sẽ được phân cho giáo viên x[i] (với x[i] thuộc [1, m])
ll load[i]: Số môn học được phân cho giáo viên i
ll Conflict[i][j]: nếu khóa học i và j mẫu thuẫn conflict[i][j] = conflict[j][i] = 1, ngược lại thì conflict[i][j] = conflict[j][i] = 0 
vector<ll> T[i]: Dang sách các giáo viên dạy môn i

Ràng buộc: 
+ Danh sách các môn giáo viên x[i] dạy phải chứa i, điều này được đảm bảo trong T[i]
+ Các môn giao cho cùng một giáo viên không bị mâu thuẫn
+ Tải lớn nhất phải nhỏ nhất 

*/
#include <bits/stdc++.h>
#define ll long long
#define MAX 50
using namespace std;

ll m, n, k;
ll best = MAX;
ll max_load = 0;
ll x[MAX];
ll load[MAX];
vector<ll> T[MAX];
ll conflict[MAX][MAX];

void input() {
    cin >> m >> n;
    for (ll t = 1; t <= m; t++) {
        ll k; cin >> k;
        for (ll i = 1; i <= k; i++) {
            ll c; cin >> c;
            T[c].push_back(t);
        }
    }
    cin >> k;
    for (ll i = 1; i <= k; i++) {
        ll f, s; cin >> f >> s;
        conflict[f][s] = conflict[s][f] = 1;
    }
}

bool check(ll t, ll k) {
    for (ll i = 1; i < k; i++) {                            //duyệt các môn đã phân cho giáo viên trước đó
        if (x[i] == t && conflict[i][k]) return false;          //nếu giáo viên đã dạy môn i và môn i bị xung đột với môn hiện tại là k
    }
    return true;
}

void TRY(ll k) {
    for (ll i = 0; i < T[k].size(); i++) {
        ll t = T[k][i];
        if (check(t, k)) {
            //update
            x[k] = t;
            load[t]++;
            ll curr_max_load = max_load;
            max_load = max(max_load, load[t]);
            
            if (k < n) TRY(k + 1);
            else {
                //solution
                best = min(best, max_load);
            }

            //rollback
            load[t]--;
            max_load = curr_max_load;
        }
    }
}

int main() {
    input();
    TRY(1);
    cout << best << endl;
    return 0;
}

