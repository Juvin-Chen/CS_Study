#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }
    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < m || ptr2 < n) {
        if (ptr1 == m) {
            cout << b[ptr2++] << " ";
        } else if (ptr2 == n) {
            cout << a[ptr1++] << " ";
        } else { // 若两个指针均未到达末尾
            if (a[ptr1] <= b[ptr2]) {
                cout << a[ptr1++] << " ";
            } else {
                cout << b[ptr2++] << " ";
            }
        }
    }
    return 0;
}