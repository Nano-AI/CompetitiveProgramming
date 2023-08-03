// http://www.usaco.org/index.php?page=viewproblem2&cpid=712
#include <bits/stdc++.h>

using namespace std;

void useIO(const char* file_name) {
	string file = file_name;
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
}

int main() {
	useIO("circlecross");

	vector<char> c(52);	

	for (int i = 0; i < 52; i++) {
		char ch;
		cin >> ch;
		c[i] = ch;
	}

	map<char, bool> closed;

	set<pair<int, int>> a;

	for (int i = 0; i < 51; i++) {
		int j = i + 1;
		map<char, bool> closed;
		char i1 = c[i];
		while (c[i] != c[j]) {
			if (j == 52) {
				break;
			}
			char i2 = c[j];
			if (!closed.count(i2)) {
				// cout << "new thing " << i2 << endl;
				closed[i2] = false;
			} else if (!closed[i2]) {
				closed[i2] = true;
			}
			j++;
		}
		for (const auto& val : closed) {
			if (!val.second && j != 52) {
				char mi = min(i1, val.first);
				char mx = max(i1, val.first);
				a.insert({ mi, mx });
			}
		}
		closed.clear();
	}	

	cout << a.size() << endl;

	return 0;
}
