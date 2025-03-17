/*
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
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<bool>> matrix;
    vector<char> best_path;
    vector<char> path;
    bool showPath;
    bool debug;
    int step;
    int best;
    int M, N;
public:
    void init(vector<vector<bool>> matrix) {
        this->step = 0;
        this->best = INT_MAX;
        this->matrix = matrix;
        this->N = matrix.size();
        this->M = matrix[0].size();
    }

    void Try(int i, int j) { 
        if (debug) print(i, j);
        if (step > best) return;
        if (i == 0 || i == N - 1|| j == 0 || j == M - 1) {
            if (best > step) {
                best_path = path;
                best = step;
            }
            if (debug) {
                cout << "update best" << endl;
                show();
            }
            return;
        }
        if (!matrix[i + 1][j]) {
            step++;
            path.push_back('D');
            matrix[i][j] = true;
            Try(i + 1, j);
            matrix[i][j] = false;
            path.pop_back();
            step--;
        }
        if (!matrix[i - 1][j]) {
            step++;
            matrix[i][j] = true;
            path.push_back('U');
            Try(i - 1, j);
            matrix[i][j] = false;
            path.pop_back();
            step--;
        } 
        if (!matrix[i][j - 1]) {
            step++;
            matrix[i][j] = true;
            path.push_back('L');
            Try(i, j - 1);
            matrix[i][j] = false;
            path.pop_back();
            step--;
        }
        if (!matrix[i][j + 1]) {
            step++;
            matrix[i][j] = true;
            path.push_back('R');
            Try(i, j + 1);
            matrix[i][j] = false;
            path.pop_back();
            step--;
        }
        if (debug) {
            printf("rollback (%d, %d)\n", i, j);
        }
    }
    void solve(int r, int c, bool debug = false, bool showPath = false) {
        this->debug = debug;
        this->showPath = showPath;
        Try(r, c);
    }
    void print(int x, int y) {
        printf("possiton: (%d, %d)\tstep = %d\tbest = %d\n", x, y, step, best);
        printf("path:\t\t"); for(char chr : this->path) cout << chr << " "; cout << endl;
        printf("best_path:\t"); for(char chr : this->best_path) cout << chr << " "; cout << endl;
        
        for (int i = 0; i != N; i++) {
            for (int j = 0; j != M; j++) { 
                if (i != x || j != y) cout << matrix[i][j] << " ";
                else if (matrix[i][j]) cout << "error" << " ";
                else cout << "x" << " ";
            }
            cout << endl;
        }
        if (step > best) cout << "stop! rollback" << endl;
        printf("***");
        char chr; cin >> chr;
        cout << endl;
    }
    void show() {
        if (showPath) {
            printf("path: ");
            for (char chr : this->best_path) cout << chr << " "; cout << endl; 
        }
        if (best == INT_MAX) best = -2;
        cout << best + 1 << endl;
    }
};

int main() {
    ifstream file("LAB0102Maze.txt");
    int n, m, r, c;
    file >> n >> m >> r >> c;
    vector<vector<bool>> a;
    for (int i = 0; i != n; i++) {
        vector<bool> row;
        for (int j = 0; j != m; j++) {
            bool e;  file >> e;
            row.push_back(e);
        }
        a.push_back(row);
    }
    // int n, m, r, c;
    // cin >> n >> m >> r >> c;
    // vector<vector<bool>> a;
    // for (int i = 0; i != n; i++) {
    //     vector<bool> row;
    //     for (int j = 0; j != m; j++) {
    //         bool e;  cin >> e;
    //         row.push_back(e);
    //     }
    //     a.push_back(row);
    // }
    bool debug = false;
    bool showPath = false;
    Solution solution;
    solution.init(a);
    solution.solve(r - 1, c - 1, debug, showPath);
    solution.show();
    return 0;
}