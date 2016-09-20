#include <bits/stdc++.h>

using namespace std;
#define right first
#define down second
#define minTime first
#define useFuel second

const int _right = 0;
const int _bottom = 1;
pair<int, int> d[105][105][2]; // 최소 시간과 사용연료량
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int m, n, L, G;
        cin >> m >> n >> L >> G;

        // L 한칸당 걸리는 시간.
        // G 주어진 연료.


        fill_n(**d, 105*105*2, make_pair(numeric_limits<int>::max() - 10000, 0));

        int fuel[105][105][2];
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n-1; j++){
                int t;
                cin >> t;

                fuel[i][j][_right] = t; // .right = t;
                // 
            }

        }
        for(int i=1; i<=m-1; i++){
            for(int j=1; j<=n; j++){
                int t;
                cin >> t; 
                fuel[i][j][_bottom] = t;
                // 
            } 
        } 

        d[1][1][0] = make_pair(0, 0);
        d[1][1][1] = make_pair(0, 0);

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                for(int dir=0; dir<=1; dir++){
                    int di[] = {-1, -1, 0, 0};
                    int dj[] = {0, 0, -1, -1};
                    int ddir[] = {0, 1, 0, 1};
                    //cout << i << "," << j << endl;
                    for(int before=0; before<4; before++){
                        if(i+di[before] < 1 || j+dj[before] < 1){

                            continue;
                        }
                        int beforeY = i + di[before];
                        int beforeX = j + dj[before];
                        int beforeDir = ddir[before];
                        int dirChange = dir != beforeDir;
                        //if(d[i-di[before]][j-dj[before]][ddir[before]].minTime == numeric_limits<int>::max()){
                            //cout << "??" << " " << i+di[before] << "??" << j+dj[before] << endl;
                        //}
                        if(d[beforeY][beforeX][beforeDir].useFuel + fuel[beforeY][beforeY][dir] <= G){
                            //cout << d[beforeY][beforeX][beforeDir].minTime << endl;
                            if(d[i][j][dir].minTime > d[beforeY][beforeX][beforeDir].minTime + L + dirChange){
                                d[i][j][dir].minTime = min(d[i][j][dir].minTime, d[beforeY][beforeX][beforeDir].minTime + L + dirChange);
                                d[i][j][dir].useFuel = d[i+di[before]][j+dj[before]][ddir[before]].useFuel + fuel[i+di[before]][j+dj[before]][dir];
                            }
                        }
                        
                    }
                }
            }
        }

        cout << d[m][n][_right].minTime << endl;
        cout << d[m][n][_bottom].minTime << endl;


    }
    return 0;
}
