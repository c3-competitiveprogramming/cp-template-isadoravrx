#include <iostream>
#include <vector>
using namespace  std;

int visited[102];
int color[102];
int fim;
void dfs(vector<vector<int> >&adj, int no, vector<int>v, int cor){
    visited[no] = 1;
    if(no == fim){
        for(int i = 0; i < v.size(); i++){
            color[v[i]] = cor;
        }
        return;
    }

    for(auto it : adj[no]){
        if(visited[it] == 0){
            v.push_back(it);
            dfs(adj,it,v,cor);
            v.pop_back();
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> >adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>v;
    for(int i = 0; i < m; i++){
        int ini,cor;
        cin >> ini >> fim >> cor;
        memset(visited,0, sizeof(visited));
        dfs(adj,ini,v, cor);
    }

    for(int i = 1; i <= n; i++){
        if(i != 1){
            cout << " ";
        }
        cout << color[i];
    }

    cout << endl;
}