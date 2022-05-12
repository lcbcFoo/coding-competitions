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
        int N; cin >> N;
        vector<ll> ns = vector<ll>(N);
        for (int i = 0; i < N; ++i)
            cin >> ns[i];
        int mi = *min_element(ns.begin(), ns.end());
        ll sum = 0;
        for (int i = 0; i < N; ++i)
            sum += ns[i] - mi;
        cout << sum << endl;
    }
}
