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

unsigned long long int put_digits(unsigned long long int number, unsigned long long int append) {
    /* cout << "number: " << number << ", idx: " << idx << ", d: " << d<< endl; */
    int d = num_digits(append);
    unsigned long long int mult = (unsigned long long int) powl(10, d - 1);
    int i = d;
        while (i-- > 0) {
            cout << "append: " << append << ", mult: " << mult << endl;
        if (d == 1) {
            number = number * 10 + append;
            break;
        }
        else {
            number = number * 10 + append / mult;
            append = append % mult;
            mult /= 10;
        }
    }
    return number;
}

long long int find_next_roaring(long long int target) {

    unsigned long long int best = 10e18;
    unsigned long long int current = 0;
    int n = num_digits(target) / 2;

    for (int group = 1; group < n; ++group) {
        current = put_digits(current, i);
        cout << current << endl;
    }

    return best;
}


void execute() {
    unsigned long long int roar = find_next_roaring(Y)   ;
    /* cout << "---------------------------------" << endl; */
    cout << roar;
    /* cout << "---------------------------------" << endl; */

}
