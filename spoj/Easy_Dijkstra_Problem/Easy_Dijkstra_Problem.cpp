#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

void djk(vector<vector<pair<int,int> > >&adj, int dist[],int start){
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

int main(){
    int t;
    cin >> t;

    while(t--){
        int v,k;
        cin >> v >> k;

        vector<vector<pair<int,int> > >adj(v+1);
        int dist[10002];
        memset(dist,-1,sizeof(dist));

        for(int i = 0; i < k; i++){
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
        }

        int ini, fim;
        cin >> ini >> fim;

        djk(adj,dist,ini);

        if(dist[fim] == -1){
            cout << "NO" << endl;
        }else{
            cout << dist[fim] << endl;
        }
    }

    return 0;
}