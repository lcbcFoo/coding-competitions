#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> ns = vector<int>(N);
        for (int i = 0; i < N; ++i) {
            cin >> ns[i];
        }
        if (N == 1) {
            if (ns[0] > 1) {
                cout << "NO" << endl;
                continue;
            }
            else {
                cout << "YES" << endl;
                continue;
            }
        }
        int max_n = max(ns[0], ns[1]);
        int min_n = min(ns[0], ns[1]);
        for (int i = 2; i < N; ++i) {
            if (ns[i] > max_n) {
                min_n = max_n;
                max_n = ns[i];
            }
            else if (ns[i] > min_n) {
                min_n = ns[i];
            }
        }
        if (abs(max_n - min_n) > 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}
