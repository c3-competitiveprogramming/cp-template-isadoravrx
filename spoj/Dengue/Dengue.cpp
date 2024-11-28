#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int ans = 0;
int minmaxdist = 100;
int maxdistv = 0;

int visited[102];
vector<int>adj[102];

void dfs(int v, int cont){
    visited[v] = 1;
    maxdistv = max(maxdistv,cont);

    for(int x : adj[v]){
        if(visited[x] != 1){
            dfs(x,cont+1);
        }
    }
}


int main(){
    int n;
    int t = 1;
    int cont = 0;
    while(true){
        cin >> n;

        if(n == 0){
            break;
        }

        if(cont != 0){
            cout << endl;
        }
        
        memset(adj,0,sizeof(adj));
        minmaxdist = 100;
        for(int i = 0; i < n-1;i++){
            int a,b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i = 1; i <= n; i++){
            dfs(i,0); 
            if(maxdistv < minmaxdist){
                minmaxdist = maxdistv;
                ans = i;
            }
            maxdistv = 0;
            memset(visited,0,sizeof(visited));
        }
        
        cout << "Teste " << t << endl;
        cout << ans << endl;
        cont = 1;
        t++;
    }
}
