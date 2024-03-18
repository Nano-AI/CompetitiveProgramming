#include <bits/stdc++.h>
using namespace std;



int main() {
	string w;
	cin >> w;
	int s = w.length();
	int m = 0;
	int l = 0;
	int r = 0;
	while (l <= r && r <= s) {
		if (w[l] == w[r]) {
			r++;
		} else {
			m = max(r - l, m);
			l = r;
		}
	}
	cout << m;
	return 0;
}
