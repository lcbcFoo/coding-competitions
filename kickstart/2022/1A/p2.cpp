#include <functional>
#include <iostream>
#include <map>

#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 

/* #define DEBUG */

#ifdef DEBUG
#include "../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string N;
        cin >> N;
        ll s = 0;
        for (int i = 0; i < N.size(); ++i) {
            s += N[i] - '0';
        }
        int r = 9 - s % 9;
        dbg(r);
        if (r == 9) {
            cout << "Case #" << t + 1 << ": " << N[0] << 0 << N.substr(1, N.size()) << endl;
            continue;
        }
        else {
            cout << "Case #" << t + 1 << ": ";
            bool put = false;
            for (int i = 0; i < N.size(); ++i) {
                if (put || N[i] <= r + '0') {
                    cout << N[i];
                }
                else {
                    cout << r;
                    put = true;
                    i--;
                }
            }
            if (!put)
                cout << r;
            cout << endl;
        }
    }
}
