// http://www.usaco.org/index.php?page=viewproblem2&cpid=1276
// improved solution that works for all test cases
#include <bits/stdc++.h>
using namespace std;

int N;
int M;

int mcost = INT_MAX;

vector<pair<int, int>> cows;
vector<int> temp;
vector<pair<int, int>> acs;
vector<int> cost;
vector<int> power;

int get_cost(string pattern) {
	vector<int> stalls(100);
	int price = 0;
	for (int i = 0; i < M; i++) {
		auto a = acs[i];
		if (pattern[i] != '1') {
			continue;
		}
		price += cost[i];	
		for (int j = a.first - 1; j < a.second; j++) {
			stalls[j] += power[i]; 
		}
	}

	bool valid = true;
	for (int i = 0; i < N; i++) {
		auto c = cows[i];
		for (int j = c.first - 1; j < c.second; j++) {
			if (stalls[j] < temp[i]) {
				valid = false;
				break;
			}
		}
	}
	if (valid) return price;
	return INT_MAX;
}

void rec(string current) {
	if (current.size() == M) {
		int cost = get_cost(current);
		mcost = min(mcost, cost);
	} else {
		rec(current + "1");
		rec(current + "0");
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int start, end, mtemp;
		cin >> start >> end >> mtemp;
		cows.push_back({ start, end });
		temp.push_back(mtemp);
	}


	for (int i = 0; i < M; i++) {
		int start, end, p, c;
		cin >> start >> end >> p >> c;
		acs.push_back({ start, end });
		power.push_back(p);
		cost.push_back(c);
	}

	rec("");

	cout << mcost << endl;

	return 0;
}

