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
    int n, m, q;
    cin >> n >> m >> q;
    char desk[1000][1000];
    for (int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> desk[i][j];
    int icons = 0;
    for (int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if (desk[i][j] == '*')
                icons++;
    int in_place = 0;
    for (int k = 0; k < icons; ++k) {
        int j = k / n;
        int i = k % n;
        dbg(i, j, desk[i][j]);
        if (desk[i][j] == '*')
            in_place++;
    }
    int moves = icons - in_place;
    dbg(icons, in_place);

    while (q--) {
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                cout << desk[i][j];
            cout << endl;
        }

        int i, j; cin >> i >> j;
        i--;
        j--;
        dbg(i, j, moves, icons);
        if (desk[i][j] == '*') {
            desk[i][j] = '.';
            icons--;
            int last_i = icons % n;
            int last_j = icons / n;
            dbg(last_i, last_j);
            if (last_j < j)
                moves--;
            else if (last_j == j) {
                if (last_i < i)
                    moves--;
                else
                    moves++;
            }
            else {
                moves++;
            }
        }
        else {
            desk[i][j] = '*';
            icons++;
            int last_i = icons % n;
            if (last_i == 0)
                last_i = m-1;
            else
                last_i--;
            int last_j = icons / n;
            dbg(last_i, last_j);
            if (last_j < j) {
                moves++;
                if (desk[last_i][last_j] == '*')
                    moves--;
            }
            else if (last_j == j) {
                if (last_i < i) {
                    moves++;
                    if (desk[last_i][last_j] == '*')
                        moves--;
                }
                else
                    moves--;
            }
            else {
                moves--;
            }
        }
        moves = min(icons, moves);
        cout << moves << endl;

    }
}
