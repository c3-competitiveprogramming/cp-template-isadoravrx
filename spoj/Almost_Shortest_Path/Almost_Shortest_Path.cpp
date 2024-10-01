#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

void deleteConnections(vector<vector<pair<ll,ll> > >&adj, vector<ll>temp){
    for(ll i = 0; i < temp.size() - 1; i++){
        for(ll j = 0; j < adj[i].size(); j++){
            if(adj[i][j].first == temp[i+1]){
                adj[i].erase(adj[i].begin() + j);
                break;
            }
        }
    }
}

void djk(vector<vector<pair<ll,ll> > >&adj , ll s, ll d, vector<ll>&dist, ll mnsize){
    set<pair<pair<ll,ll>, vector<ll> > > st;
    vector<ll>temp;
    dist[s] = 0;
    temp.push_back(s);
    st.insert(make_pair(make_pair(0,s), temp));
    while(!st.empty()){
        ll no = (*st.begin()).first.second;
        ll custo = (*st.begin()).first.second;
        vector<ll>temp = (*st.begin()).second;

        st.erase(st.begin());
        if(no == d && custo == mnsize){
            deleteConnections(adj, temp);
        }

        for(auto it : adj[no]){
            if(custo + it.second < dist[it.first]){
                dist[it.first] = custo + it.second;
                temp.push_back(it.first);
                st.insert(make_pair(make_pair(dist[it.first], it.first), temp));
                temp.pop_back();
            }
        }
    }
}

int main(){
    ll n,m;

    while(cin >> n >> m){   
        
        if(n == 0 && m == 0){
            break;
        }
        ll s,d;
        cin >> s >> d;

        vector<vector<pair<ll,ll> > >adj(n+1);
        for(ll i = 0; i < m; i++){
            ll a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
        }

        vector<ll>dist(n+1,1e18);
        djk(adj,s,d,dist,0);

        ll mnsize = dist[d];
        dist.assign(n+1,1e18);
        djk(adj,s,d,dist,mnsize);

        dist.assign(n+1,1e18);
        djk(adj,s,d,dist,0);

        if(dist[d] == 1e18){
            cout << -1 << endl;
        }else{
            cout << dist[d] << endl;
        }
    }
}