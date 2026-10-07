#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		int nums, common;
		cin >> nums >> common;
		bool found = false;
		for (int j = 0; j < nums; j++) {
			int d;
			cin >> d;
			if (d == common) {
				found = true;
			}
		}
		if (found) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
