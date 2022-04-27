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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> ns = vector<int>(N);
        for (int i = 0; i < N; ++i)
            cin >> ns[i];
        auto cs = count_elements(ns);
        dbg(ns);
        bool found = false;
        for (int i = 0; i < N; ++i) {
            int v = ns[i];
            if (cs.find(v)->second >= 3) {
                cout << v << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << -1 << endl;
    }
}
