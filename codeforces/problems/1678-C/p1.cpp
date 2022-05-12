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
        int N; cin >> N;
        vector<int> ns = vector<int>(N);
        vector<int> f = vector<int>(N, 0);
        for(int i = 0; i < N; ++i)
            cin >> ns[i];
        for (int b = 1; b < N - 2; ++b)
            for (int d = b + 1; d < N; ++d)
                if (ns[b] > ns[d])
                    f[b]++;
        ll count = 0;
        for (int b = 1; b < N - 2; ++b) {
            for (int a = 0; a < b; ++a) {
                for (int c = b + 1; c < N; ++c) {
                    if (ns[a] < ns[c])
                        count += f[b];
                }
            }
        }
        cout << count << endl;
    }
}
