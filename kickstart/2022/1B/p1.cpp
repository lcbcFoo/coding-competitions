#include <functional>
#include <iostream>
#include <map>

#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <iomanip>

constexpr long double pi = 3.14159265358979323846;

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
        ll R, A ,B;
        cin >> R >> A >> B;
        long double area = 0;
        bool right = true;
        while (R) {
            area += (double) pi * R * R;
            if (right)
                R *= A;
            else 
                R /= B;
            right = !right;
        }
        cout << "Case #" << t + 1 << ": " << std::setprecision(10) << area << endl;
    }
}
