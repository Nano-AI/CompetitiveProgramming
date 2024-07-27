#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    // a -> substring
    // b -> subsequence
    while (t--) {
        string a, b;
        cin >> a >> b;
        int i = 0, j = 0;
        int shared = 0;
        while (j < b.size()) {
            if (a[i] == b[j]) {
                shared++;
                j++;
            }
            i++;
        }
        cout << a.size() + b.size() - shared << endl;
    }
    return 0;
}