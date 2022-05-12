#include <csignal>
#include <functional>
#include <iostream>
#include <map>

#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 


/*
 * Debug macros (uncomment the #define DEBUG and use dbg(var) to debug it) 
 */

/* #define DEBUG */

#ifdef DEBUG
#include "../../../../debug.hpp"
#else
#define dbg(...)
#endif

/*
 * Declare main function before defining the macro which replaces int to long long
 */

void __main();

int main() {
    __main();
}

/*
 * Define integer macros (avoid int overflows)
 */

#define ll long long
#define ull unsigned long long
#define int ll
#define uint ull

// Namespace std to simplify typing

using namespace std;


/*
 * General macros
 */

// Select the bit of position i of x
#define bit(x,i)        (x&(1<<i))
// Get the lowest bit of x
#define lowbit(x)       ((x)&((x)^((x)-1)))
// more intuitive way to check if x is present in set c
#define IN(c,x)         ((c).find(x) != (c).end())
// More intuitive way to check if x is NOT present in set c
#define NOT_IN(c,x)     ((c).find(x) == (c).end()) 

/*
 * Iterations macros
 */

#define EACH(x, a)      for (auto& x: a)
#define FOR(i,L,R)      for (int i = L; i < R; i++) //next four are for "for loops"
#define FOR_EQ(i,L,R)   for (int i = L; i <= R; i++)
#define RFOR(i,L,R)     for (int i = L; i > R; i--)
#define RFOR_EQ(i,L,R)  for (int i = L; i >= R; i--)
#define SZ(x)           ((int)((x).size()))
#define ALL(a)          a.begin(), a.end()
// Example sorting based on a field a: sort(arr, arr + N, by(a));
#define by(x)           [](const auto& a, const auto& b) { return a.x < b.x; }


/*
 * Read IO macros
 */
template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vector<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

/*
 * Actual solutions
 */

typedef struct _node {
    vector<ll> children;
    char c;
} node_t;

vector<node_t> ns;

ll ans = 0;

pair<int, int> dfs(ll n) {
    if (ns[n].children.empty()) {
        if (ns[n].c == 'B')
            return {1, 0};
        else 
            return {0, 1};
    }
    int tot_bs = 0;
    int tot_ws = 0;
    EACH(i, ns[n].children) {
        auto tmp = dfs(i);
        int bs = tmp.first;
        int ws = tmp.second;
        dbg(bs, ws);
        tot_bs += bs;
        tot_ws += ws;
    }
    if (ns[n].c == 'B')
        tot_bs++;
    else 
        tot_ws++;
    if (tot_bs == tot_ws) {
        dbg(n);
        ans++;
    }
    return {tot_bs, tot_ws};
}

void __main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    FOR_EQ(t, 1, T) {
        int N;
        read(N);
        ns.resize(N);
        ns.clear();
        ans = 0;
        FOR(i, 1, N) {
            int k; cin >> k;
            ns[k - 1].children.push_back(i);
        }
        FOR(i, 0, N) {
            cin >> ns[i].c;
        }
        EACH(x, ns)
            dbg(x.c, x.children);
        dfs(0);
        cout << ans << endl;
    }
}
