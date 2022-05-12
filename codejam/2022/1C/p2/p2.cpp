#include <climits>
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
        int N, K;
        cin >> N >> K;
        vector<ll> ns = vector<ll>(N + K);
        for (int i = 0; i < N; ++i) {
            cin >> ns[i];
        }
        for (int i = N; i < N + K; ++i)
            ns[i] = 0;
        ll s = accumulate(ns.begin(), std::next(ns.begin(), N), 0);
        ll r = 0;
        for (int i = 0; i < N; ++i) {
            r += ns[i] * ns[i];
        }

        bool solved = false;
        vector<int> res;
        ll best_diff = LONG_LONG_MAX;
        while(K--) {
            ll use = 0;
            for (ll i = -1000; i <= 1000; ++i) {
                ll tmp_r = r + i * i;
                ll tmp_s = (s + i) * (s + i);
                dbg(tmp_r, tmp_s);
                if (tmp_r == tmp_s) {
                    use = i;
                    break;
                }
                else if (best_diff > abs(tmp_r - tmp_s)) {
                    best_diff = abs(tmp_r - tmp_s);
                    use = i;
                }
            }
            res.push_back(use);
            s = s + use;
            r = r + use * use;
            if (s * s == r) {
                solved = true;
                break;
            }
        }

        if (solved) {
            cout << "Case #" << t + 1 << ": ";
            cout << res[0];
            for (int i = 1; i < res.size(); ++i)
                cout << " " << res[i];
            cout << endl;
        }
        else {
            cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
        }
    }
}
