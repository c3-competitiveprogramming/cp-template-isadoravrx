#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int visited[100002];
int visited_cycle[100002];
bool hascycle = false;
int hastodelete = 0;


void detect_cycle(vector<vector<int> >&adj, int no, int pai){
    visited_cycle[no] = 1;

    for(int x : adj[no]){
        if(visited_cycle[x] == 0){
            detect_cycle(adj, x, no);
        }else{
            if(x != pai){
                hascycle = true;
                hastodelete++;
            }
        }
    }

}


void dfs( vector<vector<int> >&adj, int no, int cor){
    visited[no] = cor;

    for(int x : adj[no]){
        if(visited[x] == 0){
            dfs(adj, x, cor);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> >adj(n+1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool istree = true;

    
        
    int cor = 1;

    
    detect_cycle(adj, 1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(adj,1,cor);

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            detect_cycle(adj, i, 0);
            cor++;
            dfs(adj,i,cor);
            istree = false;
        }
    }

    if(hascycle){
        istree = false;
    }

    if(istree){
        cout << "BOM" << endl;
    }else{
        printf("RUIM %d %d\n",hastodelete/2, cor-1);
    }
}