#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long int

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        ll n, B, x, y;
        cin >> n >> B >> x >> y;
    
        ll sum = 0;
        ll ai = 0;
        for(int i = 1; i <= n; i++) {
            ll ai_x = ai + x;
            ll ai_y = ai - y;
            if (ai_x <= B) {
                ai = ai_x;
                sum += ai;
            }
            else {
                ai = ai_y;
                sum += ai;
            }
        }
        cout << sum << endl;
    }
}
