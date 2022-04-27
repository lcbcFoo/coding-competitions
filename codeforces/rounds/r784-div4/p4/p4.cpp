#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <cstdlib>

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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        bool ok = true;
        vector<char> wanted = vector<char>(N);
        vector<char> current = vector<char>(N, 'W');
        for (int i = 0; i < N; ++i)
            cin >> wanted[i];
        dbg(wanted);
        char sequence;
        char looking;
        if (N == 1 && wanted[0] != 'W') {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < N - 1; ) {
            while(i < N && wanted[i] == 'W') {
                dbg("a");
                i++;
            }
            if (i == N)
                break;
            sequence = wanted[i];
            if (sequence == 'B')
                looking = 'R';
            else
                looking = 'B';
            dbg(sequence, looking, i);
            if (i > 0 && wanted[i - 1] == looking) {
                while(i < N && wanted[i] == sequence) 
                    i++;
                continue;
            }
            else 
                i++;
            while(i < N && wanted[i] == sequence) 
                i++;
            if (i == N || wanted[i] != looking) {
                dbg("b");
                ok = false;
                break;
            }
            dbg(i);
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
