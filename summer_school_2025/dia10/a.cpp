#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
set<pair<ll, ll> >maisdistantes; //valor, no
ll maiordist;

ll sum = 0;

void dfs(ll no,vector<vector<ll> >&adj, vector<ll>&visited, ll dist, vector<pair<ll,ll> >&values){
    if(dist == 0){
        visited[no] = 1;
    }else{
        visited[no] = dist;
    }
    if(maiordist==-1 || dist>maiordist){
        maisdistantes.clear();
        maisdistantes.insert(values[no]);
        maiordist=dist;
    }else if(dist==maiordist){
        maisdistantes.insert(values[no]);
    }


    for(auto x : adj[no]){
        if(visited[x] == 0){
            dfs(x, adj, visited, dist+1, values);
        }
    }
}   

void dfs2(ll no,vector<vector<ll> >&adj, vector<ll>&visited, ll dist, vector<pair<ll,ll> >&values){
    if(dist == 0){
        visited[no] = 1;
    }else{
        visited[no] = dist;
    }
    sum += dist * values[no].first;

    for(auto x : adj[no]){
        if(visited[x] == 0){
            dfs2(x, adj, visited, dist+1, values);
        }
    }
}


int main(){
    ll n;
    cin >> n;
    ll mx;
    vector<pair<ll,ll> >maiores; //{valor, no}

    vector<pair<ll,ll> >values(n+1);  //{valor, no}
    for(ll i = 1; i <= n; i++){
        ll a;
        cin >> a;
        values[i] = (make_pair(a,i));
        if(i==1 || a>mx){
            mx=a;
            maiores.clear();
            maiores.push_back(values[i]);
        }else if(a==mx){
            maiores.push_back(values[i]);
        }
    }

    vector<vector<ll> >adj(n+1);
    for(ll i = 0; i < n-1; i++){
        ll a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    maiordist=-1;
    for(ll i = 0; i < maiores.size(); i++) {
        vector<ll>visited(n+1);
        dfs(maiores[i].second, adj, visited, 0,values);
    }       

    ll bestsum = -1;
    for(auto it : maisdistantes){
        vector<ll>visited(n+1);
        sum = 0;
        dfs2(it.second, adj, visited, 0, values);
        bestsum = max(bestsum, sum);
    }

    cout << bestsum << endl;
    return 0;
}