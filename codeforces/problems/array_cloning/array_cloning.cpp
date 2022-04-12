#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

#define ll long long int
#define ull long long unsigned int

using namespace std;


/*
 *
 * Count elements  in array
 * Returns a map of all elements and their frequencies
 *
 */

template<class T>
std::map<T, ull> count_elements(std::vector<T> v) {
    std::map<T, ull> counters = std::map<T, ull>();
    for(auto i: v)
    {
        ++counters[i];
    }
    return counters;
}

/*
 *
 * Find the mode of a vector and its frequency
 * Return a pair of the mode of a vector and its frequency
 * Requires count_elements
 *
 */

template<class T>
std::pair<const int, long long unsigned int> vector_mode(std::vector<T> v) {
    auto frequency_count = count_elements<T>(v);
    auto pr = std::max_element
    (
        std::begin(frequency_count), std::end(frequency_count),
        [] (auto & p1, auto & p2) {
            return p1.second < p2.second;
        }
    );
    return *pr;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<ll> v = vector<ll>(N);
        for (int i = 0; i < N; ++i)
            cin >> v[i];
        ull count = vector_mode(v).second;
        ull swap = count;
        ull ops = 0;
        while(swap < N) {
            ops += 1 + min(N - swap, swap);
            swap *= 2;
        }
        cout << ops << endl;
    }
}
