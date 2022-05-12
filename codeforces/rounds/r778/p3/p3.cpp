#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <cstring>
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

template<class T>
std::map<T, ull> count_elements(std::vector<T> v, ll N) {
    std::map<T, ull> counters = std::map<T, ull>();
    for(int i = 0; i < N; ++i)
    {
        ++counters[v[i]];
    }
    return counters;
}

map<ll, ull> m;
ll N;
vector<ll> ns = vector<ll>(2 * 100000);
ull mi;

void removea(ll a) {
    ll i = 0;
    while(i < N && ns[i] != a)
        ns.erase(ns.begin());
}

void halves(ll n) {
    dbg(n);
    if (n < mi)
        return;
    if (n == 1) {
        if (m.find(1) != m.end())
            m[1]--;
        return;
    }

    ll l = n / 2;
    ll r = (n + 1) / 2;

    if (l) {
        if (m.find(l) != m.end()) {
            m[l]--;
            if (m[l] == 0) {
                m.erase(l);

                if (l == mi) {
                    removea(mi);
                    mi = ns[0];
                }
            }
        }
        else {
            halves(l);
        }
    }
    dbg(m);
    if (r) {
        if (m.find(r) != m.end()) {
            m[r]--;
            if (m[r] == 0) {
                m.erase(r);

                if (r == mi) {
                    removea(mi);
                    mi = ns[0];
                }
            }
        }
        else {
            halves(r);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> N;
        ns = vector<ll>(N);
        for (ll i = 0; i < N; ++i) {
            cin >> ns[i];
        }
        if (N == 1) {
            cout << "YES" << endl;
            continue;
        }
        m = count_elements<ll>(ns, N);
        sort(ns.begin(), ns.begin() + N);
        mi = ns[0];
        dbg(mi);
        ll candidate = accumulate(ns.begin(), ns.end(), 0LL);
        halves(candidate);
        if (m.size()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }

    }
}
