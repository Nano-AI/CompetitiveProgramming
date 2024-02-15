#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, K; // N cows, M arranged, K specific	
	cin >> N >> M >> K;
	vector<int> cows(N);	
	vector<int> order(M);
	for (int& i : order) {
		cin >> i;
	}
	for (int i = 0; i < K - 1; i++) {
		int cow, pos;
		cin >> cow >> pos;
		cows[pos] = cow;
	}

	for (int i = 1; i < order.size(); i++) {
		
	}

	return 0;
}
