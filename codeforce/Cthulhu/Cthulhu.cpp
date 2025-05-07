#include <iostream>
#include <vector>
using namespace std;

vector<int>adj[102];
int visited[102];

void dfs(int v){
    visited[v] = 1;

    for(int x : adj[v]){
        if(visited[x] == 1){
            continue;
        }
        dfs(x);
    }
}

int main(){
    int n, m;
    
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    dfs(1);
    bool b = true;
    for(int i = 1; i <= n;i++){
        if(visited[i] != 1){
            b = false;
            break;
        }
    }

    if(b && m == n){
        cout << "FHTAGN!" << endl;
        return 0;
    }
    cout << "NO" << endl;
    
}
