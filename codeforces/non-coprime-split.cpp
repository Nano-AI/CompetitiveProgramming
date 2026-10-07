#include <bits/stdc++.h>
using namespace std;

bool gz_gcd(int a, int b) {
	for (int i = min(a, b); i > 2; i--) {
		if (a % i == 0 && b % i == 0)
			return true;
	}
	return false;
}

int main() {
	int size;
	cin >> size;
	vector<pair<int, int>> i(size);
	for (pair<int, int> &n : i) {
		cin >> n.first >> n.second;
	}

	for (pair<int, int> &p : i) {
		cout << ">>" << p.first << " " << p.second << endl;
		bool found = false;
		for (int i = p.first; i <= p.second; i++) {
			for (int j = 2; j < p.second - 1; i++) {
				bool found = false;
				if (i % (j * j) == 0) {
					bool found = true;	

					for (int k = 0; k < 1; k++) {
						
					}
				}
			}

			if (!found) {
				cout << -1 << endl;
			}
		}

		if (!found) {
			cout << "-1" << endl;
		}
	}
	
	return 0;
}
