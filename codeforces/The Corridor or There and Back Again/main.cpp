// https://codeforces.com/contest/1872/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<vector<pair<int, int>>> cases(size);

	for (auto &c : cases) {
		int l;
		cin >> l;
		c.resize(l);
		for (auto &p : c) {
			cin >> p.first >> p.second;
		}
	}

	for (auto c : cases) {
		int min_time = INT_MAX;
		for (auto p : c) {
			min_time = min(min_time, p.first + (int) ceil(0.5 * p.second - 1));
		}
		cout << min_time << endl;
	}

	return 0;
}
