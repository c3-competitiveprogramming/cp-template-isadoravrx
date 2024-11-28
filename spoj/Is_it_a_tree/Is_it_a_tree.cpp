#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int visited[10002];
bool hascycle = false;

void detect_cycle(vector<set<int> >&adj, int no, int pai){
    visited[no] = 1;

    for(int x : adj[no]){
        if(visited[x] == 0){
            detect_cycle(adj, x, no);
        }else{
            if(x != pai){
                hascycle = true;
            }
        }
    }

}


void dfs( vector<set<int> >&adj, int no){
    visited[no] = 1;

    for(int x : adj[no]){
        if(visited[x] == 0){
            dfs(adj, x);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<set<int> >adj(n+1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);
    }

    bool istree = true;

    //cycle
    detect_cycle(adj, 1, 0);
    if(hascycle){
        istree = false;
    }
    if(istree){
        //connected component
        memset(visited, 0, sizeof(visited));
        dfs(adj,1);
        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                istree = false;
                break;
            }
        }
    }

    if(istree){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}