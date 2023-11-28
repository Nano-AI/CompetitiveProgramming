#include <bits/stdc++.h>

using namespace std;

int cow_count, soc_count, pos_count;
vector<int> hiec(0);

int rec(vector<int> b, int c) {
	if (c == soc_count) {
		for (int i = 0; i < cow_count; i++) {
			if (b[i] == 0) {
				return i;
			}
		}
	}

	int m = INT_MAX;

	int at;
	for (at = 0; at < cow_count; at++) {
		if (b[at] == hiec[c]) {
			break;
		}
	}

	

	return m;
}

int main() {
	cin >> cow_count >> soc_count >> pos_count;
	vector<int> b(cow_count);

	vector<vector<int>> p(cow_count);

	for (int i = 0; i < soc_count; i++) 
		int value = 0;
		cin << value;
	}

	for (int i = 0; i < cow_count; i++) {
		int pos, v;
		cin >> pos >> v;
		b[pos] = v; 
	}

	int v = rec(b, 0); 

	return 0;
}
