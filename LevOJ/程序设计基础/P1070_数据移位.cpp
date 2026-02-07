#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, move;
    cin >> n >> move;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = move % n; i < n; i++) {
        cout << a[i] << endl;
        if (i == n - 1) {
            for (int j = 0; j < move % n; j++) {
                cout << a[j] << endl;
            }
            break;
        }
    }
    return 0;
}
