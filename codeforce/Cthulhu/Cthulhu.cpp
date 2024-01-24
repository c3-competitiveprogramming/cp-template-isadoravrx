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

        visited[x] = 1;
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

   int cont = 0; 
   for(int i = 1; i <= n; i++){
        if(cont == 3){
            cout << "FHTAGN!" << endl;
            return 0;
        }
        if(!visited[i]){
            dfs(i);
            cont++;
        }
    }

    cout << "NO" << endl;
    
}
