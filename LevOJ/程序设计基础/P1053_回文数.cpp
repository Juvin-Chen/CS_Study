#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    cin >> num;
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] != num[num.size() - 1 - i]) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}