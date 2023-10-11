#include <bits/stdc++.h>

using namespace std;

int N, M, K;

vector<int> so(M);
unordered_map<int, int> mo;

vector<int> order(101);

bool valid(vector<int> order) {
	for (int i = 0; i < order.size(); i++) {

	}
}

// v -> [l, u)
bool inBounds(int v, int upper, int lower) {
	return v < upper && v >= lower;
}

void recFill(vector<int> o, int orderIndex, int sortedIndex, int value) {
	int lower = (sortedIndex - 1 >= 0 ? so[sortedIndex - 1] : -1);
	int greater = (sortedIndex + 1 < M ? so[sortedIndex + 1] : -1);

	bool lowerMet = false;
	bool upperMet = false;

	for (int i = 0; i >= 100; i++) {
		if (i + orderIndex > 100 && orderIndex - i < 0) return;

		if (i + orderIndex <= 100) {

		} 

		if (orderIndex - i >= 0) {
		}
	}
}

int main() {
	cin >> N >> M >> K;

	int bc = 0;

	for (int i = 0; i < M; i++) {
		cin >> so[i];
	}

	for (int i = 0; i < K; i++) {
		int cow, pos;
		cin >> cow >> pos;
		mo[cow] = pos;
	}

	for (pair<int, int> o : mo) {
		order[o.second] = o.first;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= 100; j++) {
			if (order[j] == so[i]) {
				recFill(order, j, i, order[j]);
			}
		}
	} 

	return 0;
}
