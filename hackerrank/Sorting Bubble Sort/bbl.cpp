#include <bits/stdc++.h>
using namespace std;
void countSwaps(vector<int> a) {
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]); 
                c++;
            }
        }
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d", c, a[0], a[a.size() - 1]);
}
