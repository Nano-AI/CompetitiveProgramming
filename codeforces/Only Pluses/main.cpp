#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ull v[3];
        for (ull& n : v) {
            cin >> n;
        }
        ull maxVal = 0;
        for (int a = 0; a <= 5; a++) {
            for (int b = 0; a + b <= 5; b++) {
                for (int c = 0; a + b + c <= 5; c++) {
                    // cout << a << " " << b << " " << c << endl;
                    maxVal = max((v[0] + a) * (v[1] + b) * (v[2] + c), maxVal);
                }
            }
        }
        cout << maxVal << endl;
    }
    return 0;
}