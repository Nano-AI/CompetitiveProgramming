#include <bits/stdc++.h>

using namespace std;

set<string> perms;

void perm(string at, string left) {
	int size = left.length();
	if (size == 0) {
		perms.insert(at);
		return;
	}
	for (int i = 0; i < size; i++) {
		string temp = left;
		char remove = temp.at(i);
		perm(at + remove, temp.erase(i, 1));
	}
}

int main() {
	string input;
	cin >> input;
	perm("", input);

	cout << perms.size() << endl;
	for (string s : perms) {
		cout << s << endl;
	}
	return 0;
}
