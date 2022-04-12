#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>


using namespace std;

void execute();

#define MAX_N 19

unsigned int T;
long long int Y;
char roaring_years[MAX_N + 1];

int main() {
    cin >> T;

    for (int test = 0; test < T; ++test) {
        cin >> Y;
        cout << "Case #" << test + 1 << ": ";
        roaring_years[MAX_N] = '*';
        execute();
        cout << endl;
    }
}

unsigned long long int to_int();

int num_digits(long long int x) {
    return (x < 10 ? 1 :   
        (x < 100 ? 2 :   
        (x < 1000 ? 3 :   
        (x < 10000 ? 4 :   
        (x < 100000 ? 5 :   
        (x < 1000000 ? 6 :   
        (x < 10000000 ? 7 :  
        (x < 100000000 ? 8 :  
        (x < 1000000000 ? 9 :
        (x < 10000000000 ? 10 :
        (x < 100000000000 ? 11 :
        (x < 1000000000000 ? 12 :
        (x < 10000000000000 ? 13 :
        (x < 100000000000000 ? 14 :
        (x < 1000000000000000 ? 15 :
        (x < 10000000000000000 ? 16 :
        (x < 100000000000000000 ? 17 :
        18))))))))))))))))); 
}

void print_roar() {

    /* for (int i = 0; i < MAX_N; ++i) { */
    /*     cout << roaring_years[i]; */
    /* } */
    /* cout << endl; */
    unsigned long long int r = to_int();
    cout << r << endl;
}

unsigned long long int to_int() {
    unsigned long long int roar_year = 0;
    int i = 0;
    unsigned long long int mult = 1;
    while (roaring_years[i] == '-') {
        i++;
    }

    while (roaring_years[i] != '*') {
        roar_year += roaring_years[i] * mult;
        i++;
        mult *= 10;
    }
    return roar_year;
}

int put_digits(unsigned long long int number, int idx) {
    int d = num_digits(number);
    /* cout << "number: " << number << ", idx: " << idx << ", d: " << d<< endl; */
    while (d > 0 && idx >= 0) {
        if (d > 1) {
            roaring_years[idx] = number / (long long int) powl(10, d - 1);
        }
        else {
            roaring_years[idx] = number;
        }
        number = number % (long long int)pow(10, d - 1);
        idx--;
        d--;
    }
    /* print_roar(); */
    return idx;
}



long long int find_next_roaring(long long int target) {

    int n = num_digits(target);
    unsigned long long int best = 10e18;
    /* cout << "n: " << n << ", target: " << target << endl; */
    bool done = false;
    for (long long int i = 1; !done && num_digits(i) < n / 2; ) {
        /* cout << "i: " << i << endl; */
        int next_idx = MAX_N - 1;
        long long int roar = to_int();
        long long int next_n = i - 1;
        memset(roaring_years, '-', MAX_N)  ;
        bool not_finished_inner = true;
        do {
            next_n = next_n + 1;
            next_idx = put_digits(next_n, next_idx);
            roar = to_int();
            not_finished_inner = roar <= target && num_digits(next_n) < n / 2;
        } while(not_finished_inner);
        if (roar <= Y) {
            i++;
            continue;
        }
        /* cout << "roar: " << roar << endl; */
        if (roar < best) {
            best = roar;
            /* cout << "best: " << best << endl; */
        }
        if (Y < 10)
            done = true;

        i++;
    }

    return best;
}


void execute() {
    long long int roar = find_next_roaring(Y)   ;
    /* cout << "---------------------------------" << endl; */
    cout << roar;
    /* cout << "---------------------------------" << endl; */

}
