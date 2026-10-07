#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n;
	cin >> n;
	if (n <= 3 && n > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	ll e = 2;
	while (e <= n) {
		cout << e << " ";
		e += 2;
	}
	ll o = 1;
	while (o <= n) {
		cout << o << " ";
		o += 2;
	}
	return 0;
}
