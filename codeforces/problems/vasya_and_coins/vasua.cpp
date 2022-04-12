#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T;
    cin >> T;
    for (long long t = 0; t < T; ++t) {
        long long A, B;
        cin >> A >> B;

        long long used_a = 0, used_b = 0;
        bool done = false;
        long long common = min(A, B);
        if (A == 0) {
            cout << 1 << endl;
        }
        else {
            cout << 2 * B + A  + 1<< endl;
        }
        /* long long low_limit = 3 * common + 1; */
        /* while (!done) { */
        /*     /1* cout << "low: " << low_limit << endl; *1/ */
        /*     long long tmp = low_limit / 2; */
        /*     used_b = min(tmp, B); */
        /*     long long owned = low_limit - 2 * used_b; */
        /*     if (A >= owned) { */
        /*         low_limit++; */
        /*         continue; */
        /*     } */
        /*     else { */
        /*         cout << low_limit << endl; */
        /*         break; */
        /*     } */
        /* } */
    }
}
