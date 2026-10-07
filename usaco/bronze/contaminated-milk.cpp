/*
USER: Aditya Bankoti [adi.ban1]
LANG: C++
PROG: badmilk
*/
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
//For ordered_set

using namespace std;

void useIO(const char* f, bool debug) {
  string file = f;
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}

void useIO(const char* f) {
  useIO(f, false);
}

struct Event {
  int person;
  int milk = -1;
  int time; 
};

int main(){
  useIO("badmilk");
  // i copied this and i still don't understand how it works....
  // not a good sign

  int num_ppl = 0; // # of ppl
  int num_milks = 0; // # types of milk
  int drink_times = 0; // next D lines containing:
  // p: person id [1, N]
  // m: type of milk [1, M]
  // t: time [1, 100]
  int sick_times = 0; // next S lines containing:
  // p: person id [1, N]
  // t: time [1, 100]

  cin >> num_ppl >> num_milks >> drink_times >> sick_times;


  vector<Event> events(sick_times + drink_times);
  
  for (int i = 0; i < events.size(); i++) {
    Event &ev = events[i];
    if (i < drink_times) {
      cin >> ev.person >> ev.milk >> ev.time;
    } else {
      cin >> ev.person >> ev.time; 
    } 
    ev.person--;
  } 

  sort(
    events.begin(), events.end(), [&](const Event& e1, const Event& e2) {
      return (e1.time != e2.time) ? (e1.time < e2.time) : (e1.milk < e2.milk);  
    }
  ); 

  int a = 0;

  for (int m = 0; m < num_milks; m++) {
    vector<bool> sick(num_ppl);
    bool possible = true; 
    for (const Event &e : events) {
      if (e.milk == -1) {
        if (!sick[e.person]) {
          possible = false;
          break;
        }
      } else if (e.milk == m) {
        sick[e.person] = true; 
      } 
    } 

    if (possible) {
      int meds = 0;
      for (bool p : sick) {
        meds += p;
      }
      a = max(meds, a); 
    }
  }
  cout << a << endl;

  return 0;
}