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
    int X, N, K;
    cin >> N >> X;
    vector<int> nuts = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> nuts[i];
    cin >> K;
    vector<int> wanted = vector<int>(K);
    for (int i = 0; i < K; ++i)
        cin >> wanted[i];
    int sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += nuts[wanted[i] - 1];
    }
    dbg(sum);
    cout << X - sum + 1 << endl;
}
