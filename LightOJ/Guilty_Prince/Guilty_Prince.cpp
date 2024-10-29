#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int cont = 0;
int visited[22][22];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n,m;

bool pos_exist(int x,int y) {
    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }

    return false;
}

void dfs(int x, int y, vector<vector<char> >&v){
    visited[x][y] = 1;
    cont++;

    for(int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];

        if(visited[newx][newy] == 0 && pos_exist(newx,newy) && v[newx][newy] == '.'){
            dfs(newx,newy,v);
        }
    }
}

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        
        cin >> m >> n;

        vector<vector<char> >v(n, vector<char>(m));
        memset(visited, 0, sizeof(visited));
        int xarroba = 0;
        int yarroba = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                char c ; 
                cin >> c;
                v[i][j] = c;

                if(c == '@'){
                    xarroba = i;
                    yarroba = j;
                }            
            }   
        }

        dfs(xarroba, yarroba, v);

        printf("Case %d: %d\n", test, cont);
        cont = 0;
        test++;
    }
}