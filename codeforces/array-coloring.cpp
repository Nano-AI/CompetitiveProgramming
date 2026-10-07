// https://codeforces.com/contest/1857/problem/A
#include <bits/stdc++.h>
using namespace std;

bool even(int n) {
	return n % 2 == 0;
}

bool odd(int n) {
	return !even(n);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int an;
		cin >> an;
		int sum = 0;
		int os = 0;
		int es = 0;
		for (int j = 0; j < an; j++) {
			int numb;
			cin >> numb;
			sum += numb;
			if (numb % 2 == 0) {
				es++;
			}
			else {
				os++;
			}
		}
		if (even(os)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
