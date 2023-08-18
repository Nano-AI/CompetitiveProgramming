#include <bits/stdc++.h>

using namespace std;

vector<int> id(size);

int root(int i) {
	while (i != id[i]) i = id[i];
	return i;
}

bool connected(int n1, int n2) {
	return root(n1) == root(n2);
}

void connect(int p, int q) {
	int i = root(p);
	int j = root(q);
	id[i] = j;
}

int main() {
	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		id.push_back(i);
	}

	cout << "ni hao" << endl;
	return 0;
}
