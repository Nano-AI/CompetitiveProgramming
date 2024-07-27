#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(k);
        for (int& v : c) {
            cin >> v;
        }
        /**
         * 5, 3 -> 5 meters long, 3 pieces
         * 3 1 1
         * 1) 4 1
         * 2) 5
         * 
         * 5, 2
         * 3 2
         * 1) 3 1 1
         * 2) 4 1
         * 3) 5
         * 
         * 11 4
         * 2 3 1 5
         * 1) 2 3 6
         * 2) 1 1 3 6
         * 3) 1 1 2 1 6
         * 4) 1 1 1 1 1 7
         * 5) 1 1 1 1 8
         * 6) 1 1 1 9
         * 7) 1 1 10
         * 8) 1 11
         * 9) 12
         * 
         * 3 -> 2 1 -> 1 1 1
         * 5 -> 4 1 -> 3 1 1 -> 2 1 1 1 -> 1 1 1 1 1
         * 6 1 1 -> 7 1 -> 8
         */
        int greatest_index = 0;
        for (int i = 0; i < k; i++) {
            greatest_index = c[i] > c[greatest_index] ? i : greatest_index;
        }
        // sort(c.begin(), c.end(), greater<int>());
        int ops = 0;
        // for (int i = k - 1; i >= 1; i--) {
        for (int i = 0; i < k; i++) {
            if (i == greatest_index) continue;
            // cout << "breaking down " << c[i] << " into " << c[i] - 1 << " different parts and adding it up through " << c[i] << "steps" << endl;
            ops += 2 * c[i] - 1; // ops to break it down & add them
            c[greatest_index] += c[i];
        }
        cout << ops << endl;
    }
    return 0;
}