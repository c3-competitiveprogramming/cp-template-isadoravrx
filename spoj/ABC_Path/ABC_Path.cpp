#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int ans = 0;
int n,m;
int visited[52][52];
int dx[] = {1,0,-1,0,-1,1,-1,1};
int dy[] = {0,1,0,-1,-1,-1,1,1};

bool valide_position(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }

    return false;
}


void dfs(int x, int y, int cont, vector<vector<int> >&v){
    ans = max(ans,cont);
    visited[x][y] = 1;

    for(int i = 0; i < 8; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];

        if(valide_position(xi,yi) && visited[xi][yi] == 0 && v[xi][yi] == v[x][y] + 1){
            dfs(xi,yi,cont+1,v);
        }
    }
    
}


int main(){
   
    int t = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }

        vector<vector<int> >v(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;

                int num = c - 'A';
                v[i][j] = num;
            }
        }

        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 0){ // tem que comecar com um 'A'
                    memset(visited, 0, sizeof(visited));
                    dfs(i,j,1,v);
                }
            }
        }
        printf("Case %d: %d\n", t, ans);
        ans = 0;
        t++;
    }

}