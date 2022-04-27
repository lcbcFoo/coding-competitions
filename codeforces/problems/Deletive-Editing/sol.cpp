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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string a, b;
        cin >> a >> b;
        int a_i = a.size() - 1;
        int first;
        bool ok = true;
        map<char, int> counter;
        for (int i = 0; i < b.size(); ++i) {
            if (counter.find(b[i]) == counter.end())
                counter.insert({b[i], 0});
            else
                counter[b[i]] += 1;
        }
        for (int i = b.size() - 1; ok && i >= 0; --i) {
            dbg(a_i, i);
            if (a_i == -1) {
                ok = false;
                break;
            }
            while (a_i >= 0) {
                if (a[a_i] == b[i]) {
                    a_i--;
                    break;
                }
                if (b.find_first_of(a[a_i]) < i && b.find(a[a_i], i) == string::npos){
                    ok = false;
                    break;
                }
                a_i--;
            }
            if (i == b.size() - 1)
                first = a_i + 1;
            dbg(a_i);
        }
        dbg(ok);
        a_i = first + 1;
        while (ok && a_i > 0 && a_i < a.size()) {
            dbg(a[a_i]);
            if (b.find_first_of(a[a_i]) != string::npos) {
                ok = false;
                break;
            }
            a_i++;
        }
        if (!ok) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}
