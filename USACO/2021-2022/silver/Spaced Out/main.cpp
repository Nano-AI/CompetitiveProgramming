#include <bits/stdc++.h>

using namespace std;

int n;
int value[1001][1001];
bool cows[1001][1001];

int main() {

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;
      cows[i][j] = false;
      value[i][j] = v;
    }
  }

  int m = 0;

  for (int t = 0; t <= 1; t++) {
    bool top = (bool) t;
    int t_sum = 0;
    int top_sum = 0;
    int bottom_sum = 0;
    for (int x = 0; x < n; x += 2) {
      for (int y = 0; y < n; y += 2) {
        // incase they never alternate
        top_sum += value[y][x] + value[y][x + 1];
        bottom_sum += value[y + 1][x] + value[y + 1][x + 1];
        // however if the top does alternate;
        if (top) {
          /*
            t_sum = 1 1
                    0 0
          */
          t_sum += value[y][x] + value[y][x + 1];
        } else {
          /*
            t_sum = 0 0
                    1 1
          */
          t_sum += value[y + 1][x] + value[y + 1][x + 1];
        }
      }
      // and the top ones MUST alternate every column, otherwise it's invalid
      top = !top;
    }
    // store the max value
    m = max(t_sum, m);
  }

  // horizontal sum
  for (int t = 0; t <= 1; t++) {
    bool left = (bool) t;
    int h_sum = 0;
    int left_sum = 0;
    int right_sum = 0;
    for (int x = 0; x < n; x += 2) {
      for (int y = 0; y < n; y += 2) {
        // incase they never alternate
        left_sum += value[y][x] + value[y + 1][x];
        right_sum += value[y][x + 1] + value[y + 1][x + 1];
        // however if the top does alternate;
        if (left) {
          /*
            t_sum = 1 1
                    0 0
          */
          t_sum += value[y][x] + value[y][x + 1];
        } else {
          /*
            t_sum = 0 0
                    1 1
          */
          t_sum += value[y + 1][x] + value[y + 1][x + 1];
        }
      }
      // and the top ones MUST alternate every column, otherwise it's invalid
      top = !top;
    }
    // store the max value
    m = max(t_sum, m);
  }

  cout << m << endl;

  // diagonals
  for (int d = 0; d <= 1; d++) {
    bool diag = (bool) d;
    int t_sum = 0;
    int h_sum = 0;
    for (int x = 0; x < n; x += 2) {
      for (int y = 0; y < n; y += 2) {
        if (diag) {
          t_sum += value[y][x] + value[y + 1][x + 1];
          h_sum += value[y][x + 1] + value[y + 1][x];
        } else {
          h_sum += value[y][x] + value[y + 1][x + 1];
          t_sum += value[y][x + 1] + value[y + 1][y];
        }
      }
      diag = !diag;
    }
    m = max({ t_sum, m, h_sum });
  }

  cout << m << endl;

  return 0;
}
