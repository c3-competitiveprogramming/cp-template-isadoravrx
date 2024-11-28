#include <iostream>
#include <vector>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
ll maxmin = 0;

ll dfs(vector<vector<pair<ll, ll> > >&adj, vector<ll>visited, ll no, ll d, ll minpeso, map<pair<ll,ll>, ll>mp){
    if(mp.find(make_pair(no,d)) != mp.end()){
        return mp[make_pair(no,d)];
    }

    visited[no] = 1;
    if(no == d){
        maxmin = max(minpeso,maxmin);
        return minpeso;
    }

    ll mn = 10000000000;
    for(auto x : adj[no]){
        if(visited[x.first] == 0){
            ll result = dfs(adj,visited,x.first,d,min(minpeso,x.second), mp);
            if ( mn > result){
                mn = result;
            }
        }
    }

    mp[make_pair(no,d)] = mn;
    return mn;
}
int main(){
    ll n,m,s;

    while(cin >> n >> m >> s){
        vector<vector<pair<ll, ll> > >adj(n+1);
        for(ll i = 0; i < m ; i++){
            ll a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }

        map<pair<ll,ll>, ll>mp;
        for(ll i = 0; i < s; i++){
            ll s,d;
            vector<ll>visited(n+1);
            cin >> s >> d;
            maxmin = 0;
            dfs(adj, visited, s , d, 10000000000, mp);
            cout << maxmin << endl;
        }

    }
}