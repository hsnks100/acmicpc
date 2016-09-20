#include <bits/stdc++.h>
using namespace std;

vector<int> graph[20001];


bool bfs(int v){
  queue<int> que;
  int coloring[20001];
  fill_n(coloring, 20001, -1);
  que.push(v);
  coloring[v] = 1;


  while(!que.empty()){
    int q = que.front();
    int startColor = coloring[q];
    que.pop();

    for(auto i : graph[q]){
      if(coloring[i] == -1){
        // 다른색 칠함 
        que.push(i);
        coloring[i] = !startColor;
      }
      else{
        if(startColor == coloring[i]){
          return false;
          // nokay
        }
        else{
          // ok, pass
        }
      }
    }
  }

  return true; 
}
int main(){
  int tc;

  cin >> tc;

  while(tc--){
    int v, e;
    cin >> v >> e;

    for(int i=1; i<=e; i++){
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a); 
    }

    bool bit = false;
    for(int i=1; i<=v; i++){
      if(bfs(i) == false){
        bit = false;
        break;
      }
      else{

      }
    }
    if(bit == false){
      printf("NO");
    }
    else{
      printf("YES");
    }
  }
  return 0;
}
