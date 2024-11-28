#include <iostream>
#include <vector>
#include <set>
#include <cstring>
typedef long long ll;
using namespace std;
ll n,m;
ll dist[1002];

void djk(vector<vector<pair<ll,ll> > >&adj, ll start){ 
    set<pair<ll,ll> >st;
    st.insert(make_pair(0,start));
    dist[start] = 0;

    while(!st.empty()){
        ll custo = (*st.begin()).first;
        ll no = (*st.begin()).second;
        
        st.erase(st.begin());
        for(auto it : adj[no]){
            if(it.second + custo < dist[it.first] || dist[it.first] == -1){
                dist[it.first] = it.second + custo;
                st.insert(make_pair(dist[it.first], it.first));
            }
        }
    }
}
int main(){

    cin >> n >> m;


    vector<vector<pair<ll,ll> > >adj(n+2);
    for(ll i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }

    memset(dist,-1, sizeof(dist));
    djk(adj, 0);

    cout << dist[n+1] << endl;
}