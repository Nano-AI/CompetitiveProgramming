// https://cses.fi/problemset/task/1623/
#include <bits/stdc++.h>

using namespace std;

vector<long long> vals;
int apples;
long long min_val = LLONG_MAX;

void sub(long long lsum, long long rsum, int at) { 
	if (at >= apples) {
		min_val = min(abs(lsum - rsum), min_val);
		return;
	}
	sub(lsum + vals[at], rsum, at + 1);
	sub(lsum, rsum + vals[at], at + 1);
}

int main() {
	cin >> apples;
	vals.reserve(apples);

	for (int i = 0; i < apples; i++) {
		cin >> vals[i];	
	}	

	sub(0, 0, 0);

	cout << min_val << endl;

	return 0;
}
