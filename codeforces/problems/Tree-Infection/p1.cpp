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
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<ll> childrens_infected = vector<ll>(N + 1, 0);
        childrens_infected[0] = 1;
        for (int i = 1; i < N; ++i) {
            ll tmp; cin >> tmp;
            childrens_infected[tmp]++;
        }

        sort(childrens_infected.begin(), childrens_infected.end(),
                [](ll a, ll b) {
                    return a > b;
                });
        while (!childrens_infected.empty() && childrens_infected.back() <= 0)
            childrens_infected.pop_back();

        ll actions = childrens_infected.size();
        ll inject = 0;
        ll last = -1;
        for (int i = 0; i < childrens_infected.size(); ++i) {
            if (actions - i < 0)
                break;
        
            childrens_infected[i] -= actions - i;
        }

        while (!childrens_infected.empty() && childrens_infected.back() <= 0)
            childrens_infected.pop_back();

    dbg(childrens_infected);

        while (childrens_infected.size() > 0) {
            sort(childrens_infected.begin(), childrens_infected.end(),
                    [](ll a, ll b) {
                        return a > b;
                    });
            actions++;
            for (int i = 0; i < childrens_infected.size(); ++i) {
                if (childrens_infected[i]) {
                    childrens_infected[i]--;
                    break;
                }
            }
            for (int i = 0; i < childrens_infected.size(); ++i) {
                childrens_infected[i]--;
            }
            while (!childrens_infected.empty() && childrens_infected.back() <= 0)
                childrens_infected.pop_back();
            dbg(childrens_infected);
        }
        cout << actions << endl << flush;
    }
}
