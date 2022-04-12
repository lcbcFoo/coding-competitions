#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void execute();

#define MAX_N 30

unsigned int T;
unsigned int N;
unsigned int K;
unsigned int tickets[MAX_N + 1];


int main() {
    cin >> T;

    for (int test = 0; test < T; ++test) {
        cin >> N;
        cin >> K;
        cout << "Case #" << test + 1 << ": ";
        execute();
        cout << endl;
    }
}

void execute() {
    for (int i = 0; i < N; ++i) {
        cin >> tickets[i];
    }
    sort(tickets, tickets + N);

    int best = 0;
    int sec_best = 0;
    for (int idx = 0; idx < N - 1; ++idx) {
        int diff = tickets[idx + 1] - tickets[idx] - 1;
        if (diff > best) {
            sec_best = best;
            best = diff;
        }
        else if (diff > sec_best) {
            sec_best = diff;
        }
    }
    bool use_only_best = false;
    if (best > sec_best && best - (best / 2) > sec_best / 2) {
        use_only_best = true;
    }
    int last_chunk = (K - tickets[N - 1]);
    int first_chunk = tickets[0] - 1;
    /* cout << "best: " << best << std::endl; */
    /* cout << "sec_best: " << sec_best << std::endl; */
    /* cout << "last_chunk: " << last_chunk << std::endl; */

    if (use_only_best) {
        if (last_chunk >= ceil(best / (double) 2)) {
            //cout ";
            if (first_chunk >= ceil(best / (double) 2)) {
                //cout ";
                double chance = (last_chunk + first_chunk) / (double) K;
                cout << chance;
                return;
            }
            else {
                //cout ";
                double chance = (last_chunk + ceil(best / (double)2)) / (double) K;
                cout << chance;
                return;
            }
        }
        else if (first_chunk >= ceil(best / (double) 2)) {
            //cout ";
            double chance = (first_chunk + ceil(best / (double)2)) / (double) K;
            cout << chance;
            return;
        }
        else {
            //cout ";
            /* //cout "; */
            double chance = (best) / (double) K;
            cout << chance;
            return;
        }
    }
    else {
        if (last_chunk >= ceil(best / (double) 2)) {
            if (first_chunk > ceil(best / (double) 2)) {
                //cout ";
                double chance = (last_chunk + first_chunk) / (double) K;
                cout << chance;
                return;
            }
            else {
                //cout ";
                double chance = (last_chunk + ceil(best / (double)2)) / (double) K;
                cout << chance;
                return;
            }
        }
        else if (first_chunk >= ceil(best / (double) 2)) {
            //cout ";
            double chance = (first_chunk + ceil(best / (double)2)) / (double) K;
            cout << chance;
            return;
        }
        int higher = first_chunk > last_chunk ? first_chunk : last_chunk;
        if (higher >= ceil(sec_best / (double)2)) {
            //cout ";
            double chance = (ceil(best / (double)2) + higher) / (double) K;
            cout << chance;
            return;
        }
        else {
            //cout ";
            double chance = (ceil(best / (double)2) + ceil(sec_best / (double)2)) / (double) K;
            cout << chance;
            return;
        }
    }
}
