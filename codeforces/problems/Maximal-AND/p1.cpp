#include <functional>
#include <iostream>
#include <map>

#include <string>
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

ll count_ops(vector<ll> ns, int bit) {
    int count = 0;
    for (auto i : ns) {
        count += (i & (1 << bit)) == 0;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<ll> ns = vector<ll>(n);
        for (int i = 0; i < n; ++i) {
            cin >> ns[i];
        }
        for (int i = 30; i >= 0; --i) {
            ll c = count_ops(ns, i);
            dbg(c, i);
            if (c <= k) {
                dbg("found: ", c);
                for (int j = 0; j < n; ++j) {
                    dbg(1 << i);
                    dbg(ns[j]);
                    ns[j] = ns[j] | (1 << i);
                    dbg(ns[j]);

                }
                k -= c;
            }
        }
        dbg(ns);
        ll best = 0xffffffff;
        for (int j = 0; j < n; ++j) {
            best &= ns[j];
        }
        cout << best << endl;
    }
}
