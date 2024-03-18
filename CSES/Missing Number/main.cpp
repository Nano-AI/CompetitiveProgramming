#include <bits/stdc++.h>

using namespace std;

bool n[(int) (2*10e5+1)];

int main() {
	int s;
	cin >> s;
	for (int i = 1; i < s; i++) {
		int v;
		cin >> v;
		n[v] = true;
	}

	for (int i = 1; i <= s; i++) {
		if (n[i] == false) {
			cout << i;
			break;
		}
	}
}
