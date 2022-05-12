#include <functional>
#include <iostream>
#include <map>

#include <string>
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
    vector<string> words;
    for(char i = 'a'; i <= 'z'; ++i)
        for(char j = 'a'; j <= 'z'; ++j)
            if(i != j) {
                char v[2];
                v[0] = i;
                v[1] = j;
                string s(v);
                words.push_back(s);
            }

    for (int t = 0; t < T; ++t) {
        string w;
        cin >> w;
        for (int i = 0; i < words.size(); ++i)
            if (words[i] == w) {
                cout << i + 1 << endl << flush;
                break;
            }
    }
}
