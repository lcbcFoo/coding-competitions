#include <functional>
#include <iostream>
#include <map>

#include <utility>
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

// size, value
pair<ll, ll> solve(vector<ll> v, int l, int r) {
    if (l == r) {
        pair<ll, ll> p;
        if (v[l] > 0)
            p = make_pair(1, v[l]);
        else
            p = make_pair(-1, -v[l]);
        return p;
    }

    pair<ll, ll> pleft, pright;
    pleft = solve(v, l + 1, r);
    pright = solve(v, l, r + 1);
    if (pleft.second > 0 && pright.second > 0)
        return make_pair(pright.first + pleft.first, pright.second + pright.second);
    if (pleft.second < 0 && pright.second > 0) {
        if (pleft.second + pright.second >= 0)
            return make_pair(abs(pleft.first) + pright.first,
                             pright.second + pleft.second);
    }
    if (pleft.second > 0 && pright.second < 0) {
        if (pleft.second + pright.second >= 0)
            return make_pair(abs(pright.first) + pleft.first,
                             pright.second + pleft.second);
    }
    return make_pair(1, 1);
}


int main() {
    /* ios_base::sync_with_stdio(false); */
    /* cin.tie(nullptr); */
    int T;
    cin >> T;
    dbg(T);
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<ll> ns = vector<ll>(N);
        for(int i = 0; i < N; ++i) {
            cin >> ns[i];
        }
        dbg(ns);
        int l = 0, r = 0;
        ll s = ns[0], p = 0;
        while(r < N) {
            dbg(l, r, s, p);
            if (s > 0) {
                p += r - l + 1;
                l = r + 1;
                r = l;
                s = ns[l];
            }
            else {
                r++;
                if (r == N) {
                    p -= (r - l);
                }
                else 
                    s += ns[r];
            }
        }
        cout << p << endl;
    }
}
