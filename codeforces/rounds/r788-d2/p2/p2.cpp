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
        string s;
        int N, k;
        cin >> N;
        cin >> s;
        cin >> k;
        set<char> cs;
        for (int i = 0; i < k; ++i) {
            char c;
            cin >> c;
            cs.insert(c);
        }
        int max = 0;
        int l = 0;
        int r = 1;
        while (l < N && cs.find(s[l]) == cs.end()) {
            l++;
            max++;
        }
        ll prev = 0;
        while (l < N) {
            ll cur = 0;
            r = l + 1;
            while (r < N && cs.find(s[r]) == cs.end()) {
                cur++;
                r++;
            }
            if (r == N)
                break;
            dbg(l, r, max, cur);
            if (cur > max)
                break;
            else if (prev <= max) {
                max += prev + 1;
            }
            l = r;
            prev = cur;
        }
        cout << max << endl;
    }
}
