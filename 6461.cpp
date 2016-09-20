#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <cstdio>
#include <memory.h>
#include <map>
#include <queue>
 
using namespace std;
 
 
int T;
unsigned long long d[200] = {0,};
int main(){
  cin >> T;
 
  d[1] = 1;
  d[2] = 1;
  d[3] = 1;
  d[4] = 2;
  d[5] = 2;
  d[6] = 3;
  d[7] = 4;
  d[8] = 5;
  d[9] = 7;
 
 
  for(int i=10; i<=100; i++){
    d[i] = d[i-1] + d[i-5];
  }

  for(int zz=0; zz<T; zz++){
    int n; 
    cin >> n; 
    cout << d[n] << endl; 
  }
 
 
  return 0;
}
