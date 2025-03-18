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
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    queue<tuple<int, int, vector<char>>> Q; // <i, j, path>
    vector<vector<bool>> matrix;
    vector<char> best_path;
    int n, m, r, c;
    int best;
    
public:
    void init(bool inputFromFile = false) {
        if (inputFromFile) {
            ifstream file("LAB0102.txt");
            file >> n >> m >> r >> c;
            for (int i = 0; i != n; i++) {
                vector<bool> row;
                for (int j = 0; j != m; j++) {
                    bool e;  file >> e;
                    row.push_back(e);
                }
                matrix.push_back(row);
            }
        } else {
            cin >> n >> m >> r >> c;
            for (int i = 0; i != n; i++) {
                vector<bool> row;
                for (int j = 0; j != m; j++) {
                    bool e;  cin >> e;
                    row.push_back(e);
                }
                matrix.push_back(row);
            }
        }
        r--; c--; //corection
    }
    
    void solve(bool debug = false) {
        vector<char> path;
        Q.push(make_tuple(r, c, path));
        matrix[r][c] = true;
        while(!Q.empty()) {
            tuple<int, int, vector<char>> e = Q.front(); Q.pop();
            int i = get<0>(e);
            int j = get<1>(e);
            vector<char> path = get<2>(e);
            if (debug) print(i, j);
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                best = path.size() + 1;
                best_path = path;
                return;
            }
            if (!matrix[i - 1][j]) {
                matrix[i - 1][j] = true;
                vector<char> path_copy = path;
                path_copy.push_back('U');
                Q.push(make_tuple(i - 1, j, path_copy));
            }
            if (!matrix[i + 1][j]) {
                matrix[i + 1][j] = true;
                vector<char> path_copy = path;
                path_copy.push_back('D');
                Q.push(make_tuple(i + 1, j, path_copy));
            }
            if (!matrix[i][j - 1]) {
                matrix[i][j - 1] = true;
                vector<char> path_copy = path;
                path_copy.push_back('L');
                Q.push(make_tuple(i, j - 1, path_copy));
            }
            if (!matrix[i][j + 1]) {
                matrix[i][j + 1] = true;
                vector<char> path_copy = path;
                path_copy.push_back('R');
                Q.push(make_tuple(i, j + 1, path_copy));
            }
        }
        best = -1;
    }

    void print(int x, int y) {
        printf("possiton: (%d, %d)\n", x, y);
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != m; j++) { 
                if (i == x && j == y) cout << "[";
                cout << matrix[i][j];
                if (i == x && j == y) cout << "]";
                cout << "\t";
            }
            cout << endl;
        }
        printf("***");
        char chr; cin >> chr;
        cout << endl;
    }
    void show(bool showPath = false) {
        if (showPath) {
            cout << "path: "; 
            for (char chr : best_path) cout << chr << " "; 
            cout << endl;
        }
        cout << best << endl;
    }
};

int main() {
    Solution solution;
    bool inputFromFile = true; //set
    bool debug = false; //debug?
    bool showPath = false; //showPath?
    bool clock = false; //want to measure time?
    
    solution.init(inputFromFile);
    auto start = chrono::high_resolution_clock::now();
    solution.solve(debug);
    solution.show(showPath);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    if (clock) cout << "Runtimes: " << 1000 * elapsed.count() << "ms\n";
    return 0;
}