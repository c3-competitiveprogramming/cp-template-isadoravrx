#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
typedef long long ll;
ll dist[20002];

void djk(ll start, vector<vector<pair<ll,ll> > >adj){
    set<pair<ll,ll> >st;
    st.insert(make_pair(0,start));
    dist[start] = 0;

    while(!st.empty()){
        ll no = (*st.begin()).second;
        ll cost = (*st.begin()).first;

        st.erase(st.begin());
        for(auto it : adj[no]){
            if(dist[it.first] == -1 || it.second + cost < dist[it.first]){
                dist[it.first] = it.second + cost;
                st.insert(make_pair(dist[it.first], it.first));
            }
        }
    }
}

int main(){
    ll t;
    cin >> t;
    ll test = 1;
    while(t--){
        ll n,m,o,d;
        cin >> n >> m >> o >> d;

        vector<vector<pair<ll,ll> > >adj(n+1);
        for(ll i = 0; i < m ; i++){
            ll a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }

        memset(dist, -1, sizeof(dist));
        djk(o,adj);
        if(dist[d] == -1){
            printf("Case #%lld: unreachable\n", test);
        }else{
            printf("Case #%lld: %lld\n", test, dist[d]);
        }

        test++;        
    }
}