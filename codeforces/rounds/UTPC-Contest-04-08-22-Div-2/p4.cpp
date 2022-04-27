#include <functional>
#include <iostream>
#include <map>

#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 

#define DEBUG

#ifdef DEBUG
#include "../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

typedef struct _stack_t {
    string c;
    _stack_t* next;
} stack_p_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> v = vector<ll>(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int r = n - 1;
    int l;
    while (r >= 0) {
        if (v[r] > 0) {
            ll c = v[r];
            while(c--) v[--r] = c;
        }
        else {
            r--;
        }
    }
    v[0] = 0;
    dbg(v);
    for (int i = 1; i < n; ++i) {
        if (v[i] == -1) {
            if (v[i - 1] >= k - 1)
                v[i] = 0;
            else 
                v[i] = v[i - 1] + 1;
        }
    }
    cout << count(v.begin(), v.end(), 0) << endl;
    dbg(v);
}
