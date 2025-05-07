#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;

ll visited[30002];

void dfs(ll no,ll soma, vector<vector<pair<ll, ll> > > &adj){
    visited[no]=soma;

    for(auto x:adj[no]){
        if(visited[x.first]==-1){
            dfs(x.first, soma+x.second,adj);
        }
    }

}

int main(){

    ll t;
    scanf("%lld",&t);
    for(ll teste=1;teste<=t;teste++){
        ll n;
        scanf("%lld",&n);

        vector<vector<pair<ll, ll> > > adj(n+1);
        memset(visited,-1,sizeof(visited));

        for(ll i=0;i<n-1;i++){
            ll a,b,c;
            scanf("%lld %lld %lld",&a,&b,&c);
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }

        dfs(0,0,adj);

        ll distanteDoZero=0, distancia=0;
        for(ll i=0;i<n;i++){
            if(distancia<visited[i]){
                distancia=visited[i];
                distanteDoZero=i;
            }
        }

        memset(visited,-1,sizeof(visited));

        dfs(distanteDoZero,0,adj);

        ll maior=0;
        for(ll i=0;i<n;i++){
            if(maior<visited[i]){
                maior=visited[i];
            }
        }

        printf("Case %lld: %lld\n",teste,maior);
    }

    return 0;
}