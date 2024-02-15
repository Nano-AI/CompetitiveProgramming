#include <bits/stdc++.h>
using namespace std;


int s;
string l;

void rec(int c) {
	if (c > s) return;
	unordered_map<string, bool> e;
	for (int i = 0; i <= s - c; i++) {
		string a = l.substr(i, c);		
		if (e.find(a) == e.end()) {
			e[a] = true;
		} else {
			rec(c + 1);
			return;
		}
	}
	cout << c << endl;
}

int main() {
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	cin >> s;
	cin >> l;

	rec(1);	

	return 0;
}
