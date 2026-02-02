/*
从 1 开始首先向右排列数字，遇到边界或者已经被占据的格子后，
按照 “右下左上” 的方向转向输出，直至输出至 n*n 为止。
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n, 0));

    int j = 0, k = 0;
    char dir = 'r'; // 初始方向是right

    for (int i = 1; i <= n * n; i++) {
        switch (dir) {
        case 'r':
            vec[j][k++] = i;
            if (k == n || vec[j][k] != 0) {
                k--;
                j++;
                dir = 'd';
            }
            break;
        case 'd':
            vec[j++][k] = i;
            if (j == n || vec[j][k] != 0) {
                j--;
                k--;
                dir = 'l';
            }
            break;
        case 'l':
            vec[j][k--] = i;
            if (k == -1 || vec[j][k] != 0) {
                k++;
                j--;
                dir = 'u';
            }
            break;
        case 'u':
            vec[j--][k] = i;
            if (vec[j][k] != 0) {
                j++;
                k++;
                dir = 'r';
            }
            break;
        }
    }

    for (auto v : vec) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}