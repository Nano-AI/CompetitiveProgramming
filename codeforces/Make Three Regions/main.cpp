#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
// unfinished

int main() {
    int t;
    cin >> t;
    /**
     * xxxxx..xxxxxx
     * .....x.......
     */
    while (t--) {
        ull n;
        cin >> n;
        vector<vector<char>> grid(2, vector<char>(n + 2)); 
        grid[0][0] = true;
        grid[1][0] = true;
        grid[0][n - 1] = true;
        grid[1][n - 1] = true;
        for (int i = 0; i <= 1; i++) {
            for (ull j = 1; j < n - 1; j++) {
                cin >> grid[i][j];
            }
        }
        ull i = 1;
        int count = 0;
        /**
         * 1) x . x
         *    . . .
         * 
         * 2) . . .
         *    x . x
         * 
         * 3) x . .
         *    . . x
         * 
         * 4) . . x
         *    x . .
         * 
         * 5) x . . . . x 
         *    . x . x x .
         */
        while (i < n - 1) {

        }
        cout << count << endl;
    }
    return 0;
}