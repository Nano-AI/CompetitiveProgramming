#include <bits/stdc++.h>

using namespace std;

void useIO(const char* file_name) {
	string file = file_name;
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
}

bool infected[101];
int N, cowx[251], cowy[251];

bool check(int p0, int K) {
	bool temp[101] = { false };
	int handshakes[101] = { 0 }	;
	temp[p0] = true;
	for (int t = 0; t <= 250; t++) {
		int x = cowx[t], y = cowy[t];	
		if (x > 0) {
			if (temp[x]) handshakes[x]++;
			if (temp[y]) handshakes[y]++;
			if (handshakes[x] <= K && temp[x]) temp[y] = true;
			if (handshakes[y] <= K && temp[y]) temp[x] = true;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (temp[i] != infected[i]) {
			return false;
		}
	}	
	return true;
}

int main() {
	useIO("tracing");

	int T, t, x, y;

	string s;

	cin >> N >> T >> s;

	for (int i = 1; i <= N; i++) {
		infected[i] = s[i - 1] == '1';
	}

	for (int i = 0; i < T; i++) {
		cin >> t >> x >> y;
		cowx[t] = x;
		cowy[t] = y;
	}

	bool pi[101] = { false };
	bool pk[252] = { false };

	for (int i = 1; i <= N; i++) {
		for (int K = 0; K <= 251; K++) {
			if (check(i, K)) {
				pi[i] = true;
				pk[K] = true;
			}
		}		
	}

	int k_min = 251, k_max = 0, count = 0; 

	for (int i = 0; i <= 251; i++) {
		if (pk[i]) {
			k_max = i;	
		}	
	}

	for (int i = 251; i > 0; i--) {
		if (pk[i]) {
			k_min = i;	
		}
	}

	for (int i = 0; i <= N; i++) {
		if (pi[i]) {
			count++;
		}
	}

	cout << count << " " << k_min << " ";

	if (k_max == 251) {
		cout << "Infinity";
	} else {
		cout << k_max;
	}

	cout << endl;

	return 0;
}
