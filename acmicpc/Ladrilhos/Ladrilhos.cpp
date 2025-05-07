#include <iostream>
#include <vector>
using namespace std;

int visited[205][205];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int cont = 0;
int n,m;


bool ok(int i , int j){
    if(i < n && i >= 0 && j < m && j >= 0){
        return true;
    }

    return false;
}

void dfs(int x, int y, vector<vector<int> >&v){
    visited[x][y] = 1;
    cont++;

    for(int i = 0; i < 4; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(ok(xi,yi) && visited[xi][yi] == 0 && v[xi][yi] == v[x][y]){
            dfs(xi,yi,v);
        }
    }
}

int main(){
    cin >> n >> m;

    vector<vector<int> >v(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    int minans = 1000000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0){
                cont = 0;
                dfs(i,j,v);
            }

            minans = min(minans, cont);
            
        }
    }

    cout << minans << endl;

}