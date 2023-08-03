// http://www.usaco.org/index.php?page=viewproblem2&cpid=963
#include <bits/stdc++.h>

using namespace std;

void useIO() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
}

int main() {
	useIO();
	int num_s;
	int num_cows;	


	cin >> num_s >> num_cows;

	vector<vector<int>> s(num_s);

	for (int i = 0; i < num_s; i++) {
		for (int j = 0; j < num_cows; j++) {
			int c;
			cin >> c;
			s[i].push_back(c);
		}
	}

	map<pair<int, int>, pair<int, bool>> v;		

	for (int i = 0; i < num_s; i++) {
		for (int j = 0; j < num_cows; j++) {
			for (int k = j + 1; k < num_cows; k++) {
				int c1, c2;
				c1 = s[i][j];
				c2 = s[i][k];

				int mi = min(c1, c2);
				int mx = max(c1, c2);

				if (v[{ mi, mx }].first == 0) {
					v[{ mi, mx }] = { c2, true };
				} else {
					pair<int, bool> c = v[{ mi, mx }];
					if (c2 != c.first) {
						v[{ mi, mx }].second = false;
					}
				}
			}
		}	
	}	

	int count = 0;

	for (auto const& x : v) {
		if (x.second.second) {
			count++;
		}
	} 

	cout << count << endl;


	return 0;
}
