#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int visited[102];
bool b = true;

void dfs(vector<vector<int> >&adj, int no, int cont){
    visited[no] = cont;

    for(auto x : adj[no]){
        if(visited[x] == 0){
            dfs(adj,x,cont*-1);
        }else{
            if(visited[x] == visited[no]){
                b = false;
            }
        }
    }
}

int main(){
    int n,m;
    
    int t = 1;
    while(scanf("%d %d", &n,&m) == 2){

        b = true;
        memset(visited, 0 ,sizeof(visited));

        if(t !=1 ){
            printf("\n");
        }
        vector<vector<int> >adj(n+1);
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                dfs(adj,i,1);
            }
        }

        printf("Instancia %d\n", t);
        t++;
        if(b){
            printf("sim\n");
        }else{
            printf("nao\n");
        }
    }


}