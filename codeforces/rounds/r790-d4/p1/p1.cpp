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
        string s;
        cin >> s;
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < 3; ++i) {
            s1+=s[i];
            s2 += s[5 - i];
        }
        if (s1 == s2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
