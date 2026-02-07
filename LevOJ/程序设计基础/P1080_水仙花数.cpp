#include <iostream>
#include <string>
using namespace std;

int fun(char c) {
    int num = c - '0';
    return num * num * num;
}

int main() {
    for (int i = 100; i < 1000; i++) {
        string str = to_string(i);
        if (fun(str[0]) + fun(str[1]) + fun(str[2]) == i) {
            cout << i << endl;
        }
    }
    return 0;
}