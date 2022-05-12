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
#include "../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r = 1000000;
    int l = 1;
    while (l < r) {
        int m = (l + r + 1) / 2;
        dbg(l, r, m);
        cout << m << endl << flush;
        string s;
        cin >> s;
        if (s.compare(">=") == 0) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << "! " << l << endl << flush;
}
