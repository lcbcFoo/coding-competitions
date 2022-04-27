#include <utility>
#ifdef DEBUG
#include "../../../debug.hpp"
#else 
#define dbg(...)
#endif

#define ll long long int

#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int M, N;
        cin >> N >> M;
        vector<pair<ll, ll>> map_points = vector<pair<ll, ll>>(N);
        set<ll> to_be_used;
        map<ll, int> original_idxs;
        vector<pair<ll, ll>> segments = vector<pair<ll, ll>>(M);
        for (int i = 0; i < M; ++i) {
            ll xi, wi;
            cin >> xi >> wi;
            original_idxs.insert(make_pair(xi, i + 1));
            segments[i] = make_pair(xi, wi);
        }
        sort(segments.begin(), segments.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.second < b.second;
        });
        for (int i = 0; i < 2 * N; ++i)
            to_be_used.insert(segments[i].first);
        sort(segments.begin(), segments.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.first < b.first;
        });
        int l = 0;
        int r = M - 1;
        ll s = 0;
        int n = 0;
        dbg(segments);
        dbg(original_idxs);
        dbg(to_be_used);
        while (l < r) {
            if (to_be_used.find(segments[l].first) == to_be_used.end()) {
                l++;
                continue;
            }
            else if (to_be_used.find(segments[r].first) == to_be_used.end()) {
                r--;
                continue;
            }
            else {
                map_points[n++] = make_pair(
                            original_idxs.find(segments[l].first)->second,
                            original_idxs.find(segments[r].first)->second);
                s += segments[l].second + segments[r].second;
                dbg(l, r, segments[l], segments[r]);
                l++;
                r--;
            }
        }
        cout << s << endl;
        for (auto v : map_points) {
            cout << v.first << " "<< v.second << endl;
        }
    }

}

