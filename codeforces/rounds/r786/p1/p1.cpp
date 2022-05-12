#include <cmath>
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
        ll x, y; cin >> x >> y;

        if (y == x) {
            cout << 1 << " " << 1 << endl;
            continue;
        }

        if (y < x || y % x != 0) {
            cout << 0 << " " << 0 << endl;
            continue;
        }
        cout << 1 << " " << y / x << endl;
    }
}
