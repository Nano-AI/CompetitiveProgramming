#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<int> first(n);
        vector<int> second(n);
        ll rating1 = 0;
        ll rating2 = 0;
        for (int& v : first) {
            cin >> v;
        }
        for (int& v : second) {
            cin >> v;
        }
        for (int i = 0; i < n; i++) {
            if (first[i] > second[i]) {
                rating1 += first[i];
            } else if (second[i] > first[i]) {
                rating2 += second[i];
            } else {
                continue;
            }
        }
        for (int i = 0; i < n; i++) {
            if (first[i] != second[i]) {
                continue;
            }
            if (first[i] == -1) {
                if (rating1 < rating2) {
                    rating2--;
                } else {
                    rating1--;
                }
            } else if (first[i] == 1) {
                if (rating1 < rating2) {
                    rating1++;
                } else {
                    rating2++;
                }
            }
        }
        cout << min(rating1, rating2) << endl;
    }
    return 0;
}