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
        ll N;
        cin >> N;
        vector<ll> ns = vector<ll>(N);
        for (int i = 0; i < N; ++i)
            cin >> ns[i];

        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        if (N == 2 && ns[1] == 0) {
            cout << -1 << endl;
            continue;
        }
        bool pos = true;
        ll count = 0;
        for (int i = N - 2; pos && i >= 0; --i) {
            dbg(ns);
            while(ns[i] && ns[i] >= ns[i + 1]) {
                ns[i] /= 2;
                count++;
            }
            if (ns[i] == 0 && i > 0)
                pos = false;
        }
        if (pos)
            cout << count << endl;
        else
            cout << -1 << endl;
    }
}
