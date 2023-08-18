// https://codeforces.com/contest/1857/problem/B
#include <bits/stdc++.h>
using namespace std;

int getSize(unsigned long long n) {
	int size = 1;
	unsigned long long copy = n;
	while (copy > 10) {
		copy /= 10;
		size++;
	}
	return size;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		unsigned long long in;
		cin >> in;
		unsigned long long m = in;
		vector<int> toVector = getVector(in);		
		unsigned long long copy = in;
		cout << copy << endl;
		for (int i = 0; i < size + 1; i++) {
			// copy = in;
			for (int j = 0; j < i; j++) {
				copy /= 10;
			}
			cout << copy << " -> ";
			if (copy % 10 < 5) {
				copy -= copy % 10;
			} else {
				copy -= copy % 10;
				copy += 10;
			}
			cout << copy << " -> ";
			for (int j = 0; j < i; j++) {
				copy *= 10;
			}
			cout << copy << endl;
			m = max(m, copy);
		}

		cout << "\t" << m << endl;
	}
	return 0;
}
