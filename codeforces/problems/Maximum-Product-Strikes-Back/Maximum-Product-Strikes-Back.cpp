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
#include "../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

int has_0(vector<ll> v, int b, int e) {
    int n = 0;
    for(int i = b; i < e; ++i)
        if (v[i] == 0)
            n++;
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        ll N;
        cin >> N;
        vector<ll> ns = vector<ll>(N);
        for(int i = 0;i < N; ++i) {
            cin >> ns[i];
        }
        int l = 0;
        int r = N - 1;
        int n = has_0(ns, 0, N);
        while (l < r && n-- > 0) {
            dbg(l, r);
            int tl = l;
            ll part_l = 1;
            while (tl < r && ns[tl++] != 0) {
                part_l *= ns[tl - 1];
            }
            int tr = r;
            ll part_r = 1;
            while (tr > l && ns[tr--] != 0) {
                part_r *= ns[tr + 1];
                dbg("here");
            }
            dbg(tl, tr, part_l, part_r);
            ll mi = min(part_l, part_r);
            ll ma = max(part_l, part_r);
            /* if (mi < 0 && ma > 0) { */
            /*     if (part_l < part_r) { */
            /*         dbg(1); */
            /*         l = tl; */
            /*     } */
            /*     else { */
            /*         dbg(2); */
            /*         r = tr; */
            /*     } */
            /* } */
            if (abs(part_l) < abs(part_r)) {
                dbg(5);
                l = tl;
            }
            else {
                dbg(6);
                r = tr;
            }
            dbg(l, r);
        }
        ll mult = accumulate(ns.begin() + l, ns.begin() + r + 1, 1,
            [](ll a, const ll b) {return a * b;});
        dbg(mult);
        while (l < r && mult < 0) {
            int tl = l;
            ll part_l = 1;
            while (ns[tl++] > 0 && tl < r) {
                part_l *= ns[tl - 1];
            }
            int tr = r;
            ll part_r = 1;
            while (ns[tr--] > 0 && tr > l) {
                part_r *= ns[tr + 1];
            }
            ll mult_l = accumulate(ns.begin() + tl, ns.begin() + r + 1, 1,
                    [](ll a, const ll b) {return a * b;});
            ll mult_r = accumulate(ns.begin() + l, ns.begin() + tr + 1, 1,
                    [](ll a, const ll b) {return a * b;});
            dbg(tl, tr, part_l, mult_l, part_r, mult_r);
            if (mult_l == mult_r) {
                if (part_l > part_r) {
                    r = tr;
                    mult = mult_r;
                }
                else {
                    l = tl;
                    mult = mult_l;
                }
            }
            else if (mult_l > mult_r) {
                l = tl;
                mult = mult_l;
            }
            else {
                r = tr;
                mult = mult_r;
            }
        }
        dbg("end = ", l, r);
        if (mult <= 0) {
            l = 1;
            r = 0;
        }
        cout << l << " " << N - 1 - r << endl;
    }
}
