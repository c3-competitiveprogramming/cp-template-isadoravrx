#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int>adj[1000000];
int visited[1000000];
int maxdistv = 0;
int maxdistvvertice = 1;

void dfs(int v,int cont){
    visited[v] = 1;
    maxdist = max(maxdist,cont);

    for(int x : adj[v]){
        if(visited[x] != 1){
            dfs(x,cont+1);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(visited[maxdistvvertice] != 1){
        dfs(maxdistvvertice,0);
    }

    cout << maxdistv << endl; 
}
