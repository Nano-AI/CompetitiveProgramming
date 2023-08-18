// http://www.usaco.org/index.php?page=viewproblem2&cpid=1276
// My solution passed 7/11 test cases, since my algo was too slow for test cases 5 6 8 and 9
#include <bits/stdc++.h>
using namespace std;

int N;
int M;

struct ac {
	int start;
	int end;
	int cost;
	int temp;
};

struct cow {
	int start;
	int end;
	int temp;
	int mtemp;
	int cost;
};

int main() {
	int N, M;
	cin >> N >> M;

	vector<cow> cows(N);
	vector<ac> acs(M);

	int stalls[100] = { 0 };

	vector<int> order(M);

	iota(order.begin(), order.end(), 0);

	for (cow& c : cows) {
		cin >> c.start >> c.end >> c.mtemp;
		for (int i = c.start - 1; i < c.end; i++) {
			stalls[i] = c.mtemp;
		}
	}

	for (ac& ac : acs) {
		cin >> ac.start >> ac.end >> ac.temp >> ac.cost;
	}

	int mcost = INT_MAX;

	do {
		int cost = 0;
		int stallc[100] = { 0 };
		for (int i : order) {
			if (cost >= mcost) {
				break;	
			}

			ac a = acs[i];
			for (int j = a.start - 1; j < a.end; j++) {
				stallc[j] += a.temp;
			}
			cost += a.cost;	

			if (cost >= mcost) {
				break;	
			}

			bool done = true;
			for (int j = 0; j < 100; j++) {
				if (stallc[j] < stalls[j]) {
					done = false;
					break;
				}
			}

			if (done) {
				if (cost <= mcost) {
					mcost = cost;
					break;
				}
			}

		}
	} while (next_permutation(order.begin(), order.end()));

	cout << mcost << endl;
	return 0;
}

