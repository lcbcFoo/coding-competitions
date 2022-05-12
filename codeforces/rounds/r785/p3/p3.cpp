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

const long long MOD = 1000000007;

/* vector<int> palinds = {1, 2, 3, 4, 5, 6, 7, 8, 9}; */
vector<ll> palinds;

int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;
 
    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;
 
    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
 
// Function to print decimal palindromic number
void generatePalindromes(int n)
{
    int number;
 
    // Run two times for odd and even length palindromes
    for (int j = 0; j < 2; j++)
    {
        // Creates palindrome numbers with first half as i.
        // Value of j decided whether we need an odd length
        // of even length palindrome.
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            palinds.push_back(number);
            i++;
        }
    }
}

vector<vector<ll>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    ll N = 40001;
    generatePalindromes(N);
    sort(palinds.begin(), palinds.end());
    dbg(palinds);
    ll M = palinds.size();
    for(int i = 0; i <= N; ++i)
        dp.push_back(vector<ll>(M + 1, -1));
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < M; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        ll k = i + 1;
        for (int m = 1; m < M; ++m) {
            ll pm = palinds[m];
            if (pm > i) {
                dp[i][m] = dp[i][m - 1];
                continue;
            }
            dp[i][m] = (dp[i - pm][m] + dp[i][m - 1]) % MOD;
        }
    }
    while (T--) {
        ll N;
        cin >> N;
        /* total = gen_ps(N, M - 1); */
        ll total = dp[N][M - 1];
        cout << total << endl << flush;
    }
}
