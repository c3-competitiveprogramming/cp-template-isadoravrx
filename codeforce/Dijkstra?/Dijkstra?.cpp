#include <iostream>
#include <vector>
#include <cstring>
#include <set>
typedef long long ll;
using namespace std;
ll n,m;


void djk(vector<vector<pair<ll,ll> > >&adj, ll start,  vector<ll>&parents, vector<ll>&dist){
    set<pair<ll,ll> >st;
    st.insert(make_pair(0,start));
    dist[start] = 0;

    while(!st.empty()){
        ll no = (*st.begin()).second;
        ll cost = (*st.begin()).first;

        st.erase(st.begin());
        for(auto it : adj[no]){
            if(it.second + cost < dist[it.first]){
                dist[it.first] = it.second + cost;
                parents[it.first] = no;
                st.insert(make_pair(dist[it.first], it.first));
            }
        }
    }
}


int main(){
   
    scanf("%lld %lld", &n,&m);

    vector<vector<pair<ll,ll> > >adj(n+1);
    for(ll i = 0; i < m; i++){
        ll a,b,c;
        scanf("%lld %lld %lld", &a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
        
    }

    vector<ll>dist(n+1,1e18);
    vector<ll>parents(n+1);
    djk(adj,1, parents, dist);

    if(dist[n] == 1e18){
        printf("-1\n");
        return 0;
    }

    ll no = n;
    vector<ll>ans;
    while(no != 0){
        ans.push_back(no);
        no = parents[no];
    }

    for(ll i = ans.size() - 1; i >= 0; i--){
        if(i != ans.size()-1 ){
             printf(" ");
        }
        printf("%lld", ans[i]);
    }  

    printf("\n");

}