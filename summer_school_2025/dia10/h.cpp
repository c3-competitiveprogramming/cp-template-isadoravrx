#include <iostream>
#include <vector>
using namespace std;
int quantidadenoconjunto = 1;

void dfs(int no, vector<vector<int> >&adj,  vector<int>&visited, int cont){
    visited[no] = cont;

    for(auto x : adj[no]){
        if(visited[x] == 0){
            quantidadenoconjunto++;
            dfs(x, adj, visited, cont);
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> >adj(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;  
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>visited(n+1);
    int compon = 0;
    vector<int>qporcompon;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            quantidadenoconjunto = 1;
            compon++;
            dfs(i,adj, visited, compon);
            qporcompon.push_back(quantidadenoconjunto);
        }
    }

    

}