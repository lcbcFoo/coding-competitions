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
#include "../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

typedef struct _stack_t {
    string c;
    _stack_t* next;
} stack_p_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    stack_p_t* root = nullptr;
    stack_p_t* last = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int inp;
        cin >> inp;
        if (inp == 1) {
            stack_p_t* st = new stack_p_t();
            string s;
            cin >> s;
            st->c = s;
            st->next = nullptr;
            if (root == nullptr)
                root = st;
            if (last == nullptr)
                last = st;
            else {
                last->next = st;
                last = st;
            }
            dbg(root);
            dbg(last);
        }
        else {
            cout << root->c << endl;
            stack_p_t* tmp = root;
            root = root->next;
            last->next = tmp;
            last = tmp;
        }
    }
}
