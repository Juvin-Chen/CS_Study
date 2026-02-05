#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> b(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[j][i]; // 直接按照转置规则进行赋值
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n - 1)
                cout << b[i][j] << " ";
            else
                cout << b[i][j] << "\n";
        }
    }
    return 0;
}
