#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;


/* int main() { */
/*     ios::sync_with_stdio(false); */
/*     cin.tie(0); */

/*     int N; */
/*     cin >> N; */
/*     vector<int> numbers = vector<int>(N); */
/*     for (int i = 0; i < N; ++i) { */
/*         cin >> numbers[i]; */
/*     } */
/*     sort(numbers.begin(), numbers.end()); */
/*     long int best = 0; */
/*     bool possible = true; */
/*     for (int i = N - 1; i >= 0 && possible; ) { */
/*         set<int> forbidden = set<int>(); */
/*         long int sum = 0; */
/*         for (int j = i; j >= 0; --j) { */
/*             /1* cout << numbers[j] << endl; *1/ */
/*             if (forbidden.find(numbers[j]) == forbidden.end()) { */
/*                 /1* cout << "using " << numbers[j] << endl; *1/ */
/*                 forbidden.insert(numbers[j] - 1); */
/*                 forbidden.insert(numbers[j] + 1); */
/*                 sum += numbers[j]; */
/*             } */
/*         } */
/*         int k = i; */
/*         while (numbers[k] == numbers[i]) */
/*             k--; */
/*         i = k; */
/*         possible = numbers[i] * (i + 1) > best; */
/*         /1* cout << "sum: " << sum << endl; *1/ */
/*         best = max(best, sum); */
/*     } */
/*     cout << best << endl; */
/* } */


long long int f(map<int, long long int> cnt, int i) {

    if (i == 0 || i == 1) return cnt.find(i)->second * i;
    return max(f(cnt, i - 1), f(cnt, i - 2) + cnt.find(i)->second * i);

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
    int i = 0;
    int max_number = *max_element(numbers.begin(), numbers.end());
    vector<long long int> counters = vector<long long int>(max_number + 1, 0);
    sort(numbers.begin(), numbers.end());
    for (int i = 1, n_idx = 0; i <= max_number; ++i) {
        long long int counter = 0;
        int n = numbers[n_idx];
        /* cout << n_idx << endl; */
        while(n_idx < N && numbers[n_idx] == i) {
            counter++;
            n_idx++;
        }
        if (i == 1) counters[i] = counter * n;
        else { 
            long long int v = 
                max(counters[i - 2] + counter * n,
                    counters[i - 1]);
            counters[i]  = v;
        }
    }
    /* cout << endl; */
    /* for (auto i : counters) */
    /*     cout << i << " "; */
    /* cout << endl; */
    long long int best = counters[max_number];
    cout << best << endl;
}
