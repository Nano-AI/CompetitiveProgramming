#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> a) {
    /**
     * 1, 2
     * 1, 1
     * 3, 3, 3
     * 1, 2, 3, 4, 5, 5
     * 3, 3, 4, 4
     * 1, 2, 2, 2
     */
    bool found = false;
    for (int i = 0; i < a.size(); i++) {
        int possible_moves = 0;
        for (int j = 0; j < a.size(); j++) {
            if (i == j) continue;
            if (a[i] <= a[j]) possible_moves++;
        }
        if (possible_moves % 2 == 0) {
            cout << "YES" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        vector<int> a(s);
        for (int& i : a) {
            cin >> i;
        }
        solve(a);
    }
    return 0;
}
