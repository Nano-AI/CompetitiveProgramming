// https://codeforces.com/contest/1872/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<vector<int>> v(size);

	for (vector<int> &a : v) {
		for (int i = 0; i < 3; i++) {
			int n;
			cin >> n;
			a.push_back(n);
		}
	}

	for (vector<int> &a : v) {
		int moves = 0;
		cout << ceil(abs(a[0] - a[1]) / (2.0 * a[2])) << endl;
	}

	return 0;
}
