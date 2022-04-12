#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>

using namespace std;
#define ll long long int

#define MAX (ll) 1e9

int main() {
    int T;
    cin >> T;
    srand (time(NULL));
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<ll> numbers = vector<ll>(2 * N);
        int i = 0;

        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(1, MAX); ;

        ll n = distr(gen);
        cout << n;
        numbers[i] = n;
        set<ll> used;
        used.insert(n);
        for (i = 1; i < N; ++i) {
            do {
                n = distr(gen);
            } while (used.find(n) != used.end());
            numbers[i] = n;
            used.insert(n);
            cout << " " << n;
        }
        cout << endl;
        while (i < 2 * N) {
            cin >> numbers[i++];
        }
        sort(numbers.begin(), numbers.end());
        vector<ll> selected = vector<ll>(2 * N, 0);
        ll compensate = 0;
        int res_idx = 0;
        for (int idx = 2 * N - 1; idx >= 0; idx--) {
            selected[res_idx++] = numbers[idx];
            compensate += numbers[idx];
            /* cout << "using: " << numbers[idx] << endl; */
            /* cout << compensate << endl; */
            while(compensate > 0 && idx > 0) {
                idx--;
                /* cout << "ignoring: " << numbers[idx] << endl; */
                compensate -= numbers[idx];
            }
        }
        ofstream myfile ("example.txt");
        for(int count = 0; count < res_idx; count ++){
            myfile << selected[count] << " " ;
        }
        myfile.close();
        /* cout << "end comp: " << compensate << ", sum sele: " << accumulate(selected.begin(), selected.end(), 0) << endl; */
        cout << selected[0];
        for (int i = 1; i <= res_idx; ++i) {
            if (selected[i] == 0)
                break;
            cout << " " << selected[i];
        }
        cout << endl;
    }
    return 0;
}
