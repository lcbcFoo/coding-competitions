#include <climits>
#include <functional>
#include <iostream>
#include <map>

#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 

#define DEBUG

#ifdef DEBUG
#include "../../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

ll N, P;
ll sum_diffs(vector<ll> v, int b, int e) {
    dbg(v, b, e);
    ll s = v[b];
    for (int i = b + 1; i < e; ++i) {
        s += abs(v[i] - v[i - 1]);
    }
    return s;
}

ll min_diff(vector<ll> a, vector<ll> b) {
    int l = 0, r = 0;
 
    ll result = LONG_LONG_MAX;
 
    while (l < a.size() && r < b.size())
    {
        if (abs(a[l] - b[r]) < result)
            result = abs(a[l] - b[r]);
        if (a[l] < b[r])
            l++;
        else
            r++;
    }
    return result;
}

ll sum_v(vector<ll> v, ll current) {
    ll sum = current;
    while (next_permutation(v.begin(), v.begin() + P)) {
        sum = sum_diffs(v, 0, P);
    }
    return sum;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N >> P;
        vector<ll> ps = vector<ll>(N * P);
        for (int i = 0; i < N * P; ++i) {
            cin >> ps[i];
        }
        for (int i = 0; i < N * P; i += P) {
            sort(&ps[i], &ps[i + P]);
        }
        bool cont = true;
        ll best_sum = LONG_LONG_MAX;
        do {
            dbg(ps);
            ll s = sum_diffs(ps, 0, N * P);
            dbg(s);
            if (s < best_sum)
                best_sum = s;
            for (int i = 0; i < N * P; i += P) {
                cont = next_permutation(&ps[i], &ps[i + P]);
            }
        } while (cont);
        cout << "Case #" << t + 1 << ": " << best_sum << endl;
    }
}
