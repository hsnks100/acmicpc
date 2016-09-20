#include <bits/stdc++.h>
using namespace std;


int d[501][501];

int D(int i, int j, int depth){
    for(int z=1; z<=depth; z++) cout << " ";
    cout << i << " " << j << endl;
    if(d[i][j] != 0){
        return d[i][j]; 
    }

    for(int a=i; a<=j-1; a++){
        if(d[i][j] == 0){
            d[i][j] = D(i, a, depth + 1) + D(a+1, j, depth + 1);
        }
        else{
            d[i][j] = min({d[i][j], D(i, a, depth + 1)*2 + D(a+1, j, depth + 1)*2}); // [i][a] + d[a+1][j]); 
        }
    }
    return d[i][j];
}
int main()
{
    int tc;
    cin >> tc;

    for(int _=1; _<=tc; _++){
        int n;
        cin >> n;
        vector<int> v(n+1);
        for(int i=1; i<=n; i++){
            int t;
            cin >> t; 
            v[i] = t; 
        }

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                d[i][j] = 0;
        //memset(d, -1, sizeof(d));

        for(int i=1; i<=n; i++){
            d[i][i] = v[i]; 
        } 
        for(int i=1; i<=n-1; i++){
            d[i][i+1] = v[i] + v[i+1];
        } 
        //cout << d[1][2] << endl;
        //cout << d[2][3] << endl;
        //cout << D(1, 2, 0) << endl;
        cout << D(1, n, 0) << endl;

    }

    return 0;
}
