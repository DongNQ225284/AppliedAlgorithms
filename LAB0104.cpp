/*
Problem: LAB.01.04 - Largest black subrectangle
Mô tả:
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
ll M[MAX][MAX];

void input() {
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) cin >> M[i][j]; 
    }
}

//O(n^4)
class Bad {
public:
    struct Point {
        ll x, y;
        Point(ll _x, ll _y) {
            this->x = _x;
            this->y = _y;
        }

        void show() {
            printf("(%lld, %lld) ", this->x, this->y);
        }
    };

    bool check(Point A, Point B) {
        ll s_x = min(A.x, B.x);
        ll e_x = max(A.x, B.x);
        ll s_y = min(A.y, B.y);
        ll e_y = max(A.y, B.y);

        for (ll i = s_y; i <= e_y; i++) {
            for (ll j = s_x; j <= e_x; j++) {
                if (!M[i][j]) return false;
            }
        }
        return true;
    }

    ll cal_area(Point A, Point B) {
        if (!check(A, B)) return 0;
        return (abs(A.x - B.x) + 1) * (abs(A.y - B.y) + 1);
    }

    ll solve() {
        ll best_area = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (!M[i][j]) continue;
                Point A(i, j);
                for (ll k = 0; k < n; k++) {
                    for (ll l = 0; l < m; l++) {
                        if (!M[k][l]) continue;
                        Point B(k, l);
                        ll area = cal_area(A, B);
                        best_area = max(best_area, area);
                    }
                }
            }
        }
        return best_area;
    }
};

//O(n^3)
class Good {
/*
Bài toán con:
Tìm hình chữ nhật có diện tích lớn nhất của đồ thị hình cột
Đầu vào: Dãy độ cao các cột
Đầu ra: Diện tích lớn nhất
Ví dụ:
Đầu vào:
1 3 4 2
Đầu ra:
6
Giải thích: 
Vẽ
    1   
  1 1  
1 1 1 1
1 1 1 1


*/
public:
    ll h[MAX];
    //debug
    void print() {
        for (ll i = 0; i < m; i++) cout << h[i] << " "; cout << endl;
    }
    //test
    void input() {
        cin >> m;
        for (ll i = 0; i < m; i++) cin >> h[i];
    }

    //O(n)
    /*
    Tìm vị trí bắt đầu s, và vị trí kết thúc e, thỏa mãn h[j] >= h[i] với mọi j = s..e
    Khi đó chiều cao, chiều rộng hình chữ nhật là h[i] và (e - s + 1)
    */
    ll cal_area(ll i) {
        ll s, e;
        s = e = i;
        while(true) {
            if (s < 0 || h[s] < h[i]) break; 
            s--;
        }
        s++;
        while(true) {
            if (e == m || h[e] < h[i]) break;
            e++;
        }
        e--;
        return h[i] * (e - s + 1);
    }
    //O(n^2)
    ll sub_solve() {
        ll best_area = 0;
        for (ll i = 0; i < m; i++) {
            best_area = max(best_area, cal_area(i));
        }
        return best_area;
    }

    //chuẩn hóa h[]
    void stand(ll arr[]) {
        for (ll i = 0; i < m; i++) {
            if (arr[i]) h[i]++;
            else h[i] = 0;
        }
    }

    //O(n^3)
    ll solve() {
        ll best_area = 0;
        for (ll i = 0; i < n; i++) {
            stand(M[i]);
            ll area = sub_solve();
            best_area = max(best_area, area);
        }
        return best_area;
    }
};

//O(n^2)
class Best {
/*
Tối ưu phương pháp giải bài toán con đã đề cập bên trên
Sử dụng mảng s[], e[] để lưu vị trí bắt đầu và kết thúc
*/
public:
    ll h[MAX], s[MAX], e[MAX];

    //test
    void input() {
        cin >> m;
        for (ll i = 0; i < m; i++) cin >> h[i];
    }

    //debug
    void print(ll arr[]) {
        for (ll i = 0; i < m; i++) cout << arr[i] << "\t"; cout << endl;
    }

    //O(n)
    void init() {
        s[0] = 0;
        for (ll i = 1; i < m; i++) {
            ll idx = i - 1;
            while(true) {
                if (idx < 0 || h[idx] < h[i]) {
                    s[i] = idx + 1;
                    break;
                }
                if (h[idx] >= h[i]) {
                    s[i] = s[idx];
                    break;
                }
                idx--;
            }
        }

        e[m - 1] = m - 1;
        for (ll i = m - 2; i >= 0; i--) {
            ll idx = i + 1;
            while (true) {
                if (idx == m || h[idx] < h[i]) {
                    e[i] = idx - 1;
                    break;
                }
                if (h[idx] >= h[i]) {
                    e[i] = e[idx];
                    break;
                }
                idx++;
            }
        }
    }

    //O(n)
    ll sub_solve() {
        init();
        ll best_area = 0;
        for (ll i = 0; i < m; i++) {
            best_area = max(best_area, h[i] * (e[i] - s[i] + 1));
        }
        return best_area;
    }

    //O(n)
    void stand(ll arr[]) {
        for (ll i = 0; i < m; i++) {
            if (arr[i]) h[i]++;
            else h[i] = 0;
        }
    }

    //O(n^2)
    ll solve() {
        ll best_area = 0;
        for (ll i = 0; i < n; i++) {
            stand(M[i]); //O(n)
            ll area = sub_solve(); //O(n)
            best_area = max(best_area, area);

            print(h);
            print(s);
            print(e);
            cout << area << endl;
            char chr; cin >> chr;
        }
        return best_area;
    }
};

int main() {
    //input();
    //cout << Bad().solve() << endl;
    
    //input();
    //cout << Good().solve() << endl;
    
    input();
    cout << endl;
    cout << Best().solve() << endl;

    return 0;
}

