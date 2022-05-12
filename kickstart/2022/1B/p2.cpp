#include <cmath>
#include <functional>
#include <iostream>
#include <map>

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <iomanip>

/* #define DEBUG */

#ifdef DEBUG
#include "../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

bool is_palind(string s) {
    int l = 0, r = s.size() - 1;
    
    while (l <= r) {
        if (s[l] != s[r])
            return false;
        l++; r--;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        ll N;
        cin >> N;
        ll count = 0;
        ll limit = (ll) sqrt(N);
        for (int i = 1; i <= limit; ++i) {
            if (N % i != 0)
                continue;
            dbg(i);
            string s = to_string(i);
            if (is_palind(s)) count++;
            ll tmp = N / i;
            dbg(tmp);
            if (tmp == i)
                continue;
            s = to_string(tmp);
            if (is_palind(s)) count++;
        }
        cout << "Case #" << t + 1 << ": " << count << endl;
    }
}
