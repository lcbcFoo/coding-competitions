#include <functional>
#include <iostream>
#include <map>

#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <string>

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
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<string> ns = vector<string>(N);
        for (int i = 0; i < N; ++i) {
            cin >> ns[i];
        }
        bool solved = false;

        for (char starting = 'A'; starting < 'Z' && !solved; ++starting) {
            solved = true;
            string ans;
            char current = starting;
            set<int> used;
            while (used.size() < N && solved) {
                set<int> candidate;
                for (int i = 0; i < N; ++i) {
                    if (ns[i][0] != current)
                        continue;
                    else if (used.find(i) == used.end()){
                        candidate.insert(i);
                    }
                }
                if (candidate.empty()) {
                    for (int i = 0; i < N; ++i) {
                        if (used.find(i) == used.end()) {
                            current = ns[i].front();
                            break;
                        }
                    }
                    continue;
                }
                int special = -1;
                dbg(candidate);
                for (auto i: candidate) {
                    string a = ns[i];
                    char c = a[0];
                    bool uniq = true;
                    for (int j = 0; j < a.size(); ++j) {
                        if (a[j] != c) {
                            if (special != -1) {
                                solved = false;
                                break;
                            }
                            else {
                                special = i;
                                uniq = false;
                            }
                        }
                    }
                    if (uniq) {
                        used.insert(i);
                        ans += a;
                    }
                }
                dbg(special);
                if (special != -1) {
                    used.insert(special);
                    ans += ns[special];
                }
                current = ans[-1];
                dbg(ans);
                dbg(used);
            }
            set<char> seen;
            current = ans.front();
            seen.insert(current);
            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i] != current) {
                    if (seen.find(ans[i]) == seen.end()) {
                        current = ans[i];
                        seen.insert(current);
                    }
                    
                    else {
                        solved = false;
                    }
                }
            }
            if (!solved)
                cout << "IMPOSSIBLE" << endl;
            else
                cout << ans << endl;
        }
    }
}
