// https://codeforces.com/problemset/problem/581/D
#include <bits/stdc++.h>
using namespace std;


int x1, y1, x2, y2, x3, y3;

struct ret {
	vector<string> b;
	int ac;
	int bc;
	int cc;
};

bool found = false;
int sz = 0; 
 
ret fillBoard(char l, ret r, int x1, int y1, int x2, int y2) {
	if (found) return { {}, 0, 0, 0 };
	ret o = r;
	int size = o.b.size();
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > size || x2 > size || y1 > size || y2 > size
		|| found) {
		return { { }, 0, 0, 0 };
	}
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (o.b[i][j] != ' ') {
				return { { }, 0, 0, 0 };
			}
			o.b[i][j] = l;
			switch (l) {
				case 'A':
					o.ac++;
					break;
				case 'B':
					o.bc++;
					break;
				case 'C':
					o.cc++;
					break;
				default:
					break;
			}
		}
	}
	return o;	
}

bool inBounds(int a, int b) {
	return a >= 0 && b >= 0 && a <= sz && b <= sz;
}

void rec(int c, ret i) {
	if (found) return;
	vector<string> b = i.b;
	int ac = i.ac; 
	int bc = i.bc;
	int cc = i.cc;
	int size = b.size();
	if (c >= 0 && size == 0) {
		return;
	}
	if (c >= 3 || c < 0) {
		if (ac == x1 * y1 && bc == x2 * y2 && cc == x3 * y3) {
			for (string s : b) {
				cout << s << endl;
			}
			found = true;
		}
		return;
	}
	char letter;
	int xOff, yOff;
	switch (c) {
		case 0:
			letter = 'A';
			xOff = x1;
			yOff = y1;
			break;
		case 1:
			letter = 'B';
			xOff = x2;
			yOff = y2;
			break;
		case 2:
			letter = 'C';
			xOff = x3;
			yOff = y3;
			break;
		default:
			break;
	}
	for (int l = 0; l < size - min(xOff, yOff) + 1; l++) {
		for (int m = 0; m < size - min(xOff, yOff) + 1; m++) {
			if (b[l][m] != ' ') continue;
			if (inBounds(l + xOff, m + yOff))
				rec(c + 1, fillBoard(letter, i, l, m, l + xOff, m + yOff));
			if (inBounds(l + yOff, m + xOff))
				rec(c + 1, fillBoard(letter, i, l, m, l + yOff, m + xOff));
		}
	}
}

int main() {
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	sz = max({ x1, y1, x2, y2, x3, y3 });

	if (x1 * y1 + x2 * y2 + x3 * y3 != sz * sz) {
		cout << "-1" << endl;
		return 0;
	}

	cout << sz << endl;
	vector<string> board(sz, string(sz, ' '));

	rec(0, { board, 0, 0, 0 });

	return 0;
}
