/*
USER: Aditya Bankoti [adi.ban1]
LANG: C++
PROG: 
*/
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
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
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void useIO(const char* f, bool debug) {
  string file = f;
  freopen((file + ".in").c_str(), "r", stdin);
  if (!debug) {
    freopen((file + ".out").c_str(), "w", stdout);
  }
}

void useIO(const char* f) {
  useIO(f, false);
}

int main(){
  useIO("");

  return 0;
}