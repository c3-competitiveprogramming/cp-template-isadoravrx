#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

int visited[1002];
int ans[1002];

void dfs(int no, vector<vector<int> > &adj,int moradores){
    visited[no]=1;
    ans[no]+=moradores;
    for(auto x:adj[no]){
        if(visited[x]==0){
            dfs(x,adj,moradores);
        }
    }
}

int main(){

    int t;
    cin>>t;
    for(int caso=1;caso<=t;caso++){
        memset(ans, 0, sizeof(ans));
        int p, n, m;
        cin>>p>>n>>m;

        map<int, int> home;
        for(int i=1;i<=p;i++){
            int num;
            cin>>num;
            home[num]++;
        }

        vector<vector<int> > adj(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }

        for(auto it:home){
            memset(visited, 0, sizeof(visited));
            dfs(it.first,adj,it.second);
        }


        int cont=0;
        for(int i=1;i<=n;i++){
            if(ans[i]==p){
                cont++;
            }
        }

        printf("Case %d: %d\n",caso, cont);
    }

    return 0;
}