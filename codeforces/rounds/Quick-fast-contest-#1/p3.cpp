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
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ma = max(n, m);
    int mi = min (n, m);
    int sum = mi * (1 + ma);
    cout << sum << endl;
}
