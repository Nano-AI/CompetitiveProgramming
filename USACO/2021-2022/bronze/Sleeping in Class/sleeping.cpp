#include <bits/stdc++.h>

using namespace std;

int main() {
	int cases;

	cin >> cases;
	vector<vector<int>> v(cases);
	vector<int> sum(cases);

	for (int i = 0; i < cases; i++) {
		int l;
		cin >> l;
		int s = 0;
		for (int j = 0; j < l; j++) {
			int v1;
			cin >> v1;
			v[i].push_back(v1);
			s += v1;
		}
		sum[i] = s;
	}

	vector<vector<int>> avg(cases);

	for (int i = 0; i < cases; i++) {
		bool passed = false;
		int j;
		for (j = sum[i]; j > 1; j--) {
			if (sum[i] % j == 0) {
				avg[i].push_back(j);
			}
		}
	}


	vector<int> o(cases);	
	for (int i = 0; i < cases; i++) {
		int min_count = INT_MAX;
		int count = 0;
		int size = v[i].size();
		for (int val : avg[i]) {
			int j;
			for (j = 0; j < size - 1; j++) {
				vector<int> at = v[i];
				if (at[j] < val) {
					if (at[j + 1] > 0) {
						cout << "swa'" << endl;
						int minus = val - at[j];
						minus = min(minus, at[j + 1]);
						at[j] += minus;
						at[j + 1] -= minus;
					}
				}
			}

			min_count = min(min_count , count);
			cout << "//" << count << endl;
		}

		if (min_count == INT_MAX) {
			min_count = 0;
		}

		o[i] = min_count;
	}

	for (int ans : o) {
		cout << ans << endl;
	}

	return 0;
}
