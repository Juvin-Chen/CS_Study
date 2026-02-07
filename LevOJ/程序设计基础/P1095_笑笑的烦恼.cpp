#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<vector<int>> res(T, vector<int>(4, 0));
    vector<double> average(T);
    for (int i = 0; i < T; i++) {
        int max = 0, min = 100, score, cnt = 0;
        while (1) {
            cin >> score;
            if (score == -1)
                break;
            cnt++;
            if (score > max)
                max = score;
            if (score < min)
                min = score;
            res[i][3] += score;
        }
        res[i][0] = cnt;
        res[i][1] = max;
        res[i][2] = min;
        average[i] = res[i][3] * 1.0 / cnt;
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 3; j++) {
            cout << res[i][j] << endl;
        }
        cout << fixed << setprecision(1) << average[i] << endl;
    }
    return 0;
}