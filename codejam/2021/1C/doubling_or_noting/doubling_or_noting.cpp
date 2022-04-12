#include <iostream>
#include <algorithm>
#include <math.h>
#include <bitset>

using namespace std;

void execute();

#define MAX_N 2 * 2
#define MAX_BITS 10

unsigned int T;
bitset<MAX_BITS> A = 0;
bitset<MAX_BITS> B = 0;

int main() {
    cin >> T;

    for (int test = 0; test < T; ++test) {
        string inp_a, inp_b;
        cin >> A;
        cin >> B;
        cout << A.to_string() << endl;
        cout << B.to_string() << endl;
        cout << "Case #" << test + 1 << ": ";
        execute();
        cout << endl;
    }
}

unsigned int _solve(bitset<MAX_BITS> a, bitset<MAX_BITS> b, int depth) {
    cout << "a: " << a << ", b: " << b << endl; 
    if (depth > MAX_N)
        return MAX_N + 1;
    if (a == b)
        return depth;
    bitset<MAX_BITS> not_a;
    if (a == 0)
        not_a = bitset<MAX_BITS>(1);
    else {
        
    }

    unsigned int ns = _solve(~a, b, depth + 1);
    unsigned int ds = _solve(a << 1, b, depth + 1); 

    return ns < ds ? ns : ds;
}

void execute() {
    unsigned int best = _solve(A, B, 0);
    if (best > MAX_N) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << best << endl;
    }
}
