#include <iostream>
#include <vector>
using namespace std;

void dfs( vector<vector<int> >&adj, vector<int>&visited, int no ){
    visited[no] = 1;

    for(auto x : adj[no]){
        if(visited[x] == 0){
            dfs(adj,visited,x);
        }
    }
}

int main(){
    int n,m;
    int t = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }
        if(t != 1){
            cout << endl;
        }
        
        vector<vector<int> >adj(n+1);
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int>visited(n+1);
        dfs(adj, visited, 1);
        bool b = true;
        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                b = false;
                break;
            }
        }

        printf("Teste %d\n", t);
        t++;

        if(b){
            cout << "normal" << endl;
        }else{
            cout << "falha" << endl;
        }
    }
}