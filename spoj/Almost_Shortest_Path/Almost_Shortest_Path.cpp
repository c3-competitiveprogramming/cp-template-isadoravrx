#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

void deleteConnections(vector<vector<pair<ll,ll> > >&adj, vector<ll>&temp){
    for(ll i = 0; i < temp.size() - 1; i++){
        for(ll j = 0; j < adj[temp[i]].size(); j++){
            if(adj[temp[i]][j].first == temp[i+1]){
                adj[temp[i]].erase(adj[temp[i]].begin() + j);
                break;
            }
        }
    }
}

void djk(vector<vector<pair<ll,ll> > >&adj , ll s, ll d, vector<ll>&dist, ll mnsize, int todelete){
    set<pair<pair<ll,ll>, vector<ll> > > st;
    vector<ll>temp;
    dist[s] = 0;
    temp.push_back(s);
    st.insert(make_pair(make_pair(0,s), temp));
    while(!st.empty()){
        ll no = (*st.begin()).first.second;
        ll custo = (*st.begin()).first.first;
        vector<ll>temp = (*st.begin()).second;

        st.erase(st.begin());
        if(no == d && custo == mnsize && todelete){
            deleteConnections(adj, temp);
        }

        for(auto it : adj[no]){
            if(custo + it.second <= dist[it.first]){
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
        djk(adj,s,d,dist,0, 0); //encontra o menor valor

        ll mnsize = dist[d];
        dist.assign(n+1,1e18); 
        djk(adj,s,d,dist,mnsize,1); //apaga os menores caminhos

        dist.assign(n+1,1e18);
        djk(adj,s,d,dist,0, 0); // encontra o almost shortest

        if(dist[d] == 1e18){
            cout << -1 << endl;
        }else{
            cout << dist[d] << endl;
        }
    }
}