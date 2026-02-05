#include <iostream>

using namespace std;

int main() {
    int n, num, res;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (i == (n + 1) / 2)
            res = num;
    }
    cout << res;
    return 0;
}