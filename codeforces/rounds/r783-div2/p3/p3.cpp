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

bool is_increasing(vector<ll> v) {
    for (int i = 0; i < v.size() - 1; ++i)
        if (v[i] > v[i + 1])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<ull> as = vector<ull>(N);
    vector<ull> bs = vector<ull>(N, 0);
    for (int t = 0; t < N; ++t) {
        cin >> ns[t];
    }
    ll count = 1;
    ll prev = ns[0];
    for (int i = 1; i < N; ++i) {
        count += ns[i] / prev + 1;
    }
    cout << count << endl;
}
