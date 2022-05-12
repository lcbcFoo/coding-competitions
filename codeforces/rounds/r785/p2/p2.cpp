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
        set<char> ls;
        vector<char> seq;
        for (int i = 0; i < s.size(); ++i) {
            if (ls.find(s[i]) == ls.end()) {
                ls.insert(s[i]);
                seq.push_back(s[i]);
            }
            else {
                break;
            }
        }
        int l = 0;
        bool impossible = false;
        dbg(seq);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != seq[i % seq.size()]) {
                impossible = true;
            }
        }

        if (impossible)
            cout << "NO" <<endl;
        else
            cout << "YES" << endl;
    }
}
