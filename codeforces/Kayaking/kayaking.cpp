#include <bits/stdc++.h>
using namespace std;

int main() {
	int s;
	cin >> s;
	vector<int> k(s * 2);
	vector<int> diffs(s * 2);

	for (int &v : k) {
		cin >> v;
	}

	int m = INT_MAX;

	for (int i = 0; i < k.size() - 1; i++) {
		for (int j  = i + 1; j < k.size(); j++) {
			int sum = 0;
			vector<int> v;
			for (int l = 0; l < k.size(); l++) {
				if (l != i && l != j) {
					v.push_back(k[l]);
				}
			}

			sort(v.begin(), v.end());

			for (int l = 0; l < v.size(); l += 2) {
				sum += v[l + 1] - v[l];
			}

			m = min(m, sum);
		}
	}

	cout << m << endl;
	return 0;
}

