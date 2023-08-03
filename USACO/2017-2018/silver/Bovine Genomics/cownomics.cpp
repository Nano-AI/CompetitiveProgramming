// http://www.usaco.org/index.php?page=viewproblem2&cpid=739
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

	vector<vector<map<string, bool>>> g(len_gene, 
		vector<map<string, bool>>(2)); 
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
			sc[i].push_back(c);
 		}
	}

	for (int i = 0; i < num_cows; i++) {
 		for (int j = 0; j < len_gene; j++) {
			char c;
			cin >> c;
			pc[i].push_back(c);
 		}
	}

	int count = 0;

	int x, y, z;
	for (x = 0; x < len_gene; x++) {
		for (y = x + 1; y < len_gene; y++) {
			if (y >= len_gene) {
				break;
			}
			for (z = y + 1; y < len_gene; z++) {
				if (z >= len_gene) {
					break;
				}
				unordered_map<string, bool> vals;	
				bool clear = true;
				int index = 0;
				for (int i = 0; i < num_cows; i++) {
					string combo{sc[i][x], sc[i][y], sc[i][z]};
					vals[combo] = true;
				}
				for (int i = 0; i < num_cows; i++) {
					string combo{pc[i][x], pc[i][y], pc[i][z]};
					if (vals[combo]) {
						clear = false;
						break;
					}
					index++;
				}
				if (clear) {
					count ++;
				}
			}
		}
	}	

	cout << count << endl;

	return 0;
}
