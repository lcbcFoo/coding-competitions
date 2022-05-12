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
        int N, m; cin >> N >> m;
        vector<string> ns = vector<string>(N);
        for (int i = 0; i < N; ++i)
            cin >> ns[i];

        sort(ns.begin(), ns.end());
        ll sum = LLONG_MAX;
        for (int i = 1; i < ns.size(); ++i) {
            ll tmp = 0;
            for (int j = 0; j < m; ++j) {
                int a = ns[i - 1][j] - 'a';
                int b = ns[i][j] - 'a';
                tmp += abs(a - b);
            }
            if (tmp < sum)
                sum = tmp;
        }
        cout << sum << endl;
    }
}
