/**
 * 如果一个正整数是素数，它的反位数也是素数，这称这样的数称为绝对素数。是，输出 1，否，输出 0
 * n表示数据的组数，接下来的 n 行每行一个不大于100000的正整数，需要判断是否为绝对素数
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int reverse_num(int n) {
    string num = to_string(n);
    reverse(num.begin(), num.end());
    return stoi(num);
}

bool is_prime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
int main() {
    int n, num;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (is_prime(num) && is_prime(reverse_num(num)))
            res[i] = 1;
        else
            res[i] = 0;
    }
    for (auto i : res)
        cout << i << endl;
    return 0;
}