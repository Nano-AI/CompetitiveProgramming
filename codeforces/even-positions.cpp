#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l;
        string rbs;
        cin >> rbs;
        int i = l / 2 - 1;
        int j = l / 2;
        int count = l / 2;
        int energy = 0;
        while (count > 0 && i >= 0 && j < l) {
            cout << rbs << " " << i << " " << j << endl;
            if (rbs[i] != '_' && rbs[j] == '_') {
                rbs[j] = (rbs[i] == ')' ? '(' : ')');
                energy += j - i;
                i--;
                count--;
            }
            if (rbs[j] != '_' && rbs[i] == '_') {
                rbs[i] = (rbs[j] == ')' ? '(' : ')');
                energy += j - i;
                j++;
                count--;
            }
            if (rbs[i] != '_') {
                i--;
            }
            if (rbs[j] != '_') {
                j++;
            }
        }
        cout << rbs << ": " << energy << endl;
    }
    /**
     * _(_)_(_)
     * (())(())
     */
    return 0;
}
