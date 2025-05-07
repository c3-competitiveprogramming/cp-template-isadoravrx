#include <iostream>
#include <algorithm>
using namespace std;
int mx = 0;
int v[1002][1002];
int visited[1002][1002];
int n,m;

void dfs(int x,int y,int cont){
    cont++;
    if(v[x][y] == 3){
        mx = max(mx,cont);
        return;
    }
    visited[x][y] = 1;

    if(x-1 >= 0 && visited[x-1][y] == 0 && v[x-1][y] != 0){
        dfs(x-1,y,cont);
    }if(x+1 < n && visited[x+1][y] == 0 && v[x+1][y] != 0){
        dfs(x+1,y,cont);
    }if(y-1 >=0 && visited[x][y-1] == 0 && v[x][y-1] != 0){
        dfs(x,y-1,cont);
    }if(y+1 < m && visited[x][y+1] == 0 && v[x][y +1] != 0){
        dfs(x,y+1,cont);
    }
}


int main(){
    cin >> n >> m;
    
    int x,y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            v[i][j] = num;

            if(num == 2){
                x = i; 
                y = j;
            }
        }
    }

    dfs(x,y,0);
    cout << mx << endl;    
    
}
