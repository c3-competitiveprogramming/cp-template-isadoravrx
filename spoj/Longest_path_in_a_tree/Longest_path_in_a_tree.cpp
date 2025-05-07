#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
using namespace std;

void dfs(vector<int>adj[], int visited[], int dist[], int start){
    visited[start] = 1;
    deque<pair<int,int> >dq;
    dq.push_front(make_pair(start,0));

    while(!dq.empty()){
        int no = dq.front().first;
        int custo = dq.front().second;

        dq.pop_front();

        for(int x : adj[no]){
            if(visited[x] != 1){
                visited[x] = 1;
                dq.push_front(make_pair(x, custo+1));
                dist[x] = custo+1;
            }
        }
    }
    
}

int main(){
    int n;
    cin >> n;

    vector<int>adj[100000];
    int visited[100000];

    int dist[100000];

    int start;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        start = a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(adj,visited,dist, start);

    int nodist = 0, maxdist = 0;
    for(int i = 0; i < n; i++){
        if(maxdist < dist[i]){
            maxdist = dist[i];
            nodist = i;
        }
    }

    memset(dist, 0, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    dfs(adj,visited,dist, nodist);
    
    maxdist = 0;
    for(int i = 0; i < n+1; i++){
        maxdist = max(maxdist, dist[i]);
    }

    cout << maxdist << endl;
}
