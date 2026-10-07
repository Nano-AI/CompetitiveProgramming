#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        long m, n, k;
        cin >> n >> m >> k;
        // p is permutation array
        // g[i] is sum of numbers in permutations on length i that are not greater than m
        // f[i] is sum of numbers in permutations on length i that are not less than k 
        vector<long> output(n, 0);

        int j = 0;
        for (int i = n; i >= k && j < n; i--) {
            output[j] = i;
            j++;
        }

        j = n - m;
        for (int i = 1; i <= m && j < n; i++) {
            output[j] = i;
            j++;
        }

        j = n - k + 1;
        for (int i = m + 1; i < k; i++) {
            output[j] = i;
            j++; 
        }

        for (int v : output) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}