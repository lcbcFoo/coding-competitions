#include <functional>
#include <iostream>
#include <map>

#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <string>

/* #define DEBUG */

#ifdef DEBUG
#include "../../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

typedef struct {
    string p;
    int index;
} pair_t;


vector<string> to_string_v(vector<pair_t> v) {
    vector<string> a;
    for (auto i : v)
        a.push_back(i.p);

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<pair_t> pairs = vector<pair_t>(N);
        for (int i = 0; i < N; ++i) {
            pair_t p;
            string a;
            cin >> p.p;
            p.index = i;
            pairs[i] = p;
        }
        sort(pairs.begin(), pairs.end(), [](pair_t a, pair_t b) {
                    return a.p < b.p;
                });
        dbg(to_string_v(pairs));
        set<pair<int, int>> ps;
        for (int i = 0; i < N - 1; ++i) {
            pair_t w = pairs[i];
            for (int j = i + 1; j < N; ++j) {
                if (pairs[j].p[0] != w.p[0])
                    break;
                else {
                    if (pairs[j].p[1] == w.p[1])
                        continue;
                    dbg(w.p, pairs[j].p);
                    int id_i = min(w.index, pairs[j].index);
                    int id_j = max(w.index, pairs[j].index);
                    if (id_i == id_j)
                        continue;
                    if (ps.find(make_pair(id_i, id_j)) == ps.end()) {
                        ps.insert(make_pair(id_i, id_j));
                    }
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            char tmp = pairs[i].p[0];
            pairs[i].p[0] = pairs[i].p[1];
            pairs[i].p[1] = tmp;
        }
        dbg(ps);
        sort(pairs.begin(), pairs.end(), [](pair_t a, pair_t b) {
                    return a.p < b.p;
                });
        dbg(to_string_v(pairs));
        for (int i = 0; i < N - 1; ++i) {
            pair_t w = pairs[i];
            for (int j = i + 1; j < N; ++j) {
                if (pairs[j].p[0] != w.p[0])
                    break;
                else {
                    if (pairs[j].p[1] == w.p[1])
                        continue;
                    dbg(w.p, pairs[j].p);
                    int id_i = min(w.index, pairs[j].index);
                    int id_j = max(w.index, pairs[j].index);
                    if (id_i == id_j)
                        continue;
                    if (ps.find(make_pair(id_i, id_j)) == ps.end()) {
                        ps.insert(make_pair(id_i, id_j));
                    }
                }
            }
        }
        dbg(ps);
        ll count = ps.size();
        cout << count << endl;
    }
}
