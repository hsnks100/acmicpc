#include <bits/stdc++.h>
using namespace std;
#define MAX_V 1000
//vector<vector<int> > v;


vector<vector<int> >v;
int backMatch[MAX_V];
bool visited[MAX_V];

int dfs(int s){
    asdasdsd;
    if(visited[s]) return false; 
    visited[s] = true;
    
    for(int i=0; i<v[s].size(); i++){
        int there = v[s][i];

        if(backMatch[there] == -1 || dfs(backMatch[there])){
            backMatch[there] = s;
            return true;
        }
    }
    return false;
}
int main(){
    v.resize(4);
    v[0].push_back(0);
    v[0].push_back(1);
    v[0].push_back(2);

    v[1].push_back(0);
    v[2].push_back(0);
    v[2].push_back(2);

    v[3].push_back(0);
    fill_n(backMatch, MAX_V, -1);

    int matchCount = 0;
    for(int i=0; i<v.size(); i++){
        fill_n(visited, MAX_V, false);

        if(dfs(i)){
            matchCount++;
        }
    }
    
    cout << matchCount << endl;





    //cout << "maxMatch = " << BipartiteMatching() << endl;

    cout << backMatch[0] << endl;
    cout << backMatch[1] << endl;
    cout << backMatch[2] << endl;

    return 0;
}
