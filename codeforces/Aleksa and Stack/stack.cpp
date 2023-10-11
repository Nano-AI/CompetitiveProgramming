#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;

	for (int j = 0; j < cases; j++) {
		int length;
		cin >> length;
		vector<int> a(length, 1);

		int i = 0;
		while (i < length - 2) {
			if (3 * a[i + 2] % (a[i] + a[i + 1]) == 0) {
				if (a[i] < a[i + 1] && a[i] < a[i + 2]) {
					a[i]++;
				} 
				} else {
				i++;
			}
		}

		for (int num : a) 
			cout << num << " ";
		cout << endl;
	}
	return 0;
}
