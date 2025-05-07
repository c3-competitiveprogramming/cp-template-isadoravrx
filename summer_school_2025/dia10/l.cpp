#include <iostream>
#include <vector>
using namespace std;

void dfs(int no, vector<vector<int> >&adj, vector<int>&qfilhos,  vector<int>&visited ){
    visited[no] = 1;
    qfilhos[no] = 1;

    for(auto x : adj[no]){
        if(visited[x] == 0){
            dfs(x, adj,qfilhos, visited);
            qfilhos[no]+=qfilhos[x];
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int> >adj(n+1);

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nowithsizeone = 0;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1){
            nowithsizeone = i;
            break;
        }
    }


    vector<int>qfilhos(n+1);
    vector<int>visited(n+1);
    vector<int>pai;

    dfs(nowithsizeone,adj, qfilhos, visited);

    for(int i = 1; i <= n; i++){
        bool b = true;
        for(int j = 0; j < adj[i].size(); j++){
            if(qfilhos[adj[i][j]] < qfilhos[i] && qfilhos[adj[i][j]] > (n/2)){
                b = false;
                break;
            }
        }

        if(b){
            cout << i << endl;
            break;
        }
    }
}   