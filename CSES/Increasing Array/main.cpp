#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<unsigned long long> l(n);
	for (auto& v : l) {
		cin >> v;
	}
	unsigned long long t = 0;
	for (int i = 0; i < n - 1; i++) {
		unsigned long long s = l[i + 1] < l[i] ? l[i] - l[i + 1] : 0;
		l[i + 1] += s;
		t += s;
	}
	cout << t << endl;
	return 0;
}
