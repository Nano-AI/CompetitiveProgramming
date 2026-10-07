// www.usaco.org/index.php?page=viewproblem2&cpid=617
#include <bits/stdc++.h>

using namespace std;

void useIO(const char* file_name) {
	string file = file_name;
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
}

struct vec2 {
	int x;
	int y;
};

int main() {
	useIO("balancing");
	int cow_num;
	unsigned long m_val;

	cin >> cow_num >> m_val;

	vector<int> x(cow_num);
	vector<int> y(cow_num);
	set<int> vfence;
	set<int> hfence;

	for (int i = 0; i < cow_num; i++) {
		cin >> x[i] >> y[i];
		vfence.insert(x[i] + 1);
		hfence.insert(y[i] + 1);
	}

	int min_im = cow_num;

	for (int v : vfence) {
		for (int h : hfence) {
			int tl, tr, bl, br;
			tl = tr = bl = br = 0;

			for (int c = 0; c < cow_num; c++) {
				if (x[c] < v && y[c] > h) {
					tl++;
				} else if (x[c] > v && y[c] > h) {
					tr++;
				} else if (x[c] < v && y[c] < h) {
					bl++;
				} else if (x[c] > v && y[c] < h) {
					br++;
				}
			}

			min_im = min(
				min_im,
				max({ tl, tr, bl, br })
			);
		}
	}	

	cout << min_im << endl;
	return 0;
}
