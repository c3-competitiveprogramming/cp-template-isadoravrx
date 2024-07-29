#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
int dist[1000002];
int nodistante = 0 , distno= 0;

void dfs(vector<vector<int> > &adj, int start, int cont){
    deque<pair<int,int> >dq;
    dq.push_front(make_pair(start,cont));

    while(!dq.empty()){
        int no = dq.front().first;
        int cost = dq.front().second;

        dq.erase(dq.begin());
        for(auto x : adj[no]){
            if(dist[x] == -1){
                dist[x] = cost + 1;
                dq.push_front(make_pair(x,dist[x]));

                if(dist[x] > distno){
                    nodistante = x;
                    distno = dist[x];
                }
            }
        }
    }
   
}


int main(){
    int n;
    scanf("%d", &n);

    vector<vector<int> >adj(n+1);

    for(int i = 1; i <= n-1; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        dist[i] = -1;
    }
    
    dist[n] = -1;
    dfs(adj, 1, 0);

    memset(dist,-1,sizeof(dist));
    distno = 0;
    dfs(adj,nodistante , 0);

    printf("%d\n", distno);
}