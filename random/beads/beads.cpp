/*
USER: Aditya Bankoti [adi.ban1]
LANG: C++ 
PROG: beads 
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

void useIO() {
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
}

int main() {
  useIO();

  int N;
  string beads;

  cin >> N;
  cin >> beads;

  int cur = 0, max = 0;
  char color;
  bool switched;
   
  for(int i = 0; i < N; ++i){
   cur = 0;
   switched = false;
   color = 'w';
   for(int j = 0; j < N; ++j){
    const char cur_c = beads[(i + j) % N];
    if(cur_c != 'w'){
     if(color == 'w'){
      color = cur_c;
     }
     else if(color != cur_c){
      if(switched)
       break;
      else{
       color = cur_c;
       switched = true;
      }
     }
    }
    ++cur;
   }
   if(cur > max)
    max = cur;
  } 

  cout << max << endl;

  return 0;
}