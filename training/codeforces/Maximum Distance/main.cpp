#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	int c;
	cin >> c;

	vector<int> x(c);
	vector<int> y(c);

	for (int i = 0; i < c; i++) {
		int v;
		cin >> v;
		x[i] = v;
	}	

	for (int i = 0; i < c; i++) {
		int v;
		cin >> v;
		y[i] = v;
	}	


	int m = 0;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			int distance = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);	
			m = max(distance, m);
		}
	}

	cout << m << endl;



	return 0;
}
