#include <functional>
#include <iostream>
#include <map>

#include <queue>
#include <random>
#include <utility>
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

vector<ll> parents;
vector<vector<ll>> children;
vector<ll> current;
set<ll> visited;

void dfs(ll root)
{
    // Mark the current node as visited and
    // print it
    /* visited[v] = true; */
    /* cout << v << " "; */
    current.push_back(root + 1);
    visited.insert(root);
 
    /* // Recur for all the vertices adjacent */
    /* // to this vertex */
    if (children[root].size() == 0) {
        cout << current.size() << endl;
        for(auto i : current)
            cout << i << " ";
        cout << endl;
        return;
    }

    for (ll i = 0; i < children[root].size(); ++i) {
        if (i == 0) {
            dfs(children[root][i]);
        }
        else {
            current = vector<ll>();
            dfs(children[root][i]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    dbg(T);
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        parents = vector<ll>(N, -1);
        current = vector<ll>();
        children  = vector<vector<ll>>(N);
        ll root;
        for(int i = 0; i < N; ++i) {
            cin >> parents[i];
            if (parents[i] == i + 1) {
                root = i;
                continue;
            }
            parents[i]--;
            children[parents[i]].push_back(i);
        }
        if (N == 1) {
            cout << 1 << endl << 1 << endl << 1 << endl << endl;
            continue;
        }

        dbg(children);
        dbg(root);


        ll total = 1;
        for (int i = 0; i < children.size(); ++i) {
            dbg(children.size());
            if (children[i].size() > 1)
                total += children[i].size() - 1;
        }
        cout << total << endl;
        dfs(root);
        cout << endl;
    }
}
