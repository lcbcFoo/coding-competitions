
#include <cmath>
#include <functional>
#include <iostream>
#include <map>

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <iomanip>

/* #define DEBUG */

#ifdef DEBUG
#include "../../../debug.hpp"
#else
#define dbg(...)
#endif

#define ll long long int
#define ull long long int

using namespace std;

bool is_palind(string s) {
    int l = 0, r = s.size() - 1;
    
    while (l <= r) {
        if (s[l] != s[r])
            return false;
        l++; r--;
    }
    return true;
}

int main() {
    int n; cin >> n;
    int i;
    for(i=1;i*i<n;i++){           
        if(n%i==0){                
            cout<<i<<" ";
        }
    }
    for( ;i>=1;i--){             
      if(n%i==0){               
          cout<<(n/i)<<" ";
      }
    }
}
