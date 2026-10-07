#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

struct Case {
	int num_ppl;
	int num_steps;
	int height_diff;
	int height;	
	vector<int> heights;
};

int main() {
	// n passengers, m total stesp, ith step = i * k 
	// vlad height is H
	// talk if steps are not same, and H1 - H2 = S1 - S2 

	int num_cases;
	cin >> num_cases;

	vector<Case> cases(num_cases);

	for (int i = 0; i < num_cases; i++) {
		Case &c = cases[i];
		cin >> c.num_ppl >> c.num_steps >> c.height_diff >> c.height;	
		for (int j = 0; j < c.num_ppl; j++) {
			int height;
			cin >> height;
			c.heights.push_back(height);
		}	
	}	

	for (Case &c : cases) {
		int count = 0;
		for (int height : c.heights) {
			int step_diff = abs(height - c.height);
			if (step_diff != 0 && step_diff % c.height_diff == 0 && step_diff / c.height_diff < c.num_steps) {
				count++;
			}
		}	
		cout << count << endl;
	}
	
	return 0;	
}