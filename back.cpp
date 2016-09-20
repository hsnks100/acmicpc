#include <bits/stdc++.h>
using namespace std; 


int d[200] = {0,};
// int dfs(int i, int n, int c, int bc){
//   if(i == n) {
//     return c;
      
//   }
//   else{
//     dfs(i + 1, n, c + 1, bc); // A
//     dfs(i + 1, n, c, bc); // ^A
//     dfs(i + 1, n, c, bc); // ^C
//     dfs(i + 1, n, c + 1, bc); // ^V
    
//   }
// }
// int dfs(int i, int n){



//   if(d[i] != 0)
//     return d[i];


//   if(i == n){
//     return 


//   }
//   else{
//   }
// }
int D(int i){
  // if(d[i] != -1)
  //   return d[i];

  cout << i << endl
  if(i == 0)
    return 0;
  if(i == 1)
    return 1;
  if(i == 2)
    return 2;
  if(i == 3)
    return 3;
  if(i == 4)
    return 4;
  auto a = max(D(i - 3) * 2, D(i-1) + D(i-1) - D(i-2));
  a = max(a, D(i-1) + 1);
  a = max(a, D(i));
  return a;
  return d[i] = a;
}
int main()
{


  int n;
  cin >> n;
  for(int i=0; i<200; i++){
    d[i] = -1;
  }

  d[0] = 0;
  d[1] = 1;
  d[2] = 2;
  d[3] = 3;
  d[4] = 4;

  cout << D(n);



  return 0;
}

