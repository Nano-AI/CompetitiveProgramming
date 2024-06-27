#include <bits/stdc++.h>
#define inf numeric_limits<int>::max()

using namespace std;

int solve(string s, int n) {
	int two_digit = 0;
	int two_digit_index = -1;
	int out = 0;

	int ans = inf;

	// iterate through each section. "sliding" window for a two digit number
	for (int i = 0; i < n - 1; i++) {
		// reset var
		out = 0;

		// get the two digit number
		two_digit = (s[i] - '0') * 10 + (s[i + 1] - '0');
		// store its index
		two_digit_index = i;

		// iterate through all the numbers assuming that it's the right answer
		for (int i = 0; i < n; i++) {
			// ignore it if it's the two digit number or of it's 1
			// b/c we'll add the two digit later and 1 can be mulitplied, therefor iit can be skipped
			if (i == two_digit_index || i == two_digit_index + 1 || s[i] == '1')
				continue;
			// if it's zero then return zero b/c mulitiplying by zero gives smallest value
			if (s[i] == '0') {
				return 0;
			}
			// add the digit
			out += s[i] - '0';
		}

		// mulitply the two digit number b/c two_digit is either 0 or 1
		// which will result in a smaller number than addng
		// otherwise if it's greater than one, then adding will give a smaller number than mulitplying
		if (two_digit <= 1 && out != 0) {
			out *= two_digit;
		} else {
			out += two_digit;
		}
		
		// store the ans as the min between the simulated and the stored ans
		ans = min(out, ans);
	}

	// return the ans
	return ans;
}

int main() {
	// # of cases
	int t;
	cin >> t;

	int n;
	string s;

	while (t--) {
		cin >> n;
		cin >> s;

		int ans = inf;

		cout << solve(s, n) << endl;
	}

	return 0;
}
