#include <iostream>
#include <vector>
using namespace std;
int visited[100002];
int cat[100002];
vector<int>adj[100002];
int n, m;
int cont = 0;

void dfs(int v,int c){
    visited[v] = 1;
    
    if(cat[v] == 1){
        c++;
    }else{
        c = 0;
    }
    
    if(c > m){
        return;
    }

    if(adj[v].size() == 0 && v !=1){
        cont++;
    }

    for(auto x : adj[v]){
        if(visited[x] != 1){
            dfs(x,c);
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        cat[i] = num;
    }

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1,0);
    cout << cont << endl;
}
