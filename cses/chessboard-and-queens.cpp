#include <bits/stdc++.h>
using namespace std;

const int DIM = 8;

vector<vector<bool>> blocked(DIM, vector<bool>(DIM));
vector<bool> row_taken(DIM, false);

vector<bool> diagDU(DIM * 2);
vector<bool> diagUD(DIM * 2);
int ways;

void rec(int c = 0) {
	if (c == DIM) {
		ways++;
		return;
	}

	for (int r = 0; r < DIM; r++) {
		bool row_open = !row_taken[r];
		bool diag_open = !diagDU[r + c] && !diagUD[r - c + DIM];
		if (!blocked[r][c] && row_open && diag_open) {
			row_taken[r] = diagDU[r + c] = diagUD[r - c + DIM] = true;
			rec(c + 1);
			row_taken[r] = diagDU[r + c] = diagUD[r - c + DIM] = false;
		}
	}
}

int main() {
	ways = 0;
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			char in;
			cin >> in;
			blocked[r][c] = in == '*';
		}
	}

	rec();

	cout << ways << endl;

	return 0;
}

