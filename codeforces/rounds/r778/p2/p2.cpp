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
        vector<ll> ns = vector<ll>('z' - 'a' + 1, 0);
   
        for (auto i: s)
            ns[i - 'a']++;
        dbg(ns);
        int l = 0;
        int x;
        do{
            ns[s[l] - 'a']--;
            x = ns[s[l] - 'a'];
            if (x)
                l++;
        } while (x);
        while (l < s.size()){
            cout << s[l++];
        }
        cout << endl;
    }
}
