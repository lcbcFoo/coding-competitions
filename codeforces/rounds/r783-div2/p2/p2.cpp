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
        ull N, M;
        cin >> N >> M;
        ull ni;
        bool possible = true;
        ull count = 1;
        ull last = 0;
        ull first = 0;
        vector<ull> nis = vector<ull>(N);
        for (int i = 0; i < N; ++i) {
            cin >> ni;
            if (possible == false)
                continue;
            dbg(ni);
            dbg(last);
            dbg(count);
            if (i == 0) {
                last = ni;
                first = ni;
                continue;
            }
            count += max(ni, last) + 1;
            last = ni;
            dbg(count);
            if (count > M) {
                possible = false;
            }
            if (M - count < last || M - count < first) {
                possible = false;
            }
        }
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}
