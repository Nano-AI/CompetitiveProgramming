#include <bits/stdc++.h>

using namespace std;

int n, m, k;

bool check(vector<int> order, vector<int> &hierarchy) {
  vector<int> cow_to_pos(n, -1);
  for (int i = 0; i < n; i++) {
    if (order[i] != -1) {
      cow_to_pos[order[i]] = -1;
    }
  }

}

int main() {
  cin >> n >> m >> k;

  vector<int> hierarchy(m);
  for (int i = 0; i < m; i++) {
    cin >> hierarchy[i];
    hierarchy[i] --;
  }

  vector<int> order(n, -1);
  for (int i = 0; i < k; i++) {
    int cow, pos;
    cin >> cow >> pos;
    order[--pos] = --cow;
    // if (cow == 0) {
    //   cout << pos + 1 << endl;
    //   return 0;
    // }
  }

  for (int i = 0; i < n; i++) {
    if (order[i] == -1) {
      order[i] = 0;
      if (check(order, hierarchy)) {
        cout << i + 1 << endl;
        break;
      }

      order[i] = -1;
    }
  }
}
