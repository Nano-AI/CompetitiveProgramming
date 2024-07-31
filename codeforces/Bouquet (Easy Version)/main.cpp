#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1995/B1

void solve(int m, vector<int> flowers) {
    /**
     * 1, 1, 1, 2, 4, 5, 6, 7
     *          i
     *             j
     *          l
     */
    sort(flowers.begin(), flowers.end());
    int n = flowers.size();

    /**
     * 1 1 1 2 4 5 6 7
     * l
     *       r
     * 
     *       l
     *       r 
     * s = 5
     */

    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         int left = flowers[i];
    //         int right = flowers[j];
    //         if (right - left > 1) {
    //             break;
    //         }
    //         int s = sum[i] + flowers[j];
    //         if (s <= m) {
    //             sum[i] = s;
    //         }
    //     }
    // }

    int i = 0;
    int j = 0;
    int sum = 0;
    int biggest = 0;
    while (i < n && j < n) {
        int left = flowers[i];
        int right = flowers[j];
        int diff = right - left;
        if (diff <= 1 ){
            if (sum + right <= m) {
                sum += right;
                j++;
            }
        }
    }
    cout << biggest << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; // # of flowers, # of coins
        cin >> n >> m;
        vector<int> flowers(n);
        for (int& v : flowers) {
            cin >> v;
        } 
        solve(m, flowers);
    }
    return 0;
}