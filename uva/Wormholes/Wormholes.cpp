#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool b = false;

void djk(vector<vector<pair<int,int> > >&adj, vector<int>&dist ,int start){
    set<pair<int,int> >st;
    st.insert(make_pair(0,start));
    dist[start] = 0;

    while(!st.empty()){
        int no = (*st.begin()).second;
        int cost = (*st.begin()).first;

        st.erase(st.begin());

        for(auto it : adj[no]){
            if(it.second + cost < dist[it.first] || dist[it.first] == -1){
                dist[it.first] = it.second + cost;
                st.insert(make_pair(dist[it.first],it.first));
            }
        }
    }
}

void dfs(vector<vector<pair<int,int> > >&adj,vector<int>&visited, vector<int>&dist, int no){
    visited[no] = 1;
 
    for(auto x : adj[no]){
        if(visited[x.first] != 0){
            if(dist[no] + x.second < dist[x.first]){
                b = true;
            }
        }else{
            dfs(adj, visited,dist, x.first);
        }
    }
    
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;
         
        b = false;
        vector<int>dist(n,-1);
        vector<vector<pair<int,int> > >adj(n);
        vector<vector<pair<int,int> > >adj_without_negatives(n);
        for(int i = 0; i < m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
            if(c < 0){
                adj_without_negatives[a].push_back(make_pair(b,0));
            }else{
                adj_without_negatives[a].push_back(make_pair(b,c));
            }
        }

        djk(adj_without_negatives, dist, 0);
        vector<int>visited(n);
        dfs(adj,visited, dist, 0);
        if(b){
            cout << "possible" << endl;
        }else{
            cout << "not possible" << endl;
        }
    }
}