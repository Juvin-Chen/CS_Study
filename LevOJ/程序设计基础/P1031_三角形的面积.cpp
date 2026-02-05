#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b, c;
    double p = 0.0, S = 0.0;
    cin >> a >> b >> c;

    if (!a || !b || !c) {
        cout << -1 << endl;
    } else if (a + b > c && a + c > b && b + c > a) {
        p = (a + b + c) / 2;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << fixed << setprecision(2) << S << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}