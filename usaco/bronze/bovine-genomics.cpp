// http://www.usaco.org/index.php?page=viewproblem2&cpid=736
#include <bits/stdc++.h>

using namespace std;

void useIO(const char* file_name) {
	string file = file_name;
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
}

int main() {
	useIO("cownomics");
	int num_cows;
	int len_gene;

	cin >> num_cows >> len_gene;

	vector<vector<char>> sc(num_cows);
	vector<vector<char>> pc(num_cows);

	vector<vector<map<char, bool>>> g(len_gene, 
		vector<map<char, bool>>(2)); 
	/*
	every gene index:
		0: spotty cow
			A: on or not 
			T:
			G:
			C:
		1: plain cow
			A:
			T:
			G:
			C
	*/

	for (int i = 0; i < num_cows; i++) {
 		for (int j = 0; j < len_gene; j++) {
			char c;
			cin >> c;
			g[j][0][c] = true;
 		}
	}

	for (int i = 0; i < num_cows; i++) {
 		for (int j = 0; j < len_gene; j++) {
			char c;
			cin >> c;
			g[j][1][c] = true;
 		}
	}

	int count = 0;

	vector<char> types = { 'A', 'T', 'G', 'C' };

	for (int i = 0; i < len_gene; i++) {
		bool clear = true;
		map<char, bool> called;
		for (int j = 0; j < 5; j++) {
			called[types[j]] = -1;
		}
		for (int j = 0; j < 4; j++) {
			bool scG = g[i][0][types[j]];
			bool pcG = g[i][1][types[j]];
			if (scG == pcG && scG != false && pcG != false) {
				clear = false;
				break;
			}
		}

		if (clear) {
			count++;
		}
	}


	cout << count << endl;

	return 0;
}
