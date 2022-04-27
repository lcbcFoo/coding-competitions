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
        int N;
        cin >> N;
        if (N >= 1900)
            cout << "Division 1" << endl;
        else if (N >= 1600)
            cout << "Division 2" << endl;
        else if (N >= 1400)
            cout << "Division 3" << endl;
        else
            cout << "Division 4" << endl;
    }
}
