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
#include "../../../../debug.hpp"
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
        int M, N;
        cin >> N >> M;
        int ma = max(N, M);
        int mi = min(N, M);
        dbg (N, M);
        if (mi == 1) {
            if (ma > 2) {
                cout << -1 << endl;
            }
            else {
                cout << (int) (ma != 1) << endl;
            }
        }
        else {
            int count = 2 * (mi - 1);
            // even
            if ((ma - mi) % 2 == 0) {
                count += ma - mi;
                count += ma - mi;
            }
            // odd
            else {
                count += ma - mi;
                count += ma - mi - 1;
            }

            cout << count << endl;
        }
        dbg(t, T);
    }
}
