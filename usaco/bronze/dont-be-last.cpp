#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> c;

int main() {
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string n;
		int a;
		cin >> n >> a;

		if (c.find(n) == c.end()) {
			c[n] = a;
		} else {
			c[n] += a;
		}
	}

	vector<pair<string, int>> cv;

	for (auto p : c) {
		cv.push_back(p);
	}

	if (m == 1) {
		cout << cv[0].first << endl;
		return 0;
	}

	sort(cv.begin(), cv.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
		return a.second > b.second;
	});

	int size = cv.size();
	int sm = cv[size - 1].second;
	bool passed = false;
	string name;

	for (int i = size - 1; i >= 0; i--) {
		if (cv[i].second == sm) {
			if (!passed)
				continue;
			else {
				passed = false;
				break;
			}
		}
		if (passed) break;
		sm = cv[i].second;
		name = cv[i].first;
		passed = true;
	}
	
	if (!passed) {
		cout << "Tie" << endl;
	} else {
		cout << name << endl;
	}

	return 0;
}

