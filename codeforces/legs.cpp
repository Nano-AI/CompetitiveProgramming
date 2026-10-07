#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cows = n / 4;
        if (cows > 0) {
            n -= cows * 4; 
        }
        int chickens = n / 2;
        cout << cows + chickens << endl;
    }
    return 0;
}