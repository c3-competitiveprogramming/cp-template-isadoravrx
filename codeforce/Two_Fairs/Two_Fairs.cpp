#include <iostream>
#include <vector>
#include <map>
#include <deque>
typedef long long ll;
using namespace std;

ll a,b;

void dfs(vector<vector<ll> >&adj, vector<ll>&visited, vector<pair<ll,ll> >&p, ll cor, ll i, ll excluido){
    deque<int>dq;
    dq.push_front(i);
    visited[i] = 1;

    while(!dq.empty()){
        int no = dq[0];
        dq.pop_front();
       
        if(excluido == a){
            p[no].first = cor;
        }else{
            p[no].second = cor;            
        }

        for(int x : adj[no]){
            if(visited[x] == 0 && x != excluido){
                visited[x] = 1;
                dq.push_front(x);
            }
        }
    }
}

int main(){
    ll t;
    scanf("%lld", &t);

    while(t--){
        ll n,m;
        scanf("%lld %lld %lld %lld",&n,&m,&a,&b);

        vector<vector<ll> >adj(n+1);
        for(int i = 0; i < m; i++){
            ll x,y;
            scanf("%lld %lld",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<pair<ll,ll> >p(n+1);
        ll ans = ((n-2) * (n-2-1)) /2;
    
        ll cor = 1;
        vector<ll>visited(n+1);

        for(int i = 1; i <= n; i++){
            if(visited[i] == 0 && i != a && i != b){
                dfs(adj,visited,p,cor,i,a);
                cor++;
            }
        }

        cor = 1;
        visited.clear();
        visited.assign(n+1,0);

        for(int i = 1; i <= n; i++){
            if(visited[i] == 0 && i != a && i != b){
                dfs(adj,visited,p,cor,i, b);
                cor++;
            }
        }

        map<ll,ll>pp1;
        //quantidade de vertices em cada componente, quando tira a
        for(int i = 1; i <= n; i++){
            if(i != a && i != b){
                pp1[p[i].first]++;
            }
        }

        //quantidade de pares em cada componente
        for(auto it : pp1){
            ans -= (it.second * (it.second -1)) /2;
        }

        map<ll,ll>pp2;
        //quantidade de vertices em cada componente, quando tira b
        for(int i = 1; i <= n; i++){
            if(i != a && i != b){
                pp2[p[i].second]++;
            }
        }

        //quantidade de pares em cada componente
        for(auto it : pp2){
            ans -= (it.second * (it.second -1)) /2;
        }


        map<pair<ll,ll>,ll>pp_final;
        for(int i = 1; i <= n; i++){
            if(i != a && i != b){
                pp_final[p[i]]++; 
            }
        }

        for(auto it : pp_final){
           ans += (it.second * (it.second -1)) /2;
        }

        cout << ans << endl;
    }
}