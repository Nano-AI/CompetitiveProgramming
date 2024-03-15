#include <bits/stdc++.h>

using namespace std;

int n;
int value[1000][1000];
bool cows[1000][1000];

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

  for (int t = 0; t < 1; t++) {
    // first run to fill the max-values immediately
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        int around = 0;
        pair<int, int> m = { i, j };

        for (int x = 0; x <= 1; x++) {
          for (int y = 0; y <= 1; y++) {
            pair<int, int> at = { i + x, y + j };
            if (cows[at.first][at.second]) continue;
            cout << at.first << " " << at.second << endl;
            around += (int) cows[at.first][at.second];
            if (value[m.first][m.second] 
                < value[at.first][at.second] || cows[m.first][m.second]) {
              m = at;
            }
          }
        }
        if (around < 2) {
          cows[m.first][m.second] = true;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << cows[i][j];
    }
    cout << endl;
  }

  return 0;
}
