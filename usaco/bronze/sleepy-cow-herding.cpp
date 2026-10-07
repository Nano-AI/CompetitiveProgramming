#include <bits/stdc++.h>

using namespace std;
int mi = INT_MAX;
int ma = 0;

vector<int> mids;

void rec(int c1, int c2, int c3, int moves) {
	int mirec = min({ c1, c2, c3 });
	int marec = max({ c1, c2, c3 }); 
	int mid = min(min(max(c1, c2), max (c2, c3)), max(c1, c3));

	if (mid - mirec == 1 && marec - mid == 1) {
		for (int md : mids) {
			if (md == mid) {
				return;
			}
		}
		mids.push_back(mid);
		mi = min(moves, mi);
		ma = max(moves, ma);
		return;
	}
	
	for (int i = mid + 1; i < marec; i++) {
		rec(i, mirec, mid, moves + 1);
		rec(marec, i, mid, moves + 1);
	}
	for (int i = mirec + 1; i < mid; i++) {
		rec(mirec, i, mid, moves + 1);
		rec(marec, i, mid, moves + 1);
	}
}

int main() {
	int c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	rec(c1, c2, c3, 0);
	cout << mi << " " << ma << endl;
	return 0;
}
