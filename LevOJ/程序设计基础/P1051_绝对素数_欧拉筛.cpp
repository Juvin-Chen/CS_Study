/**
 * 如果一个正整数是素数，它的反位数也是素数，这称这样的数称为绝对素数。是，输出 1，否，输出 0
 * n表示数据的组数，接下来的 n 行每行一个不大于100000的正整数，需要判断是否为绝对素数
 */

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;
int primes[MAX];
bool is_composite[MAX];
int cnt = 0;

// 预处理合数表
void make() {
    memset(is_composite, 0, sizeof(is_composite));
    is_composite[0] = is_composite[1] = true;
    for (int i = 2; i <= MAX; i++) {
        if (!is_composite[i])
            primes[cnt++] = i;
        for (int j = 0; j < cnt && primes[j] * i <= MAX; j++) {
            is_composite[i * primes[j]] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int reverse_num(int n) {
    int new_num = 0, t;
    while (n > 0) {
        t = n % 10;
        n /= 10;
        new_num = new_num * 10 + t;
    }
    return new_num;
}
int main() {
    make();
    int n, num;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (is_composite[num] || is_composite[reverse_num(num)])
            res[i] = 0;
        else
            res[i] = 1;
    }
    for (auto i : res)
        cout << i << endl;
    return 0;
}