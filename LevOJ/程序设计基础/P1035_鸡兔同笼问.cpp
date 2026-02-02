#include <iostream>

using namespace std;

int main() {
    int head, leg;
    while (cin >> head >> leg) {
        double chicken = (4 * head - leg) / 2.0;
        if (chicken == (int)chicken && chicken >= 0 && (head - chicken) >= 0) {
            cout << chicken << " " << (head - chicken);
        } else {
            cout << -1 << " " << -1;
        }
        cout << endl;
    }
    return 0;
}