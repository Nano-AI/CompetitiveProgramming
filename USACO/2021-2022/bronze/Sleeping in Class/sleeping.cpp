// http://usaco.org/index.php?page=viewproblem2&cpid=1203
// i have no clue how this one works
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> ans(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
		sum += ans[i];
	}

	for (int mod = n; mod >= 1; mod--) {
		if (sum % mod == 0) {
			int target = sum / mod;
			int current = 0;
			bool valid = true;

			for (int i = 0; i < n; i++) {
				current += ans[i];
				if (current > target) {
					valid = false;
					break;
				}
				if (current == target) {
					current = 0;
				}
			}

			if (valid) {
				cout << n - mod << endl;
				return;
			}
		}
	}
}

int main() {
	int cases;

	cin >> cases;

	for (int i = 0; i < cases; i++) {
		solve();
	}

	return 0;
}
