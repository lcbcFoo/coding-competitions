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
        string a, b;
        cin >> a >> b;
        if (b.size() == 1 && b[0] == 'a') {
            cout << 1 << endl;
            continue;
        }
        bool ok = true;
        for (auto i: b) {
            if (i == 'a') {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
        }
        else {
            cout << (ll)pow(2, count(a.begin(), a.end(), 'a')) << endl;
        }


    }
}
