#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
#define MAX 32768 

vector<int> cache = vector<int>(MAX, MAX);
int best = MAX;

int _solve(int n, bool doubled) {
    /* cout << "n: " << n << endl; */
    if (n == MAX) {
        return 0;
    }
    if (n > MAX) {
        if (doubled)
            return MAX;
        n = n % MAX;
        doubled = true;
    }
    if (cache[n] != MAX)
        return cache[n];
    return min(_solve(n + 1, doubled) + 1, _solve(n << 1, doubled) + 1);
}

int solve(int n) {
    best = MAX;

    int res = _solve(n, false);
    cache[n] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> numbers = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    for (int i = MAX, step = 0; i > 0; i = i / 2, step++) {
        cache[i] = step;
        cache[i - 1] = step + 1;
    }
    cache[0] = 0;
    cache[MAX] = 0;
    /* cache[MAX / 2] = 1; */
    /* cache[MAX - 1] = 1; */
    /* for (int i = 1; i < MAX; ++i) { */
    /*     solve(i); */
    /*     /1* cout << "i: " << i << ", c[i]: " << cache[i] << endl; *1/ */
    /* } */
    for (int i = 0; i < N; ++i) {
        solve(numbers[i]);
        if (i < N - 1)
            cout << cache[numbers[i]] << " ";
        else
            cout << cache[numbers[i]] << endl; 
    }
}
