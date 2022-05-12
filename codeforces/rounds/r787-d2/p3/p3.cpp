#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <cstring>
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
    ll T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() == 1) {
            cout << 1 << endl;
            continue;
        }
        if (s[0] == 0 || s.back() == 1) {
            cout << 1 << endl;
            continue;
        }
        int last_1 = s.find_last_of('1');
        int last_0 = s.find_first_of('0');
        last_0 = s.find_first_of('0', last_0 + 1);
        dbg(last_0, last_1);
        if (last_0 == string::npos && last_1 == string::npos) {
            cout << s.size() << endl;
            continue;
        }
        
    }
}
