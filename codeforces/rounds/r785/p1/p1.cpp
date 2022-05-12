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

int points(string s, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i] - 'a' + 1;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string s;
        cin >> s;

        if (s.size() == 1) {
            cout << "Bob " << points(s, s.size()) << endl;
            continue;
        }

        if (s.size() % 2 == 0) {
            cout << "Alice " << points(s, s.size()) << endl;
            continue;
        }
        int pl = points(s, s.size() - 1);
        int pr = points(&s[1], s.size() - 1);
        if (pl >= pr) {
            int diff = pl - (s.back() - 'a' + 1);
            cout << "Alice " << diff << endl;
        }
        else {
            int diff = pr - (s.front() - 'a' + 1);
            cout << "Alice " << diff << endl;
        }


    }
}
