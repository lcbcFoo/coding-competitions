#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <vector>
#include <bitset>
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

uint8_t first_try() {
    return 0xff;
}

void p_char(uint8_t p) {
    cout << bitset<8>(p).to_string() << endl;
}

set<uint8_t> tries;

uint8_t new_c(uint8_t last, int n) {
    uint8_t a = 0;
    set<int> idxs;
    do {
        for (int i = 0; i < n; ++i) {
            int tmp;
            do {
                tmp = rand() % 8;
            } while(idxs.find(tmp) != idxs.end());
            idxs.insert(tmp);
        }
        for (auto i: idxs) {
            a |= 1 << i;
        }
    } while (tries.find(a) != tries.end());
    dbg(bitset<8>(a).to_string());
    return a;
}

int main() {
    int T;
    cin >> T;
    srand(time(NULL));
    for (int t = 0; t < T; ++t) {
        int m_tries = 300;
        uint8_t last_try = first_try();
        bool first_Try = true;
        p_char(last_try);
        tries = set<uint8_t>();
        while (m_tries--) {
            int inp;
            cin >> inp;
            if (inp == 0)
                break;

            if (inp < 4)
                inp = 8 - inp;
            uint8_t a = new_c(last_try, inp);
            p_char(a);
            last_try = a;
        }
    }
}
