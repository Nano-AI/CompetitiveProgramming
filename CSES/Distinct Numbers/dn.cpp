#include <bits/stdc++.h>
using namespace std;
int main() {
	int s;
	cin >> s;
	vector<int> n(s);
	for (int& v : n) {
		cin >> v;
	}
	sort(n.begin(), n.end());
	int c = 1;
	int prev = n[0];
	for (int v : n) {
		if (v == prev) {
			continue;
		}
		prev = v;
		c++;
	}
	cout << c << endl;
	return 0;
}
