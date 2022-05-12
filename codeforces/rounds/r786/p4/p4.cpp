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
        for (int i = 0; i <N; ++i)
            cin >> ns[i];

        if (N == 1 || N == 2) {
            cout << "YES" << endl;
            continue;
        }
        bool higher = ns[0] > ns[1];
        bool ok = true;
        for (int i = 1; i < N - 1 && ok; ++i){
            if (higher && ns[i] > ns[i + 1])
                ok = false;
            else if (!higher && ns[i] < ns[i + 1])
                ok = false;
            higher = !higher;
        }
        if (ok)
            cout << "YES" << endl;
        else{
            cout << "NO" << endl;
        }
    }
}
