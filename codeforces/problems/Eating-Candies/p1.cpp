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
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        vector<int> ns = vector<int>(N);
        for(int i = 0; i < N; ++i)
            cin >> ns[i];
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        int l = 0, r = N - 1;
        int count = 0, count_l = 1, count_r = 1;
        int w_l = ns[0], w_r = ns[N - 1]; 
        while (l < r) {
            dbg(l, r, w_l, w_r);
            if (w_l == w_r) {
                l++;
                r--;
                count += count_l + count_r;
                w_l = ns[l]; w_r = ns[r]; count_l = 1; count_r = 1;
            }
            else if (w_l < w_r) {
                count_l++; l++;
                w_l += ns[l];
            }
            else {
                count_r++; r--;
                w_r += ns[r];
            }
        }
        cout << count << endl;
    }
}
