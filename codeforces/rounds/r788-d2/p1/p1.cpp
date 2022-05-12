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
        int l = 0;
        int r = N - 1;
        bool ok = true;
        while (l < N - 1) {
            dbg(ns);
            if (ns[l] > ns[l + 1]){
                int idx = l + 1;
                while (idx < N && ns[idx] * ns[l] >= 0)
                    idx++;
                if (idx == N) {
                    ok = false;
                    break;
                }
                ns[l] = ns[l] * -1;
                ns[idx] = ns[idx] * -1;
            }
            l++;
        }
        for (int i = 0; i < N - 1; ++ i)
            if (ns[i] > ns[i + 1]) {
                ok = false;
                break;
            }
        if (ok)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}
