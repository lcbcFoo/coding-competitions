#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            cout << 0 << endl;
            continue;
        }
        double d = sqrt(x * x + y * y);
        if (ceil(d) == floor(d))
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
} 
