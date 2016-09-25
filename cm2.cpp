#include <bits/stdc++.h>
using namespace std;
 
#define LIMIT(X, cmd) {static int __ = 0; if(__++ >= (X)) cmd;}

int jido[30][30];

int sy, sx;
void dfs(int y, int x, int value){
  
}
int main(){
  int tc;
  cin >> tc;

  while(tc--){
    int r, c;

    cin >> r >> c;
    fill_n(*jido, 30*30, -1e9);

    for(int i=1; i<=r; i++){
      string t;
      cin >> t;
      for(int k=0; k<t.size(); k++){
        if(t[k] == 'E'){
          sy = i;
          sx = k+1;
        }
        jido[i][k+1] = t[k];
      }
    }


    dfs(sy, sx, 0);


  }
  return 0;
}
