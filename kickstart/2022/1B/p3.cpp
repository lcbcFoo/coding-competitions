#include <cmath>
#include <functional>
#include <iostream>
#include <map>

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <iomanip>

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
        ll N, D;
        cin >> N >> D;
        vector<ll> ds = vector<ll>(N);
        for (int i = 0; i < N; ++i)
            cin >> ds[i];
        ll count = 0;
        for (int i = N - 1; i > 0; -- i) {
            if (ds[i] == 0)
                continue;
            dbg(ds[i], abs(ds[i] - ds[i - 1]), D - ds[i]);
            count += min(min(D - ds[i], abs(ds[i] - ds[i - 1])), ds[i]);
        }
        count += min(D - ds[0], ds[0]);
        cout << "Case #" << t + 1 << ": " << count << endl;
    }
}
