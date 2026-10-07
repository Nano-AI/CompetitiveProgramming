// NOT DONE - DID NOT FINISH

#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = * b;
  *b = temp;
}

void bblSort(int a[], int n) {
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = i; j < n - i - 1; j++) {
      if (a[i] > a[j] && a[j] % 2 == a[i]) {
        cout << "HHSDF" << endl;
        swap(&a[j], &a[i]);
        swapped = true;
      }
    }
  }
}

int main() {
  int numCases;
  cin >> numCases;

  for (int i = 0; i < numCases; i++) {
    int s;
    cin >> s;
    int vals[s];
    for (int j = 0; j < s; j++) {
      int v;
      cin >> v;
      vals[j] = v;
    }


    bblSort(vals, s);

    bool same = true;

    for (int v : vals) {
      cout << v << " ";
    }
    cout << endl;

    for (int j = 0; j < s - 1; j++) {
      if (vals[j] > vals[j + 1]) {
        cout << "NO" << endl;
        same = false;
        break;
      }
    }

    if (same) {
      cout << "YES" << endl;
    }

    // if (same) {
    //   cout << "YES" << endl;
    // } else {
    //   cout << "NO" << endl;
    // }
  }

  return 0;
}
