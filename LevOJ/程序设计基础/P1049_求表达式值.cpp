/**
 * 编程计算表达式 x+a%3*(int)(x+y)%2/4 的值 输出到小数点后六位。
 */

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int a;
    double x, y;
    cin >> a >> x >> y;
    cout << fixed << setprecision(6) << x + a % 3 * (int)(x + y) % 2 / 4;
    return 0;
}