#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int>adj[1002];
bool visited[1002];
int cont = 0;

void dfs(int v){
    visited[v] = true;

    for(int x : adj[v]){
        if(visited[x]){
            continue;
        }
        dfs(x);
    }
}
int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i ++){
        if(!visited[i]){
            dfs(i);
            cont++;
        } 
    }
    cout << cont << endl;
}
