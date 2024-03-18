#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned long long s;
	cin >> s;
	while (s != 1) {
		cout << s << " ";
		if (s % 2 == 0) {
			s /= 2;
		} else {
			s = s * 3 + 1;
		}
	}
	cout << s;
	return 0;
}
