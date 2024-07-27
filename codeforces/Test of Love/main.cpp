#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        unsigned long long n, m, k; // legth of river, distance of jump, swim distance
        cin >> n >> m >> k;

        string river; // river
        cin >> river;
        
        // create array to keep track of how many spots required to make a jump
        unsigned long long swim[n + 1];
        // set the last one to zero b/c that's the dock
        swim[n] = 0;

        // start backwards to calculate the swim distance required
        for (int i = n - 1; i >= 0; i--) {
            // if it's a log, we should pick the minumum value between (i, min(i + m, n)]
            // to iterate over the points & pick the smallest one.
            // this is the min swim value to go from the log to the next place
            if (river.at(i) == 'L') {
                unsigned long long min_val = swim[i + 1];
                for (int j = 1; j <= m && i + j <= n; j++) {
                    min_val = min(min_val, swim[i + j]);
                }
                swim[i] = min_val;
            }
            // if it's water, add one from the previous array because it'll require 1 swim point
            if (river.at(i) == 'W') {
                swim[i] = swim[i + 1];
                if (swim[i] < numeric_limits<unsigned long long>::max()) {
                    swim[i]++;
                }
            }
            // if it's a crock just set it to the max value
            // we can't actually swim through it
            if (river.at(i) == 'C') {
                swim[i] = numeric_limits<unsigned long long>::max(); 
            }
        }

        bool possible = false;
        // iterate through [0, m) to check for values where it's within the acceptable swim level
        // if it exists, then print yes, otherwise no.
        for (int i = 0; i < m; i++) {
            if (swim[i] <= k) {
                possible = true;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}