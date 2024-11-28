#include <iostream>
#include <vector>
#include <set>
#include <cstring>
typedef long long ll;
using namespace std;
ll dist[102];

void djk(vector<vector<pair<ll,ll> > >&adj, ll dist[], ll start){
    set<pair<ll,ll> >st;
    st.insert(make_pair(0,start));
    dist[start] = 0;

    while(!st.empty()){
        ll no  = (*st.begin()).second;
        ll cost =(*st.begin()).first;

        st.erase(st.begin());
        for(auto it : adj[no]){
            if(it.second + cost < dist[it.first]){
                dist[it.first] = it.second + cost;
                st.insert(make_pair(dist[it.first], it.first));
            }
        }
    }
}

int main(){
    ll n;
    ll exit;
    ll t;
    ll m;

    cin >> n >> exit >> t >> m;

    vector<vector<pair<ll,ll> > >adj(n+1);
    for(int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;

        adj[a].push_back(make_pair(b,c));
    }

    ll ans = 0;
    
    for(int i = 1; i <= n; i++){
        memset(dist,1000000,sizeof(dist));
        djk(adj,dist, i);
        if(dist[exit] <= t){
            ans++;  
        }
    }

    cout << ans << endl;
}   