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
        string P, I;
        cin >> I >> P;
        int l = 0;
        int count = 0;
        bool pos = true;
        for (int i = 0; i < I.size(); ++i, ++l) {
            while(l < P.size() && P[l] != I[i]) {
                count++;
                l++;
            }
            if (l == P.size()) {
                pos = false;
                break;
            }
        }
        count += P.size() - l;
        if (pos) {
            cout << "Case #" << t + 1 << ": " << count << endl;
        }
        else {
            cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
        }
    }
}
