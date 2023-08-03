/*
USER: Aditya Bankoti [adi.ban1]
LANG: C++
PROG: milk2
*/

#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <string>
#include <utility>
//For ordered_set
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define S string
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define IT iterator
#define RIT reverse_iterator
#define all(a) a.begin(),a.end()
#define ld long double
#define PI 3.14159265358979323846 
using namespace std;
// For ordered_set
template <typename T>
const ll maxn = 1e5;
const ll inf = 1e9;

void useIO(const char* s, bool debug) {
  S file = s;
  freopen((file + ".in").c_str(), "r", stdin);
  // freopen((file + ".out").c_str(), "w", stdout);
}

void useIO(const char* s) {
  useIO(s, false); 
}

int main(){
  useIO("milk2", true);

  int s = 0; 
  V<PII> vals;  

  cin >> s;

  int oc = 0;
  int nc = 0; 

  for (int i = 0; i < s; i++) {
    PII pair; 
    cin >> pair.first >> pair.second;
    vals.push_back(pair);
  }

  for (int i = 0; i < s; i++) {
     
  }

  return 0;
}