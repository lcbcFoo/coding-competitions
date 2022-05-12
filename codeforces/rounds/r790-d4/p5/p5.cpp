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

template<class T>
std::map<T, ull> count_elements(std::vector<T> v) {
    std::map<T, ull> counters = std::map<T, ull>();
    for(auto i: v)
    {
        ++counters[i];
    }
    return counters;
}

template<class T>
std::pair<const int, long long unsigned int> vector_mode(std::vector<T> v) {
    auto frequency_count = count_elements<T>(v);
    auto pr = std::max_element
    (
        std::begin(frequency_count), std::end(frequency_count),
        [] (auto & p1, auto & p2) {
            return p1.second < p2.second;
        }
    );
    return *pr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, k; cin >> N >> k;
        vector<ll> ns = vector<ll>(N);
        set<ll> s;
        for (int i = 0; i < N; ++i) {
            cin >> ns[i];
            s.insert(ns[i]);
        }
        map<ll, ull> count = count_elements(ns);
        ll mi = *min_element(ns.begin(), ns.end());
        ll ma = *max_element(ns.begin(), ns.end());
        ll l = mi;
        ll r = ma;
        bool found = false;
        while(l <= r) {
            bool ok = false;
            /* do { */
            /*     if (r < l) { */
            /*         break; */
            /*     } */
            /*     auto a = count.find(l); */
            /*     if (a == count.end() || a->second < k) */
            /*         l++; */
            /*     else */
            /*         ok = true; */
            /* } while(!ok); */
            while(l < r && (!count[l] || count[l] < k)) l++;
            if (l > r || !count[l])
                break;
            while(l < r && (!count[r] || count[r] < k)) r--;
            if (l > r || !count[r])
                break;
            /* do { */
            /*     if (r < l) { */
            /*         break; */
            /*     } */
            /*     auto a = count.find(r); */
            /*     if (a == count.end() || a->second < k) */
            /*         r--; */
            /*     else */
            /*         ok = true; */
            /* } while(!ok); */
            /* if (!ok) */
            /*     break; */
            ll i;
            ok = true;
            for (i = l + 1; i < r && ok; ++i) {
                if (!count[i] || count[i] < k) {
                    ok = false;
                    break;
                }
                /* auto a = count.find(i); */
                /* if (a == count.end() || a->second < k) { */
                /*     ok = false; */
                /*     break; */
                /* } */
            }
            if (ok) {
                found = true;
                break;
            }
            dbg(i, l, r);
            if (i - l < r - i)
                l = i + 1;
            else
                r = i - 1;
        }
        if (l == r && count[l] && count[l] < k)
            cout << -1 << endl;
        else
            cout << l << " " << r << endl;
    }
}
