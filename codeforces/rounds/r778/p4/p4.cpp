#include <functional>
#include <iostream>
#include <map>

#include <queue>
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

#define MOD 998244353;

typedef struct {
    ll prop_i;
    ll prop_j;
} props_t;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    dbg(T);
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        props_t p;
        p.prop_j = 1;
        p.prop_i = 1;
        vector<vector<props_t>> rules =
            vector<vector<props_t>>(N, vector<props_t>(N, props_t()));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                rules[i][j] = p;
        dbg("oi");

        for(int l = 0; l < N - 1; ++l) {
            int i, j, x, y;
            cin >> i >> j >> x >> y;
            i--;
            j--;
            props_t t;
            t.prop_i = x; t.prop_j = y;
            rules[i][j] = t;
            t.prop_j = x; t.prop_i = y;
            rules[j][i] = t;
        }
        // find max
        ll ma = 1;
        ll i_ma = 0;
        for (int i = 0; i < N; ++i) {
            ll count = 1;
            for (int j = 0; j < N; ++j) {
                count = lcm(count, rules[i][j].prop_i);
            }
            if (count > ma) {
                ma = count;
                i_ma = i;
            }
        }
        set<ll> used;
        vector<ll> ns = vector<ll>(N, 0);
        ll current = i_ma;
        ns[current] = ma;
        queue<ll> to_go;
        to_go.push(current);
        used.insert(current);
        dbg(current);
        dbg(ma);
        /* for (int i = 0; i < N; ) */
        /*     to_go.push(i); */

        while (used.size() != N) {
            ll n_current = current;
            for (ll j = 0; j < N; ++j) {
                props_t p = rules[current][j];
                if (ns[j] == 0 && p.prop_i != 1 || p.prop_j != 1) {
                    ns[j] = (ns[current] * p.prop_j / p.prop_i) % MOD;
                    to_go.push(j);
                    used.insert(j);
                }
            }
            if (to_go.empty()) {
                dbg("bo");
                break;
            }
            current = to_go.front();
            to_go.pop();
        }
        dbg(ns);
        dbg(ma, i_ma);
        ll sum = 0;
        for (auto i: ns)
            sum = (sum + i) % MOD;
        cout << sum << endl;
    }
}
