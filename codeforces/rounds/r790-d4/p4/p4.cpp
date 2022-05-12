#include <cstring>
#include <functional>
#include <iostream>
#include <map>

#include <vector>
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


ll matrix[200][200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M; cin >> N >> M;
        memset(matrix, 0, N * M);
        for (int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                cin >> matrix[i][j];

        ll sum = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int idxi = i;
                int idxj = j;
                ll tmp = 0;
                while(idxi < N && idxj < M) tmp += matrix[idxi++][idxj++];
                idxi = i - 1;
                idxj = j - 1;
                while(idxi >= 0 && idxj >= 0) tmp += matrix[idxi--][idxj--];
                idxi = i - 1;
                idxj = j + 1;
                while(idxi >= 0 && idxj < M) tmp += matrix[idxi--][idxj++];
                idxi = i + 1;
                idxj = j - 1;
                while(idxi < N && idxj >= 0) tmp += matrix[idxi++][idxj--];
                sum = max(sum, tmp);
            }
        }
        cout << sum << endl;

        /* vector<ll> diags_down = vector<ll>(N + M - 1, 0); */
        /* vector<ll> diags_up = vector<ll>(N + M - 1, 0); */
        /* // for all possible start positions */
        /* int start_row = N - 1; */
        /* int start_col = 0; */
        /* int column = 0; */
        /* int idx = 0; */
        /* do { */
        /*     // set the row and column values to the start values */
        /*     int row = start_row; */
        /*     column = start_col; */
            
        /*     //Now go through the diagonal */
        /*     do { */
        /*         // Show current value */
        /*         diags_down[idx] += matrix[row][column]; */

        /*         // Set next position in the diagonal */
        /*         ++row;      // Go one row down */
        /*         ++column;   // Go one column to the right */

        /*       // As long as we do not cross the border */
        /*     } while ((row < N) && (column < M)); */

        /*     idx++; */
        /*     // Calculate new start row and start column */
        /*     // If possible */
        /*     if (start_row > 0) { */
        /*         // Go up */
        /*         --start_row; */
        /*     } */
        /*     else { */
        /*         // Else go right */
        /*         ++start_col; */
        /*     } */
        /* } while (start_col < M); */
        /* start_row = 0; */
        /* start_col = 0; */
        /* int row; */
        /* idx = 0; */
        /* do { */
        /*     // set the row and column values to the start values */
        /*     int column = start_col; */
        /*     row = start_row; */
            
        /*     //Now go through the diagonal */
        /*     do { */
        /*         // Show current value */
        /*         diags_up[idx] += matrix[row][column]; */

        /*         // Set next position in the diagonal */
        /*         --row;      // Go one row down */
        /*         ++column;   // Go one column to the right */

        /*       // As long as we do not cross the border */
        /*     } while ((row >= 0) && (column < M)); */

        /*     idx++; */
        /*     // Calculate new start row and start column */
        /*     // If possible */
        /*     if (start_row < N - 1) { */
        /*         ++start_row; */
        /*     } */
        /*     else { */
        /*         ++start_col; */
        /*     } */
        /* } while (start_col < M); */
        /* dbg(diags_down, diags_up); */

        /* ll ma = 0; */
        /* for (int i = 0; i < N + M - 1; ++i) { */
        /*     for (int j = i % 2 == 0 ? 1 : 0; j < N + M - 1; j += 2) { */
        /*         int idxi, idxj; */
        /*         if (i < j) { */
        /*             idxi = (i + j - 1) % N; */
        /*             idxj = (i + j - 1) % M; */
        /*         } */
        /*         else { */
        /*             idxj = (i + j - 1) % M; */
        /*             idxi = (i + j - 1) % N; */
        /*         } */
        /*         ll tmp = diags_down[i] + diags_up[j] - matrix[idxi][idxj]; */
        /*         if (tmp > ma) { */
        /*             ma = tmp; */
        /*             dbg(ma, i, j, idxi, idxj); */
        /*         } */
        /*     } */
        /* } */
        /* cout << ma << endl; */
    }
}
