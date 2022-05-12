#include <bits/stdc++.h>
using namespace std;

#include "../../../debug.hpp"

long long solve(long long x) {
    string s = to_string(x);
    int n = (int) size(s);

    vector ways(n + 1, vector(99 + 1, vector(99 + 1, vector(2, vector<long long>(2)))));
    for (int i = 1; i <= 99; ++i) ways[0][i][i][0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 99; ++j) {
            for (int k = 0; k <= 99; ++k) {
                for (bool l : {false, true}) {
                    for (int digit = 0; digit <= 9 && k - digit >= 0; ++digit) {
                        bool l_new = l || digit > 0;
                        int j_new = l_new ? j / gcd(j, digit) : j;
                        if (digit <= s[i] - '0') {
                            ways[i + 1][j_new][k - digit][l_new][digit < s[i] - '0'] += ways[i][j][k][l][0];
                        }
                        ways[i + 1][j_new][k - digit][l_new][1] += ways[i][j][k][l][1];
                    }
                }
            }
        }
    }

    dbg(ways);

    long long ans = 0;
    for (auto i : {false, true})
        for (auto j : {false, true})
            ans += ways[n][1][0][i][j];

    return ans;
}

void solve() {
    long long a, b; cin >> a >> b;
    cout << solve(b) - solve(a - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
