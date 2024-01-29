#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int>adj[1000000];
int visited[1000000];
int maxdist = 0;

void dfs(int v,int cont){
    visited[v] = 1;
    maxdist = max(maxdist,cont);

    for(int x : adj[v]){
        if(visited[x] != 1){
            dfs(x,cont+1);
        }
    }
}
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n ; i++){
        dfs(i,0);
        memset(visited,0,sizeof(visited));
    }
    
    cout << maxdist << endl; 
}
