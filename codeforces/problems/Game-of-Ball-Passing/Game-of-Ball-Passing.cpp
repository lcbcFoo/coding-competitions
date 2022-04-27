#include <functional>
#include <iostream>
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

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<ll> players = vector<ll>(N);
        for (int i = 0; i < N; ++i)
            cin >> players[i];

        dbg(players);
        if (*max_element(players.begin(), players.end()) == 0) {
            cout << 0 << endl;
            continue;
        }
        sort(players.begin(), players.end(), greater<ll>());
        int balls = 1;
        int l = 0;
        int r = 1;
        while (r < N) {
            dbg(players);
            if (players[l] == players[r]) {
                players[l] = 0;
                players[r] = 1;
                l = r;
                r++;
            }
            else if (players[l] > players[r]) {
                players[l] = players[l] - players[r];
                players[r] = 0;
                r++;
            }
            else {
                players[r] -= players[l] - 1;
                players[l] = 0;
                l = r;
                r++;
            }
        }
        if (players[N - 1] == 1)
            players[N - 1] = 0;
        dbg(players);
        if (players[l] <= 1)
            cout << 1 << endl;
        else
            cout << players[l] << endl;
    }
}
