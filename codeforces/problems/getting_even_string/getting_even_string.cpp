#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        string input;
        cin >> input;
        if (input.length() == 1) {
            cout << 1 << endl;
            continue;
        }
        int count = 0;
        int prev_idx = 0;
        int i = 0;
        bool done = false;
        while (i < input.length()) {
            /* cout << "part1: " << i << endl; */
            while(i < input.length() - 1 && input[i] == input[i + 1])
                i += 2;
            if (i >= input.length()) {
                done = true;
                break;
            }
            if (i == input.length() - 1) {
                count++;
                break;
            }
            prev_idx = i;
            set<char> seen;
            seen.insert(input[prev_idx]);
            i++;
            /* cout << "part2: " << i << endl; */
            while(i < input.length() && seen.find(input[i]) == seen.end()) {
                seen.insert(input[i]);
                i++;
            }
            if (seen.find(input[i]) != seen.end())
                count += i - prev_idx - 1;
            else
                count += i - prev_idx;
            i++;
        }
        cout << count << endl;
    }

}
