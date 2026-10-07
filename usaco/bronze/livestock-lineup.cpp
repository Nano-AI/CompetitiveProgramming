// http://www.usaco.org/index.php?page=viewproblem2&cpid=965

#include <bits/stdc++.h>

using namespace std;


vector<string> cows = { "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };
unordered_map<string, vector<string>> c;
vector<vector<string>> p;

bool valid(vector<string> line) {
	string before = line[0];
	for (int i = 0; i < line.size(); i++) {
		string at = line[i];
		if (c[at].size() > 0) {
			bool left = true;
			bool right = true;
			for (string cow : c[at]) {
				if (i != line.size() - 1) {
					string after = line[i + 1];
					right = after != cow;
				}
				if (i != 0) {
					string prev = line[i - 1];
					left = prev != cow;
				}
				if (right && left) {
					return false;
				}
			}
		}
		else {
			if (before > at) {
				return false;
			}
			before = at;
		}
	}
	return true;
}

int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int numLines;
	cin >> numLines;
	cin.ignore();

	for (int i = 0; i < numLines; ++i) {
		string line;
		getline(cin, line);
		
		istringstream iss(line);
		string name1, _, name2;
		
		iss >> name1 >> _ >> _ >> _ >> _ >> name2;
		
		c[name1].push_back(name2);
		c[name2].push_back(name1);
	}

	do {
		if (valid(cows)) {
			for (string cow : cows) {
				cout << cow << endl;
			}
			return 0;
		}
	} while (next_permutation(cows.begin(), cows.end()));

	return 0;
}
