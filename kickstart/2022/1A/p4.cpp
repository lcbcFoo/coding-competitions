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

ll sum_d(ll a) {
    ll s = 0;
    while(a) {
        s += a % 10;
        a /= 10;
    }
    return s;
}
ll mult_d(ll a) {
    ll s = 1;
    while(a) {
        s *= a % 10;
        a /= 10;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        ll A, B;
        cin >> A >> B;
        ll count = 0;
        for(int i = A; i <= B; ++i) {
            ll s = sum_d(i);
            ll m = mult_d(i);
            if (m % s == 0)
                count++;
        }
        cout << "Case #" << t + 1 << ": " << count << endl;
    }
}
