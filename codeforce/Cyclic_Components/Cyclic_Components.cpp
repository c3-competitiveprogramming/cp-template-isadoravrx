#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;
int component = 1;
int qnoscomponent = 0;

void dfs( vector<vector<int> >&adj, vector<int>&visited, int ini){
    deque<int>dq;
    dq.push_back(ini);

    while(!dq.empty()){
        int no = dq[0];
        dq.pop_front();
        visited[no] = component;
        qnoscomponent++;


        for(int x : adj[no]){
            if(visited[x] == 0){
                dq.push_front(x);
            }
        }
    }
}



int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> >adj(n+2);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>visited(n+2);
    map<int,bool>has_3moreNos;
    for(int i = 1; i <= n ; i++){
        if(visited[i] == 0){
            dfs(adj, visited, i);
            if(qnoscomponent > 2){
                has_3moreNos[component] = true;
            }else{
                has_3moreNos[component] = false;
            }
            component++;
            qnoscomponent = 0;
        }
    }

    vector<int>hasGrauTwo(component);
    for(int i = 1; i <= n; i++){
        if(adj[i].size() != 2){
            hasGrauTwo[visited[i]] = 1;
        }
    }

    int cont = 0;
    for(int i = 0; i < hasGrauTwo.size(); i++){
        if(hasGrauTwo[i] == 0 && has_3moreNos[i]){
            cont++;
        }
    }

    cout << cont << endl;
}