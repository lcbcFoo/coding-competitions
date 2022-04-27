#include <functional>
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
        bool has_odd = false;
        bool has_even = false;
        bool has_zero = false;
        bool has_one = false;
        bool all_equals = true;
        bool has_consecutive = false;
        bool has_two = false;
        vector<int> ns = vector<int>(N);
        for (int i = 0; i < N; ++i) {
            int n;
            cin >> n;
            ns[i] = n;
            has_odd |= n % 2 == 1;
            has_even |= n % 2 == 0;
            has_zero |= n == 0;
            has_one |= n == 1;
            has_two |= n == 2;
        }
        sort(ns.begin(), ns.end(), less<int>());
        int n = ns[0];
        for(int i = 1; i < N; ++i) {
            if (ns[i] != n) {
                all_equals = false;
            }
            if (ns[i] == ns[i - 1] + 1) {
                has_consecutive = true;
            }
            if (all_equals == false && has_consecutive)
                break;
        }
        if (all_equals)
            cout << "YES" << endl;
        else if (has_two && has_one)
            cout << "NO" << endl;
        else if (has_zero && has_one)
            cout << "NO" << endl;
        else if (has_consecutive && has_one)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

}
